#include <Arduino.h>

typedef struct Motor
{
    uint8_t Channel_A;
    uint8_t Channel_B;
    
    uint8_t speed;
} Motor;

void motor_init(
                Motor *motor, 
                uint8_t Channel_1A,
                uint8_t Channel_1B,
                uint8_t Channel_2A,
                uint8_t Channel_2B,
                uint8_t Channel_3A,
                uint8_t Channel_3B,
                uint8_t Channel_4A,
                uint8_t Channel_4B
                );

void motor_setSpeed(Motor *motor, uint8_t motor_channel, int16_t speed);