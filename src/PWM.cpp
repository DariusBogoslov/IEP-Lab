#include "PWM.h"
#include <iostream>

using namespace std;

PWM::PWM(Pin* pin) {
    if (!bcm2835_init()) {
        cerr << "Failed to initialise BCM module";
        exit(EXIT_FAILURE);
    }
    bcm2835_gpio_fsel(pin->get_pin_number(), BCM2835_GPIO_FSEL_ALT5);
    validate_config(BCM2835_PWM_CLOCK_DIVIDER_16, 1);
    configure();
    bcm2835_pwm_set_range(PWM_CHANNEL, DEFAULT_RANGE);
    
    this->frequency = -1;

};

PWM::~PWM() {
    bcm2835_close();
};


void PWM::configure() {
    bcm2835_pwm_set_clock(this->clock_divider);
    bcm2835_pwm_set_mode(PWM_CHANNEL, this->markspace, 1);
}

void PWM::validate_config(uint32_t clock_divider, uint8_t markspace) {
    if (clock_divider != -1 && clock_divider) {
        this->clock_divider = clock_divider;
    }
    if (markspace == 1 || markspace == 0) {
        this->markspace = markspace;
    }

}

void PWM::set_frequency(uint32_t frequency) {
    this->frequency = frequency;
    this->update_range();
}

void PWM::update_range() {
    uint32_t range = CLOCK_FREQUENCY / this->frequency;
    bcm2835_pwm_set_range(PWM_CHANNEL, range);
}

void PWM::reconfigure(uint32_t clock_divider, uint8_t markspace) {
    this->validate_config(clock_divider, markspace);
    this->configure();
}

void PWM::set_duty_cycle(uint8_t duty_cycle) {
    if (this->frequency == -1) {
        cerr << "Must set frequency before using!";
        exit(EXIT_FAILURE);
    }
    if (duty_cycle < 0 || duty_cycle > 100) {
        cerr << "Duty cycle must be between 0-100!";
        exit(EXIT_FAILURE);
    }
    int32_t range = CLOCK_FREQUENCY / this->frequency;
    int32_t data = duty_cycle / 100 * range;
    bcm2835_pwm_set_data(PWM_CHANNEL, data);
    bcm2835_delay(1);
}
