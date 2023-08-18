// --- BĂM XUNG BTS7960 BẰNG ESP32 (đơn giản - test motor) ---
// --- Khai báo các biến, các chân ---
#define PWM_Pulse_On 255       // Đây là 100% xung (bật) - Chi tiết cách tính xung bên phần README.md
#define PWM_Pulse_Off 0       // Đây là 0% xung (tắt) - Chi tiết cách tính xung bên phần README.md

#define BTS_CHANNEL_A 12    // Khai báo chân băm xung kênh A   
#define BTS_CHANNEL_B 13    // Khai báo chân băm xung kênh B

// --- Hàm khởi tạo, thiết lập, định nghĩa các tác vụ, biến ---
void setup()
{
    // --- Khởi tạo biến Serial (Chuẩn baud ESP32: 115200) ---
    Serial.begin(115200);
    
    // --- Định nghĩa chân - Chi tiết bên README.md
    pinMode(BTS_CHANNEL_A, OUTPUT);
    pinMode(BTS_CHANNEL_B, OUTPUT);
}

// --- Hàm thực thi lệnh liên tục theo vòng tuần hoàn
void loop()
{
    // --- Băm xung để bật / tắt Motor
    // Motor quay theo chiều A
    analogWrite(BTS_CHANNEL_A, PWM_Pulse_On);
    analogWrite(BTS_CHANNEL_B, PWM_Pulse_Off);          
    delay(5000);                                        // Độ trễ (tính theo ms)

    // Motor quay theo chiều B
    analogWrite(BTS_CHANNEL_A, PWM_Pulse_Off);
    analogWrite(BTS_CHANNEL_B, PWM_Pulse_On);
    delay(5000);                                        // Độ trễ (tính theo ms)
}