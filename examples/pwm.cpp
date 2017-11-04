#include "../src/Pin.h"
#include "../bcm2835.h"
#include "../src/PWM.h"
#include <stdio.h>

#define BCM_PIN_17 17
#define PIN BCM_PIN_17
#define BCM_PIN_12 12

int main() {
    Pin* button_pin = new Pin(BCM_PIN_17, INPUT);
    button_pin->set_pud(PUD_UP);

    Pin* pwm_pin = new Pin(BCM_PIN_12, OUTPUT);
    PWM* pwm = new PWM(pwm_pin);

    uint8_t duty_cycle = 0;
    pwm->set_frequency(1000);
    pwm->set_duty_cycle(duty_cycle);

    while(1) {
        if (button_pin->read() == 0) {
            duty_cycle = (duty_cycle + 10) % 100;
            pwm->set_duty_cycle(duty_cycle);
        }
    }

    delete button_pin;
    delete pwm_pin;
    delete pwm;
    return 0;
}