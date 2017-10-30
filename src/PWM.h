#include <stdint.h>
#include "bcm2835.h"
#include "Pin.h"

#define PWM_CHANNEL 0

class PWM {
public:
    PWM(Pin* pin);
    ~PWM();
    void set_frequency(uint8_t frequency);
    void set_duty_cycle(uint8_t duty_cycle);
    uint8_t get_frequency();
    uint8_t get_duty_cycle();
    void set_data(uint32_t data);

private:
    uint32_t frequency;
    uint8_t duty_cycle;
};