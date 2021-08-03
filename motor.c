#include "motor.h"


motor_t *motor_create(uint8_t size)
{
    motor_t*new_motor = (motor_t*)malloc(size);
    if (new_motor == NULL)
    {
        printf("Falied to allocate memory for new motor\n");
        return NULL;
    }

    return new_motor;
}

bool motor_run(motor_t *mot, int thousands)
{
    assert(mot != NULL);

    mot->set_speed(mot, thousands);

    return true;
}

bool motor_destroy(motor_t *mot)
{
    assert(mot != NULL);
    
    printf("free motor");

    //mot->destroy(mot);
    free(mot);
    return true;
}
