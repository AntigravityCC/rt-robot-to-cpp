#include <iostream>
#include <unistd.h>
#include <signal.h>
#include <stdio.h>
#include "wheel.hpp"

using namespace std;


int main(int argc,char *argv[])
{
    wheel  *left_wheel = new wheel();
    wheel  *right_wheel = new wheel();
//  cout << "main begin\n" << endl;
    printf("main begin\n");
    while(1)
    {
        left_wheel->set_target(ENCODE_TARGET);
        right_wheel->set_target(ENCODE_TARGET*2);

        left_wheel->update();      
        right_wheel->update();

        printf("left %d   %d   %d\n",left_wheel->target,left_wheel->measure,left_wheel->output);
        //printf("right %d   %d   %d\n",right_wheel->target,right_wheel->measure,right_wheel->output);
        //motor *c_wheels = new wheel();
        usleep(100000);
    }

    while(1);
}
