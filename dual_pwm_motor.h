
#ifndef __DUAL_PWM_MOTOR_H__
#define __DUAL_PWM_MOTOR_H__

#include "motor.h"

typedef struct dual_pwm_motor
{
    struct motor mot;
    char *dev;
}dual_pwm_motor_t;


dual_pwm_motor_t *dual_pwm_motor_create(char *pwm);

#endif