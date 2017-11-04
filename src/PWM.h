#include <stdint.h>
#include "bcm2835.h"
#include "Pin.h"

#define PWM_CHANNEL 0
#define CLOCK_FREQUENCY 1200000
#define DEFAULT_RANGE 1024

class PWM {
public:
    PWM(Pin* pin);
    ~PWM();
    void set_frequency(uint32_t frequency);
    void set_duty_cycle(uint8_t duty_cycle);
    void reconfigure(uint32_t clock_divider, uint8_t markspace);
    
private:
    void update_range();
    void configure();
    void validate_config(uint32_t clock_divider, uint8_t markspace);
    uint32_t frequency;
    uint32_t clock_divider;
    uint8_t duty_cycle;
    uint8_t markspace;
};