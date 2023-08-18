--- Giải thích phương thức giao tiếp giữa PS3 và ESP32 ---
    • So với PS2 thì PS3 kết nối với ESP32 không cần qua RF, mà là qua Bluetooth (BLE).
    • Để kết nối với nhau, tay cầm và ESP32 phải trùng khớp địa chỉ MAC.

--- Hướng dẫn kết nối giữa PS3 và ESP32 ---
* Bước 1: Dùng dây Cab kết nối ESP32 với máy tính, điều chỉnh cổng PORT sao cho tương ứng với cổng COM. Chọn board là "ESP32 Dev Module".
* Bước 2: Mở file "PS3_MAC_Address_Scan.ino" trong thư mục "PS3_MAC_Address_Scan", nạp code vào ESP32.
* Bước 3: Mở màn hình Serial Monitor (Tools -> Serial Monitor), sau đó chỉnh baud là 115200.
* Bước 4: Copy địa chỉ MAC và lưu lại trong Notepad.
* Bước 5: Mở file "PS3_Button_Testing_Library.ino" trong thư mục "PS3_Button_Testing_Library", dán địa chỉ MAC vào dấu ngoặc kép của biến MAC_ADDRESS.
* Bước 6: Mở Serial Monitor (xem lại Bước 3) để xem trạng thái kết nối và tín hiệu.

*** Trường hợp nếu như không kết nối được ***
* Bước 1: Tải phần mềm "SixaxisPairTool" theo đường dẫn:
https://sixaxispairtool.en.lo4d.com/download
Sau đó giải nén ra.
* Bước 2: Sau đó dùng dây Cab kết nối tay cầm với máy tính, rồi mở phần mềm "SixaxisPairTool" rồi đợi 1-3p để cài đặt driver tay cầm cho máy tính.
* Bước 3: Cuối cùng dán địa chỉ MAC của ESP32 vào ô biểu mẫu của phần mềm, rồi nhấn "Update".