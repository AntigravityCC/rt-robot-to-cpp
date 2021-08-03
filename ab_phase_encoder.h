#ifndef __AB_PHASE_ENCODER_H__
#define __AB_PHASE_ENCODER_H__

#include "encoder.h"

typedef struct ab_phase_encoder
{
    struct encoder  enc;
    char   *pin;
}ab_phase_encoder_t;

ab_phase_encoder_t *ab_phase_encoder_create(char* pin,int sample_time);

#endif // __AB_PHASE_ENCODER_H__

