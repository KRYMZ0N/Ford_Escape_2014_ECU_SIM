#pragma once
#include "pico/stdlib.h"
#include "hardware/pwm.h"

class HardwareIO {
private:
    uint redLedPin;
    uint greenLedPin;
    uint buzzerPin;
    uint buzzerSlice;

public:
    HardwareIO(uint redLed, uint greenLed, uint buzzer);

    void init();
    void triggerDTC();
    void normalOperation();
};