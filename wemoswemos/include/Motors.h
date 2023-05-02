#ifndef Motors_h
#define Motors_h

#include "Arduino.h"

class Motors
{
  
   public: Motors(int pin1,int pin2);
   public: Motors(int pin);
    void go(int v1,int v2);
    void goone(int v);
    

  private:
   int _pin;
    int _pin1;
    int _pin2;
    int _v1;
    int _v2;
    int _v;


};

#endif
