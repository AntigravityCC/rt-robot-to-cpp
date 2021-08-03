#ifndef  __DUAL_PWM_MOTOR_HPP__
#define  __DUAL_PWM_MOTOR_HPP__

#include "motor.hpp"


class dual_pwm_motor : public motor
{
    public:

        dual_pwm_motor();
        ~dual_pwm_motor();
        char *dev;
        bool set_speed(int thousands);
        bool motor_run(int thousands);
};



#endif