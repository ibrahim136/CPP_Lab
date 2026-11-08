#ifndef _SPI_H_
#define _SPI_H_

#include "ICommBus.h"

class SPI: public ICommBus
{
    public:
    SPI();
    ~SPI();
    void send(int x);
};

#endif