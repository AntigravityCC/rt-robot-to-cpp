#ifndef __WHEEL_HPP__
#define __WHEEL_HPP__

#include "dual_pwm_motor.hpp"
#include "ab_phase_encoder.hpp"


class wheel : public dual_pwm_motor,public ab_phase_encoder
{
    public:
        wheel();
        ~wheel();
        int target;
        int measure;
        int output;

        bool set_target(int speed); 
        void controller_update(int target,int measure,int *output);
        void update();
        
};



#endif