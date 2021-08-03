#include "wheel.hpp"
//#include "stdio.h"


wheel::wheel()
{


}

wheel::~wheel()
{

    
}

bool wheel::set_target(int speed)
{
   target = speed;
   return true;
}


#define KP 1
void wheel::controller_update(int target,int measure,int *output)
{
    // do somethig to control
    int err = target - measure;
    *output = KP * err;
}

void wheel::update(void)
{
    measure = read();

    controller_update(target, measure,&output);
  
    motor_run(output);
}
