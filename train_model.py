import pandas as pd
import numpy as np
from sklearn.model_selection import train_test_split
from sklearn.ensemble import RandomForestClassifier
from sklearn.metrics import accuracy_score, classification_report, confusion_matrix

# --- 1. HÀM TRÍCH XUẤT ĐẶC TRƯNG (FEATURE EXTRACTION) ---
def extract_features(df, label, window_size=35):
    """
    Cắt dữ liệu thành các 'cửa sổ' (ví dụ 35 mẫu ~ 2 giây).
    Tính toán các đặc trưng thống kê cho mỗi cửa sổ.
    """
    features = []
    # Trượt cửa sổ trên dữ liệu
    for i in range(0, len(df) - window_size, window_size // 2): # Độ trễ (Overlap) 50%
        window = df.iloc[i : i + window_size]
        
        # Tính các đặc trưng cho trục Z (có thể thêm X, Y nếu muốn)
        z_data = window['Az']
        
        feature_vector = {
            'Z_Mean': z_data.mean(),
            'Z_Std': z_data.std(),      # Độ lệch chuẩn (thể hiện mức độ rung)
            'Z_Max': z_data.max(),
            'Z_Min': z_data.min(),
            'Z_Range': z_data.max() - z_data.min(), # Biên độ dao động
            'Label': label              # Nhãn (0: Bình thường, 1: Rung, 2: Lắc)
        }
        features.append(feature_vector)
        
    return pd.DataFrame(features)

print("[*] Đang đọc dữ liệu và trích xuất đặc trưng...")

# --- 2. ĐỌC FILE VÀ GÁN NHÃN ---
# Chú ý: Đảm bảo tên file khớp với tên bạn đã lưu
df_normal = pd.read_csv('dataset_normal.csv')
df_type1 = pd.read_csv('dataset_anomaly_type1.csv')
df_type2 = pd.read_csv('dataset_anomaly_type2.csv')

# Label 0: Normal, Label 1: Rung bàn, Label 2: Lắc mạnh
feat_normal = extract_features(df_normal, label=0)
feat_type1 = extract_features(df_type1, label=1)
feat_type2 = extract_features(df_type2, label=2)

# Gộp tất cả lại thành một bộ Dataset hoàn chỉnh
dataset = pd.concat([feat_normal, feat_type1, feat_type2], ignore_index=True)

# Tách Đặc trưng (X) và Nhãn (y)
X = dataset.drop('Label', axis=1)
y = dataset['Label']

# --- 3. CHIA TẬP DỮ LIỆU ĐỂ HUẤN LUYỆN VÀ KIỂM TRA ---
# Lấy 80% dữ liệu để dạy (Train), 20% để làm bài kiểm tra (Test)
X_train, X_test, y_train, y_test = train_test_split(X, y, test_size=0.2, random_state=42)

print(f"[*] Kích thước tập huấn luyện: {len(X_train)} mẫu")
print(f"[*] Kích thước tập kiểm tra: {len(X_test)} mẫu")

# --- 4. HUẤN LUYỆN MÔ HÌNH (TRAIN) ---
print("[*] Đang huấn luyện mô hình Random Forest...")
model = RandomForestClassifier(n_estimators=50, random_state=42)
model.fit(X_train, y_train)

# --- 5. ĐÁNH GIÁ ĐỘ CHÍNH XÁC (EVALUATE) ---
y_pred = model.predict(X_test)
accuracy = accuracy_score(y_test, y_pred)

print("\n" + "="*40)
print(f"🎯 ĐỘ CHÍNH XÁC CỦA MÔ HÌNH: {accuracy * 100:.2f}%")
print("="*40)

print("\n📊 Báo cáo chi tiết:")
target_names = ['Bình thường', 'Rung bàn', 'Lắc mạnh']
print(classification_report(y_test, y_pred, target_names=target_names))

print("\nMa trận nhầm lẫn (Confusion Matrix):")
print(confusion_matrix(y_test, y_pred))