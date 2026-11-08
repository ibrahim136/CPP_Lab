#ifndef _UART_H_
#define _UART_H_

#include "ICommBus.h"

class UART: public ICommBus
{
    public:
    UART() = default;
    ~UART() = default;
    void send(int x);
};

#endif