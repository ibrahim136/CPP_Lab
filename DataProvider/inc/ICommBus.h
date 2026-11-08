#ifndef _I_COMM_BUS_H_
#define _I_COMM_BUS_H_

class ICommBus{
    public:
    ICommBus();
    virtual ~ICommBus();
    virtual void send(int x) = 0;
};

#endif