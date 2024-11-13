#include "motor.h"
#include <Adafruit_PWMServoDriver.h>

Adafruit_PWMServoDriver pwm = Adafruit_PWMServoDriver();

void motor_init(
                Motor *motor, 
                uint8_t Channel_A,
                uint8_t Channel_B
                )
{
    pwm.begin();
    pwm.setOscillatorFrequency(27000000);
    pwm.setPWMFreq(50);

    motor -> Channel_A = Channel_A;
    motor -> Channel_B = Channel_B;
}

void motor_setSpeed(Motor *motor, int16_t speed)
{
    motor -> speed = speed;
    if(motor -> speed > 0)
    {
        pwm.setPWM(motor -> Channel_A, 0, speed);
        pwm.setPWM(motor -> Channel_B, 0, 0);
    }
    else if(motor -> speed < 0)
    {
        pwm.setPWM(motor -> Channel_A, 0, 0);
        pwm.setPWM(motor -> Channel_B, 0, speed);
    }
    else
    {
        pwm.setPWM(motor -> Channel_A, 0, 0);
        pwm.setPWM(motor -> Channel_B, 0, 0);
    }
}