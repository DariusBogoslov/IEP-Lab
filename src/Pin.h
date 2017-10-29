#include <stdint.h>
#include "bcm2835.h"

#define INPUT BCM2835_GPIO_FSEL_INPT
#define OUTPUT BCM2835_GPIO_FSEL_OUTP
#define PUD_UP BCM2835_GPIO_PUD_UP
#define PUD_DOWN BCM2835_GPIO_PUD_DOWN
#define PUD_OFF BCM2835_GPIO_PUD_OFF
#define HIGH 1u
#define LOW 0u

class Pin {
public:
    Pin(uint8_t pin_number, uint8_t direction);
    ~Pin();
    void set_direction(uint8_t direction);
    void set_pud(uint8_t mode);
    uint8_t read();
    void write(uint8_t value);

private:
    uint32_t pin_number;
    uint8_t direction;
    uint8_t pull_up;
};