// --- BĂM XUNG BTS7960 BẰNG ESP32 (Gia tốc dần) ---
// --- Khai báo các biến, các chân ---
#define PWM_Pulse_On 255       // Đây là 100% xung (bật) - Chi tiết cách tính xung bên phần README.md
#define PWM_Pulse_Off 0       // Đây là 0% xung (tắt) - Chi tiết cách tính xung bên phần README.md

#define BTS_CHANNEL_A 12    // Khai báo chân băm xung kênh A   
#define BTS_CHANNEL_B 13    // Khai báo chân băm xung kênh B

int BTS_PWM_PULSE = 0;      // Khai báo biến giá trị xung PWM
// --- Hàm khởi tạo, thiết lập, định nghĩa các tác vụ, biến ---
void setup()
{
    // --- Khởi tạo biến Serial (Chuẩn baud ESP32: 115200) ---
    Serial.begin(115200);
    
    // --- Định nghĩa chân - Chi tiết bên README.md
    pinMode(BTS_CHANNEL_A, OUTPUT);
    pinMode(BTS_CHANNEL_B, OUTPUT);
}

// --- Hàm băm xung tăng dần
void riseUpPWM()
{
    // --- Nếu giá trị xung PWM hiện tại nhỏ hơn hoặc bằng 255 -> thực thi tác vụ
    if(BTS_PWM_PULSE <= PWM_Pulse_On)
    {
        // --- Tăng giá trị xung PWM đến khi đạt 100%
        BTS_PWM_PULSE++;
        delay(15)            // Độ trễ (tính theo ms)
    }
    delay(1000);             // Độ trễ (tính theo ms)
}

// --- Hàm băm xung giảm dần
void riseDownPWM()
{
    if(BTS_PWM_PULSE >= PWM_Pulse_On)
    {
        // --- Giảm giá trị xung PWM đến khi đạt 0%
        BTS_PWM_PULSE--;
        delay(15)            // Độ trễ (tính theo ms)
    }
    delay(1000);             // Độ trễ (tính theo ms)
}

// --- Hàm thực thi lệnh liên tục theo vòng tuần hoàn
void loop()
{
    riseUpPWM();
    riseDownPWM();
}