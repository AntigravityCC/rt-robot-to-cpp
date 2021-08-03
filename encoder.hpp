#ifndef __ENCODE_HPP__
#define __ENCODE_HPP__

#include <iostream>

class encoder
{
    public: 

        encoder(); 
        ~encoder();    
        int  sample_time;  
        int  pulse_count;  
        virtual int read() = 0;
};


#endif 
