#include "wheel.h"

wheel_t *wheel_create(motor_t *w_motor, encoder_t *w_encoder)
{
    // 1. Malloc memory for wheel
    wheel_t *new_wheel = (wheel_t*)malloc(sizeof(struct wheel));
    if (new_wheel == NULL)
    {
        printf("Falied to allocate memory for new wheel");
        return NULL;
    }

    // 2. Initialize wheel
    new_wheel->w_motor = w_motor;
    new_wheel->w_encoder = w_encoder;
    
    return new_wheel;
}

bool wheel_destroy(wheel_t *whl)
{
    assert(whl != NULL);

    printf("Free wheel");

    motor_destroy(whl->w_motor);
    encoder_destroy(whl->w_encoder);

    free(whl);

    return true;
}

bool wheel_set_speed(wheel_t *whl, int speed)
{
    assert(whl != NULL);
    whl->target = speed;
    return true;
}

#define KP 1
void wheel_controller_update(int target,int measure,int *output)
{
    // do somethig to control
    int err = target - measure;
    *output = KP * err;
}

void wheel_update(wheel_t *whl)
{
    assert(whl != NULL);

    whl->measure = encoder_read(whl->w_encoder);

    wheel_controller_update(whl->target, whl->measure,&whl->output);
  
    motor_run(whl->w_motor, whl->output);
}

