import pandas as pd
from sklearn.ensemble import RandomForestClassifier
import m2cgen as m2c

# 1. Train lại mô hình y hệt lúc nãy
def extract_features(df, label, window_size=35):
    features = []
    for i in range(0, len(df) - window_size, window_size // 2):
        window = df.iloc[i : i + window_size]
        features.append({
            'Z_Mean': window['Az'].mean(), 'Z_Std': window['Az'].std(),
            'Z_Max': window['Az'].max(), 'Z_Min': window['Az'].min(),
            'Z_Range': window['Az'].max() - window['Az'].min(), 'Label': label
        })
    return pd.DataFrame(features)

dataset = pd.concat([
    extract_features(pd.read_csv('dataset_normal.csv'), 0),
    extract_features(pd.read_csv('dataset_anomaly_type1.csv'), 1),
    extract_features(pd.read_csv('dataset_anomaly_type2.csv'), 2)
], ignore_index=True)

X = dataset.drop('Label', axis=1)
y = dataset['Label']
model = RandomForestClassifier(n_estimators=50, random_state=42)
model.fit(X, y)

# 2. XUẤT MÔ HÌNH RA CODE C
print("[*] Đang biên dịch mô hình sang C...")
c_code = m2c.export_to_c(model)

# 3. Ghi ra file thư viện .h
with open("ai_model.h", "w") as f:
    f.write("#ifndef AI_MODEL_H\n#define AI_MODEL_H\n\n")
    f.write(c_code)
    f.write("\n#endif\n")

print("[+] Thành công! Đã tạo ra file 'ai_model.h'. Hãy mang nó bỏ vào STM32CubeIDE!")