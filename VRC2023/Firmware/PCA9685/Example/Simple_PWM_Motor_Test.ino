// --- Khai báo thư viện ---
#include <Adafruit_PWMServoDriver.h>

// --- Khai báo biến giá trị xung ---
#define PWM_Pulse 4095                                      // 100% xung - chi tiết cách tính xung bên README.md

// --- Khai báo biến tần số ---
#define MOTOR_FREQ 50

// --- Khai báo các chân băm xung cho các kênh ---
#define MOTOR_CHANNEL_A1 8          
#define MOTOR_CHANNEL_A2 9
#define MOTOR_CHANNEL_B1 10
#define MOTOR_CHANNEL_B2 11
#define MOTOR_CHANNEL_C1 12
#define MOTOR_CHANNEL_C2 13
#define MOTOR_CHANNEL_D1 14
#define MOTOR_CHANNEL_D2 15

Adafruit_PWMServoDriver pwm = Adafruit_PWMServoDriver();   //  Địa chỉ I2C mặc định của PCA9685: 0x40

// --- Hàm khởi tạo, thiết lập, định nghĩa các tác vụ, biến ---
void setup()
{
    // --- Khởi tạo biến Serial (Chuẩn baud ESP32: 115200) ---
    Serial.begin(115200);

    // --- Khởi tạo I2C PWM ---
    pwm.begin();
    // --- Giới hạn hoạt động của chip PCA9685: 23MHz -> 27MHz ---
    pwm.setOscillatorFrequency(27000000);
    // --- Gán tần số (Chuẩn: 50Hz) ---
    pwm.setPWMFreq(MOTOR_FREQ);
    
}

// --- Hàm thực thi lệnh liên tục theo vòng tuần hoàn ---
void loop()
{
    // --- Các dòng lệnh để thử motor từng Channel (Uncomment line để sử dụng: Bôi đen và nhấn tổ hợp phím CTRL + /) ---
    
    // Băm xung ở Channel A1 với 100% tốc độ quay
    // pwm.setPWM(MOTOR_CHANNEL_A1, 0, PWM_Pulse);     // Uncomment ở đây để sử dụng

    // Băm xung ở Channel A2 với 100% tốc độ quay
    // pwm.setPWM(MOTOR_CHANNEL_A2, 0, PWM_Pulse);     // Uncomment ở đây để sử dụng

    // Băm xung ở Channel B1 với 100% tốc độ quay
    // pwm.setPWM(MOTOR_CHANNEL_B1, 0, PWM_Pulse);     // Uncomment ở đây để sử dụng

    // Băm xung ở Channel B2 với 100% tốc độ quay
    // pwm.setPWM(MOTOR_CHANNEL_B2, 0, PWM_Pulse);     // Uncomment ở đây để sử dụng

    // Băm xung ở Channel C1 với 100% tốc độ quay
    // pwm.setPWM(MOTOR_CHANNEL_C1, 0, PWM_Pulse);     // Uncomment ở đây để sử dụng

    // Băm xung ở Channel C2 với 100% tốc độ quay
    // pwm.setPWM(MOTOR_CHANNEL_C2, 0, PWM_Pulse);     // Uncomment ở đây để sử dụng

    // Băm xung ở Channel D1 với 100% tốc độ quay
    // pwm.setPWM(MOTOR_CHANNEL_D1, 0, PWM_Pulse);     // Uncomment ở đây để sử dụng

    // Băm xung ở Channel D2 với 100% tốc độ quay
    // pwm.setPWM(MOTOR_CHANNEL_D2, 0, PWM_Pulse);     // Uncomment ở đây để sử dụng

    // --- Độ trễ (tính theo ms)
    delay(10000);
}