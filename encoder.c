 #include "encoder.h"

encoder_t *encoder_create(uint8_t size, uint8_t sample_time)
{
    // Malloc memory and initialize
    encoder_t *new_encoder = (encoder_t*)malloc(size);
    if(new_encoder == NULL)
    {
        printf("Failed to malloc memory for new encoder\n");
        return NULL;
    }

    new_encoder->sample_time = 0;

    return new_encoder;
}

int encoder_read(encoder_t *enc)
{
    assert(enc != NULL);

    return enc->read(enc);
}

bool encoder_destroy(encoder_t *enc)
{
    printf("Free Encoder");
    assert(enc != NULL);

    return enc->destroy(enc);
}
