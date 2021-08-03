
#ifndef __MOTOR_H__
#define __MOTOR_H__

#include <stdio.h>
#include <stdbool.h>
#include <stdint.h>
#include <assert.h>

//#define  uint8_t  __uint8_t 

typedef struct motor
{
    bool(*set_speed)(void *mot, int thousands);
    bool (*destroy)(void *mot);
}motor_t;

motor_t  *motor_create(uint8_t size);
bool motor_destroy(motor_t *mot);
bool motor_run(motor_t *mot, int thousands);

#endif
