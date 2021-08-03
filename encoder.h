#ifndef __ENCODER_H__
#define __ENCODER_H__

#include <stdio.h>
#include <stdbool.h>
#include <stdint.h>
#include <assert.h>

typedef struct encoder
{
    int  sample_time;  
    int  pulse_count;  
    bool (*destroy)(void *enc);
    int (*read)(void *enc);

}encoder_t;

encoder_t   *encoder_create(uint8_t size, uint8_t sample_time);
bool encoder_destroy(encoder_t *enc);
int encoder_read(encoder_t *enc);

#endif