#include "ThermalSim.h"

ThermalSim::ThermalSim() : exhaust_temp(200.0f), rpm(1000.0f), heat_shield_integrity(1.0f) {}

void ThermalSim::update() {

    rpm += 150.0f;
    if (rpm > 4000.0f) {
        rpm = 1500.0f;
    }

    // Thermodynamics
    float heat_generated = rpm * 0.015f;

    heat_shield_integrity -= 0.02f;
    if (heat_shield_integrity < 0.1f) {
        heat_shield_integrity = 0.1f;
    }

    float heat_dissipated = 20.0f * heat_shield_integrity;

    exhaust_temp = exhaust_temp + heat_generated - heat_dissipated;
}

bool ThermalSim::isCritical() const {
    return exhaust_temp >= CRITICAL_TEMP;
}