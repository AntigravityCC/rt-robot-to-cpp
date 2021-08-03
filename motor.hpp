#ifndef __MOTOR_HPP__
#define __MOTOR_HPP__

#include <iostream>

class motor
{
    public:  
        motor();  
        ~motor();
        virtual bool set_speed(int thousands) = 0;
        virtual bool motor_run(int thousands) = 0;
};


#endif 