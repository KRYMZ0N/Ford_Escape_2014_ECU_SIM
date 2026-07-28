#include <stdio.h>
#include "pico/stdlib.h"
#include "ThermalSim.h"
#include "HardwareIO.h"

int main() {
    HardwareIO ecuHardware(6, 2);
    ecuHardware.init();

    ThermalSim engineSim;

    while (true) {
        engineSim.update();

        if (engineSim.isCritical()) {
            ecuHardware.triggerDTC();
        } else {
            ecuHardware.normalOperation();
        }
    }

    return 0;
}