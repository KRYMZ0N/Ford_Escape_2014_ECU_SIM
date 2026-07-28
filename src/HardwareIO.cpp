#include "HardwareIO.h"

HardwareIO::HardwareIO(uint redLed, uint greenLed, uint buzzer) 
    : redLedPin(redLed), greenLedPin(greenLed), buzzerPin(buzzer) {}

void HardwareIO::init() {
    gpio_init(redLedPin);
    gpio_set_dir(redLedPin, GPIO_OUT);
    
    gpio_init(greenLedPin);
    gpio_set_dir(greenLedPin, GPIO_OUT);

    gpio_set_function(buzzerPin, GPIO_FUNC_PWM);
    buzzerSlice = pwm_gpio_to_slice_num(buzzerPin);
    
    pwm_set_clkdiv(buzzerSlice, 125.0f);
    pwm_set_enabled(buzzerSlice, true);
}

void HardwareIO::triggerDTC() {
    gpio_put(redLedPin, 1);
    gpio_put(greenLedPin, 0);

    // High-pitched 1000 Hz alarm
    uint hz = 1000;
    uint wrap = 1000000 / hz;
    pwm_set_wrap(buzzerSlice, wrap);

    for (int i = 0; i < 3; i++) {
        pwm_set_gpio_level(buzzerPin, wrap / 2); 
        gpio_put(redLedPin, 1);
        sleep_ms(150);
        
        pwm_set_gpio_level(buzzerPin, 0); 
        gpio_put(redLedPin, 0);
        sleep_ms(150);
    }

    sleep_ms(1000);
}

void HardwareIO::normalOperation() {
    // Healthy Engine: Green ON, Red OFF
    gpio_put(greenLedPin, 1);
    gpio_put(redLedPin, 0);
    
    // Low-frequency 50 Hz to simulate an idling engine block
    uint hz = 50; 
    uint wrap = 1000000 / hz;
    pwm_set_wrap(buzzerSlice, wrap);
    
    // Drive the buzzer to create the mechanical vibration
    pwm_set_gpio_level(buzzerPin, wrap / 2); 
    
    sleep_ms(250);
}