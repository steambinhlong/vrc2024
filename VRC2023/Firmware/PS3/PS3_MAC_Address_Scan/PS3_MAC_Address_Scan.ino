// --- Khai báo thư viện theo từng trường hợp ---
// --- Trường hợp thiết bị ESP là ESP32 -> Khai báo thư viện WiFi.h ---
#ifdef ESP32
  #include <WiFi.h>
// --- Trường hợp thiết bị ESP là ESP8266 -> Khai báo thư viện ESP8266WiFi.h ---
#else
  #include <ESP8266WiFi.h>
#endif

// --- Hàm khởi tạo, thiết lập, định nghĩa các tác vụ, biến ---
void setup(){
  // --- Khởi tạo biến Serial (Chuẩn baud ESP32: 115200) ---
  Serial.begin(115200);
  // --- In để cách xuống 1 dòng ---
  Serial.println();
}

void loop(){
  // --- Địa chỉ MAC được in ra trên Màn hình Monitor ---
  Serial.print("Địa chỉ MAC trên thiết bị ESP:  ");
  Serial.println(WiFi.macAddress());
  // --- Độ trễ ---
  delay(2000);
}