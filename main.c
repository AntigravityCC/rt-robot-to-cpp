
#include "wheel.h"
#include "dual_pwm_motor.h"
#include "ab_phase_encoder.h"

int main(int argc,char *argv[])
{
    wheel_t* c_wheels = (wheel_t*)malloc(sizeof(wheel_t) * 2);
    if (c_wheels == NULL)
    {
        printf("Failed to malloc memory for wheels");
    }

    dual_pwm_motor_t *left_motor   = dual_pwm_motor_create(NULL);
    ab_phase_encoder_t *left_encoder  = ab_phase_encoder_create(NULL,0);
 
    c_wheels = wheel_create((motor_t*)left_motor,  (encoder_t*)left_encoder);
    
    while(1)
    {
        wheel_set_speed(c_wheels,100);
        wheel_update(c_wheels);

        printf("%d   %d   %d\n",c_wheels[0].target,c_wheels[0].measure,c_wheels[0].output);
        
        sleep(1);
    }
    return 0;
}
