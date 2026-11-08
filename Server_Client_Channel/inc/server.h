#ifndef _Server_H_
#define _Server_H_

#include "channel.h"

typedef enum{
    Speed,
    Temp,
    RPM,
    NUM_OF_TYPES
}Channel_ID_t;

class Server{
    private:
    Channel_RPM array[5];

    public:
    bool write_channel(Channel_ID_t Copy_enuChannelID, int data);
    Channel& bind(Channel_ID_t Copy_enuChannelID);

};

#endif