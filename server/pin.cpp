#include "pin.h"
 
 
pin::pin(int numar,int direction)
{
    this->numar = numar;
    this->direction = direction;
    this ->state = 0;
    this ->pullUp = 0;
 
}
 
 
void pin::set(int state)
{
    if(this->direction == 1 && state == 0)
       {
        bcm2835_gpio_write(this -> numar, LOW);
        this ->state = 0;
        }
    else if(this->direction == 1 &&  state == 1)
         {
            bcm2835_gpio_write(this -> numar, HIGH);
            this ->state = 1;
        }
 
}
 
int pin::get()
{
    if(this -> direction == INPUT)
    return  bcm2835_gpio_lev(this->numar);
    else return -1;
}
 
void pin::changeDirection()
{
    if(this->direction == 0)
    {
        this ->direction = 1;
        this->setOutput();
    }
    else{
 
        this ->direction = 0;
        this->setInput();
    }
}
 
void pin::setOutput()
{
    bcm2835_gpio_fsel(this->numar, BCM2835_GPIO_FSEL_OUTP);
    this -> direction = OUTPUT;
}
 
void pin::setInput()
{
    bcm2835_gpio_fsel(this->numar, BCM2835_GPIO_FSEL_INPT);
    this -> direction = INPUT;
}
 
void pin::setPullUp()
{
    bcm2835_gpio_set_pud(this->numar, BCM2835_GPIO_PUD_UP);
    this->pullUp = 1;
}
