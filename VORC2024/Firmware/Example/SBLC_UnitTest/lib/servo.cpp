#include "servo.h"
#include <Adafruit_PWMServoDriver.h>
Adafruit_PWMServoDriver pwm = Adafruit_PWMServoDriver();

void servo_init(Servo *servo, uint8_t Channel)
{
    pwm.begin();
    pwm.setOscillatorFrequency(27000000);
    pwm.setPWMFreq(50);

    servo -> Channel = Channel;
}

void servo_writeAngle(Servo *servo, float angle)
{
    servo -> angle = angle;

    pwm.writeMicroseconds(servo -> Channel, map(angle, 0, 180, 500, 2300));
}