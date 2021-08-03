#include "ab_phase_encoder.h"

static bool ab_phase_encoder_destroy(void *enc)
{
    ab_phase_encoder_t *enc_sub = (ab_phase_encoder_t*)enc;
    //rt_pin_detach_irq(enc_sub->pin_a);
    free(enc_sub);

    return true;
}

int ab_phase_encoder_read(void *enc)
{
    ab_phase_encoder_t *enc_sub = (ab_phase_encoder_t*)enc;
  
    enc_sub->enc.pulse_count += 10;

    return enc_sub->enc.pulse_count;
}

ab_phase_encoder_t *ab_phase_encoder_create(char* pin,int sample_time)
{
    // Malloc memory and initialize pulse_count and pin
    ab_phase_encoder_t *new_encoder = (ab_phase_encoder_t*)encoder_create(sizeof(struct ab_phase_encoder), sample_time);
    if(new_encoder == NULL)
    {
        return NULL;
    }
    
    new_encoder->pin = pin;

    new_encoder->enc.destroy = ab_phase_encoder_destroy;
    new_encoder->enc.read = ab_phase_encoder_read;
    return new_encoder;
}
