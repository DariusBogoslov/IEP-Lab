#include "../src/Pin.h";
#include "../bcm2835.h";
#include <stdio.h>

#define BCM_PIN_17 17
#define PIN BCM_PIN_17

int main() {
    Pin* pin = new Pin(PIN, INPUT);
    pin->set_pud(PUD_UP);
    
    while(1) {
        uint8_t value = pin->read();
        printf("Read from pin %d: %d\n", PIN, value);
    }

    delete pin;
    return 0;
}