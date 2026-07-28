#pragma once
#include "pico/stdlib.h"

class HardwareIO {
private:
    uint ledPin;
    uint buzzerPin;

public:
    HardwareIO(uint led, uint buzzer);

    void init();
    void triggerDTC();
    void normalOperation();
};