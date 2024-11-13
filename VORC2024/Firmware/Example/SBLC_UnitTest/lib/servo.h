#include "Arduino.h"

typedef struct Servo{
    uint8_t Channel;

    float angle;
    float ppm;
} Servo;

void servo_init(Servo *servo, uint8_t Channel);

void servo_writeAngle(Servo *servo, float angle);