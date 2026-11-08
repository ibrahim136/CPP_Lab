#ifndef _Eth_H_
#define _Eth_H_

#include "ICommBus.h"

class Eth: public ICommBus
{
    public:
    Eth();
    ~Eth();
    void send(int x);
};

#endif