import serial
import pandas as pd
import numpy as np
from sklearn.ensemble import RandomForestClassifier
import warnings
warnings.filterwarnings("ignore") # Ẩn các cảnh báo cho màn hình gọn gàng

# --- 1. HUẤN LUYỆN LẠI MÔ HÌNH (Dùng code cũ cho nhanh) ---
print("[*] Đang khởi động AI và học lại dữ liệu...")
def extract_features(df, label, window_size=35):
    features = []
    for i in range(0, len(df) - window_size, window_size // 2):
        window = df.iloc[i : i + window_size]
        z_data = window['Az']
        features.append({
            'Z_Mean': z_data.mean(), 'Z_Std': z_data.std(),
            'Z_Max': z_data.max(), 'Z_Min': z_data.min(),
            'Z_Range': z_data.max() - z_data.min(), 'Label': label
        })
    return pd.DataFrame(features)

# Load data và train chớp nhoáng
df_normal = pd.read_csv('dataset_normal.csv')
df_type1 = pd.read_csv('dataset_anomaly_type1.csv')
df_type2 = pd.read_csv('dataset_anomaly_type2.csv')

dataset = pd.concat([
    extract_features(df_normal, 0),
    extract_features(df_type1, 1),
    extract_features(df_type2, 2)
], ignore_index=True)

X_train = dataset.drop('Label', axis=1)
y_train = dataset['Label']

model = RandomForestClassifier(n_estimators=50, random_state=42)
model.fit(X_train, y_train)
print("[+] AI ĐÃ SẴN SÀNG!\n" + "="*40)

# --- 2. LIVE INFERENCE TỪ CỔNG COM ---
COM_PORT = 'COM8' # Cập nhật đúng cổng COM của mạch CP2102
BAUD_RATE = 115200
WINDOW_SIZE = 35  # Tương đương ~0.7 giây dữ liệu (vì 1 giây được 50 mẫu)

LABELS = {
    0: "🟢 BÌNH THƯỜNG (Im lặng)",
    1: "🟡 CẢNH BÁO: RUNG NHẸ",
    2: "🔴 NGUY HIỂM: RUNG LẮC MẠNH!"
}

try:
    ser = serial.Serial(COM_PORT, BAUD_RATE, timeout=1)
    print(f"[*] Đã kết nối MPU6050 qua {COM_PORT}. Bắt đầu theo dõi...")
    
    # Bỏ qua vài dòng nhiễu ban đầu
    for _ in range(5): ser.readline()
        
    z_buffer = [] # Bộ đệm chứa các mẫu trục Z
    
    while True:
        if ser.in_waiting > 0:
            line = ser.readline().decode('utf-8').strip()
            data = line.split(',')
            
            if len(data) == 3:
                az = float(data[2])
                z_buffer.append(az)
                
                # Khi thu thập đủ 35 mẫu (Đầy 1 cửa sổ)
                if len(z_buffer) == WINDOW_SIZE:
                    # Chuyển thành Series để tính toán đặc trưng
                    z_series = pd.Series(z_buffer)
                    
                    # Rút trích 5 đặc trưng giống y hệt lúc Train
                    live_features = pd.DataFrame([{
                        'Z_Mean': z_series.mean(),
                        'Z_Std': z_series.std(),
                        'Z_Max': z_series.max(),
                        'Z_Min': z_series.min(),
                        'Z_Range': z_series.max() - z_series.min()
                    }])
                    
                    # Ném vào mô hình dự đoán
                    prediction = model.predict(live_features)[0]
                    
                    # In kết quả ra màn hình
                    print(f"Trạng thái hiện tại: {LABELS[prediction]}")
                    
                    # Xóa bộ đệm đi một nửa để tạo cửa sổ trượt (Sliding Window 50%)
                    # Việc này giúp AI phản ứng siêu nhanh, không bị độ trễ
                    z_buffer = z_buffer[WINDOW_SIZE // 2 :]

except KeyboardInterrupt:
    print("\n[+] ĐÃ DỪNG HỆ THỐNG.")
except Exception as e:
    print(f"\n[!] Lỗi: {e}")
finally:
    if 'ser' in locals() and ser.is_open:
        ser.close()