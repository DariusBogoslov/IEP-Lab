    #include "pin.h"
 
    int main(int argc, char *argv[])
    {
        pin *led = new pin(LED,OUTPUT);
        led->setOutput();
        pin *button = new pin(BUTTON,INPUT);
        button->setInput();
        button->setPullUp();
        uint8_t readValue = -1;
 
 
        while(1)
        {
            readValue = bcm2835_gpio_lev(button->numar);
            led->set(0);
            bcm2835_delay(500);
            led->set(1);
            bcm2835_delay(500);
 
        }
 
 
        bcm2835_close();
        return 0;
    }
