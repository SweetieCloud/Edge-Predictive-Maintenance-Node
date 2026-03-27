import serial
import csv
import time

COM_PORT = 'COM8'     
BAUD_RATE = 115200
FILE_NAME = 'dataset_anomaly_type2.csv' # Tên file lưu dữ liệu

try:
    ser = serial.Serial(COM_PORT, BAUD_RATE, timeout=1)
    print(f"[*] Đã kết nối thành công với {COM_PORT}!")
    
    with open(FILE_NAME, mode='w', newline='') as file:
        writer = csv.writer(file)
        writer.writerow(['Timestamp', 'Ax', 'Ay', 'Az'])
        
        print(f"[*] Bắt đầu thu thập dữ liệu vào file '{FILE_NAME}'...")
        print("[!] NHẤN CTRL+C ĐỂ DỪNG THU THẬP VÀ LƯU FILE.")
        
        # Bỏ qua 5 dòng đầu tiên để lọc nhiễu lúc mới cắm điện
        for _ in range(5):
            ser.readline()
            
        while True:
            if ser.in_waiting > 0:
                # Đọc 1 dòng từ STM32, giải mã utf-8 và xóa ký tự thừa (\r\n)
                line = ser.readline().decode('utf-8').strip()
                current_time = time.time()
                
                # Tách 3 giá trị Ax, Ay, Az cách nhau bởi dấu phẩy
                data = line.split(',')
                
                # Đảm bảo đọc đủ 3 số mới ghi vào file (chống lỗi rớt gói tin)
                if len(data) == 3: 
                    writer.writerow([current_time] + data)
                    print(f"Đã lưu: {current_time:.3f} -> {line}")

except KeyboardInterrupt:
    print(f"\n[+] ĐÃ DỪNG THU THẬP! Dữ liệu lưu an toàn tại: {FILE_NAME}") #Ctrl + C
except Exception as e:
    print(f"\n[!] Có lỗi xảy ra: {e}")
finally:
    if 'ser' in locals() and ser.is_open:
        ser.close()
        print("[*] Đã đóng cổng Serial.")