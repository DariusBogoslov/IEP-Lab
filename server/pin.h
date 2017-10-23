#include<bcm2835.h>
#ifndef PIN_H
#define PIN_H
#define OUTPUT 1
#define INPUT 0
#define LED RPI_GPIO_P1_11
#define BUTTON RPI_GPIO_P1_10
 
 
class pin
{
public:
    pin(int numar,int direction);
    int numar;
    int direction;
    int pullUp;
    int state;
    int get();
    void set(int state);
    void setOutput();
    void setInput();
    void changeDirection();
    void setPullUp();
};
 
#endif // PIN_H
