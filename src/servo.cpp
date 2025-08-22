#include "Servo.h"
#include "driver/ledc.h"

// Constructor
Servo::Servo(int gpioPin, ledc_channel_t ch) : pin(gpioPin), channel(ch) {}

uint32_t Servo::angleToDuty(int angle) {
    int us = minPulse + (angle * (maxPulse - minPulse) / 180);
    return (us * 8191) / (1000000 / freq);
}

void Servo::begin() {
    static bool timerInit = false;

    if (!timerInit) {
        // Configuración del timer en el orden correcto
        ledc_timer_config_t timer_conf = {};
        timer_conf.speed_mode      = LEDC_LOW_SPEED_MODE;
        timer_conf.timer_num       = LEDC_TIMER_0;
        timer_conf.duty_resolution = LEDC_TIMER_13_BIT;
        timer_conf.freq_hz         = freq;
        timer_conf.clk_cfg         = LEDC_AUTO_CLK;

        ledc_timer_config(&timer_conf);
        timerInit = true;
    }

    // Configuración del canal en el orden correcto
    ledc_channel_config_t channel_conf = {};
    channel_conf.gpio_num   = pin;
    channel_conf.speed_mode = LEDC_LOW_SPEED_MODE;
    channel_conf.channel    = channel;
    channel_conf.timer_sel  = LEDC_TIMER_0;
    channel_conf.duty       = 0;
    channel_conf.hpoint     = 0;

    ledc_channel_config(&channel_conf);
}

void Servo::setAngle(int angle) {
    ledc_set_duty(LEDC_LOW_SPEED_MODE, channel, angleToDuty(angle));
    ledc_update_duty(LEDC_LOW_SPEED_MODE, channel);
}