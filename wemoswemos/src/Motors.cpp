#include "Motors.h"

Motors::Motors(int pin1,int pin2)
{
    pinMode(pin1, OUTPUT);
    pinMode(pin2,OUTPUT);
    _pin1 = pin1;
    _pin2=pin2;
}
Motors::Motors(int pin)
{
    pinMode(pin,OUTPUT);
    _pin=pin;
}
void Motors::goone(int v)
{
    analogWrite(_pin,v);
}
void Motors::go(int v1,int v2)
{
    analogWrite(_pin1,v1);
    analogWrite(_pin2,v2);

}
