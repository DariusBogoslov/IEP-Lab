#include "../src/Pin.h";
#include "../bcm2835.h";

#define BCM_PIN_17 17
#define PIN BCM_PIN_17

int main() {
    Pin* pin = new Pin(BCM_PIN_17, OUTPUT);

    while(1) {
        pin->write(HIGH);
        pin->write(LOW);
    }

    delete pin;
    return 0;
}

