#include "ab_phase_encoder.hpp"

ab_phase_encoder::ab_phase_encoder()
{

}

ab_phase_encoder::~ab_phase_encoder()
{
    
}

int ab_phase_encoder::read()
{
    this->pulse_count = (this->pulse_count >= ENCODE_TARGET ? ENCODE_TARGET : this->pulse_count + ENCODE_MEASURE_ADD);

    return this->pulse_count;
}
