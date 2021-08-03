#ifndef  __AB_PHASE_ENCODER_HPP__
#define  __AB_PHASE_ENCODER_HPP__

#include "encoder.hpp"

#define ENCODE_TARGET 100
#define ENCODE_MEASURE_ADD 10


class ab_phase_encoder : public encoder
{
    public:
        ab_phase_encoder();
        ~ab_phase_encoder();

        char *dev;
        char *pin;       
        int  read();
};





#endif