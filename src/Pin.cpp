#include "Pin.h"
#include <stdio.h>
#include <iostream>

using namespace std;

#define INPUT BCM2835_GPIO_FSEL_INPT
#define OUTPUT BCM2835_GPIO_FSEL_OUTP

Pin::Pin(uint8_t pin_number, uint8_t direction) {
    if (!bcm2835_init()) {
        cerr << "Failed to initialise BCM module";
        exit(EXIT_FAILURE);
    }
    this->pin_number = pin_number;
    this->pull_up = BCM2835_GPIO_PUD_OFF;
    this->direction = direction;
}

void Pin::set_direction(uint8_t direction) {
    bcm2835_gpio_fsel(this->pin_number, direction);
    this->direction = direction;
    this->pull_up = BCM2835_GPIO_PUD_OFF;
}

void Pin::set_pud(uint8_t mode) {
    bcm2835_gpio_set_pud(this->pin_number, mode);
    this->pull_up = mode;
}

uint8_t Pin::read() {
    uint8_t value = bcm2835_gpio_lev(this->pin_number);
    delay(500);
    return value;
}

void Pin::write(uint8_t value) {
    if (this->direction == OUTPUT) {
        bcm2835_gpio_write(this->pin_number, value);
        delay(500);
    } else {
        cerr << "Cannot write to INPUT Pin\n";
    }
}

