#include "dual_pwm_motor.hpp"
#include "stdio.h"

dual_pwm_motor::dual_pwm_motor()
{

}

dual_pwm_motor::~dual_pwm_motor()
{

}

bool dual_pwm_motor::set_speed(int thousands)
{
    if (thousands == 0)
    {
        //rt_pwm_set(mot_sub->pwm1_dev, mot_sub->pwm1_channel, MOTOR_PWM_PERIOD, 0);
    }

   printf("dual_pwm_motor_set_speed %d\n",thousands);
    return true;
}

bool dual_pwm_motor::motor_run(int thousands)
{
    set_speed(thousands);
    return true;
}
