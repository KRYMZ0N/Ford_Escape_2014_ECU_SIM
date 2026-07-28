#include "HardwareIO.h"

HardwareIO::HardwareIO(uint led, uint buzzer) : ledPin(led), buzzerPin(buzzer) {}

void HardwareIO::init() {
    gpio_init(ledPin);
    gpio_set_dir(ledPin, GPIO_OUT);

    gpio_init(buzzerPin);
    gpio_set_dir(buzzerPin, GPIO_OUT);
}

void HardwareIO::triggerDTC() {

    for (int i = 0; i < 3; i++) {
        gpio_put(ledPin, 1);
        gpio_put(buzzerPin, 1);
        sleep_ms(150);

        gpio_put(ledPin, 0);
        gpio_put(buzzerPin, 0);
        sleep_ms(150);
    }

    sleep_ms(1000);
}

void HardwareIO::normalOperation() {
    // Keep hardware off, wait before next physics tick
    gpio_put(ledPin, 0);
    gpio_put(buzzerPin, 0);
    sleep_ms(250);
}