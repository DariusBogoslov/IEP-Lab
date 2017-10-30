#include "PWM.h"
#include <iostream>

using namespace std;

PWM::PWM(Pin* pin) {
    if (!bcm2835_init()) {
        cerr << "Failed to initialise BCM module";
        exit(EXIT_FAILURE);
    }
    bcm2835_gpio_fsel(pin->get_pin_number(), BCM2835_GPIO_FSEL_ALT5);
    bcm2835_pwm_set_clock(BCM2835_PWM_CLOCK_DIVIDER_16);
    bcm2835_pwm_set_mode(PWM_CHANNEL, 1, 1);
    this->frequency = -1;

};

PWM::~PWM() {
    bcm2835_close();
};

void PWM::set_data(uint32_t data) {
    if (this->frequency == -1) {
        cerr << "Must set frequency!";
        exit(EXIT_FAILURE);
    }
    bcm2835_pwm_set_data(PWM_CHANNEL, data);
    bcm2835_delay(1);
}

