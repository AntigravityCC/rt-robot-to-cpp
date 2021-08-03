#ifndef __WHEEL_H__
#define __WHEEL_H__

#include "motor.h"
#include "encoder.h"

typedef struct wheel
{
    motor_t *w_motor;
    encoder_t   *w_encoder;
    int target;
    int measure;
    int output;
}wheel_t;

wheel_t *wheel_create(motor_t *w_motor, encoder_t *w_encoder);
bool wheel_destroy(wheel_t *whl);
void wheel_update(wheel_t *whl);
bool wheel_set_speed(wheel_t *whl, int speed);

#endif