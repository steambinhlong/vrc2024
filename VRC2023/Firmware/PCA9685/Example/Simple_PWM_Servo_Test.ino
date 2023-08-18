// --- Khai báo thư viện ---
#include <Adafruit_PWMServoDriver.h>
#include <Wire.h>

// --- Khai báo, khởi tạo các biến ---
#define SERVOMIN  150   // Đây là số lượng độ dài xung 'tối thiểu' (trong số 4096 - hay 2^12)
#define SERVOMAX  600   // Đây là số xung 'tối đa' (trong số 4096 - hay 2^12)
#define USMIN  600      // Đây là độ dài micro giây 'tối thiểu' được làm tròn dựa trên xung tối thiểu là 150
#define USMAX  2400     // Đây là độ dài micro giây 'tối đa' được làm tròn dựa trên xung tối đa là 600
#define SERVO_FREQ 50   // Các động cơ servo tương tự chạy ở các bản cập nhật ~50 Hz

uint8_t servonum = 0;   // Biến dùng để đánh số thứ tự cho servo

void setup()
{
    // --- Khởi tạo biến Serial (Chuẩn baud ESP32: 115200) ---
    Serial.begin(115200);

    // --- Khởi tạo I2C PWM ---
    pwm.begin();
    // --- Giới hạn hoạt động của chip PCA9685: 23MHz -> 27MHz ---
    pwm.setOscillatorFrequency(27000000);
    // --- Gán tần số (Chuẩn: 50Hz) ---
    pwm.setPWMFreq(SERVO_FREQ);

    // --- In trạng thái nếu đã thực thi được các lệnh trên ---
    Serial.println("Chương trình test 8 kênh Servo");

    // --- Độ trễ (tính theo ms) ---
    delay(10);
}

// --- Hàm xác định tốc độ / chiều quay của Servo (không theo thời gian) ---
void servoSetPulseTesting()
{
    // Vòng lặp tăng dần xung -> Servo băm xung với giá trị tương ứng
    for (uint16_t pulselen = SERVOMIN; pulselen < SERVOMAX; pulselen++) {
        pwm.setPWM(servonum, 0, pulselen);      // Chi tiết cách tính xung bên README.md
    }

    // --- Độ trễ (tính theo ms) ---
    delay(500);

    // Vòng lặp giảm dần xung -> Servo băm xung với giá trị tương ứng
    for (uint16_t pulselen = SERVOMAX; pulselen > SERVOMIN; pulselen--) {
        pwm.setPWM(servonum, 0, pulselen);      // Chi tiết cách tính xung bên README.md
    }

    // --- Độ trễ (tính theo ms) ---
    delay(500);
}

// --- Hàm xác định chu kỳ quay của Servo (theo thời gian - đơn vị Us) ---
void servoWriteUsTesting()
{
    // Vòng lặp tăng dần thời gian (đơn vị Us) -> Servo băm xung theo thời gian tương ứng
    for (uint16_t microsec = USMIN; microsec < USMAX; microsec++) {
        pwm.writeMicroseconds(servonum, microsec);
    }

    // --- Độ trễ (tính theo ms) ---
    delay(500);

    // Vòng lặp giảm dần thời gian (đơn vị Us) -> Servo băm xung theo thời gian tương ứng
    for (uint16_t microsec = USMAX; microsec > USMIN; microsec--) {
        pwm.writeMicroseconds(servonum, microsec);
    }

    // --- Độ trễ (tính theo ms) ---
    delay(500);
}

void loop()
{
    // --- In số thứ tự của Servo ra màn hình ---
    Serial.println(servonum);
    // --- Hàm thử ---
    servoSetPulseTesting();
    servoWriteUsTesting();

    // --- Tăng 1 số thứ tự Servo sau khi đã thực thi các lệnh trên ---
    servonum++;
    // --- Giới hạn 8 Servo ----
    if(servonum > 7) servonum = 0;
}