#include "dual_pwm_motor.h"

static bool dual_pwm_motor_set_speed(void *mot, int thousands)
{
    dual_pwm_motor_t* mot_sub = (dual_pwm_motor_t*)mot;

    if (thousands == 0)
    {
        //rt_pwm_set(mot_sub->pwm1_dev, mot_sub->pwm1_channel, MOTOR_PWM_PERIOD, 0);
    }

    printf("dual_pwm_motor_set_speed %d\n",thousands);
    return true;
}

dual_pwm_motor_t *dual_pwm_motor_create(char *dev)
{
    dual_pwm_motor_t *new_motor = (dual_pwm_motor_t*)motor_create(sizeof(struct dual_pwm_motor));
    if (new_motor == NULL)
    {
        return NULL;
    }
    new_motor->dev = dev;
    new_motor->mot.set_speed = dual_pwm_motor_set_speed;
    return new_motor;
}




