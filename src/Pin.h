#include <stdint.h>
#include "bcm2835.h"


class Pin {
public:
    Pin(uint8_t pin_number, uint8_t direction);
    void set_direction(uint8_t direction);
    void set_pud(uint8_t mode);
    uint8_t read();
    void write(uint8_t value);

private:
    uint32_t pin_number;
    uint8_t direction;
    uint8_t pull_up;
};