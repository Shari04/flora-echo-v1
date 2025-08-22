#ifndef SERVO_H
#define SERVO_H

#include "driver/ledc.h"
#include "esp_err.h"

class Servo {
private:
    int pin;
    ledc_channel_t channel;
    static const int freq = 50; // Hz
    static const int minPulse = 500;
    static const int maxPulse = 2400;

    uint32_t angleToDuty(int angle);

public:
    Servo(int gpioPin, ledc_channel_t ch);
    void begin();
    void setAngle(int angle);
};

#endif