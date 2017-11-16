#include "Serial.h"
#include "bcm2835.h"

class Spi : public Serial {
public:
    Spi(uint8_t bit_order, uint8_t data_mode, uint16_t clock_divider, uint8_t chip_select, uint8_t active);
    ~Spi();
    uint8_t transfer(uint8_t data);

private:
    void validate_order(uint8_t bit_order);
    void validate_data_mode(uint8_t data_mode);
    void validate_clock_divider(uint16_t clock_divider);
    void validate_chip_select(uint8_t chip_select);
};