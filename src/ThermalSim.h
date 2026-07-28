#pragma once

class ThermalSim {
private:
    float exhaust_temp;
    float rpm;
    float heat_shield_integrity;
    
    static constexpr float CRITICAL_TEMP = 850.0f;

public:
    ThermalSim();

    void update();

    bool isCritical() const;
};