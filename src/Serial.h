#include <stdint.h>

class Serial {
public:
    virtual uint8_t transfer(uint8_t data) = 0; 
};