#include "server.h"

Server::Server() {
    array[Speed] = new SpeedChannel();
    array[Temp]  = new TempChannel();
    array[RPM]   = new RPMChannel();
}

Server::~Server() {
    for(int i = 0; i < NUM_OF_TYPES; i++) {
        delete array[i];
    }
}

bool Server::write_channel(Channel_ID_t Copy_enuChannelID, int data) {
    if (Copy_enuChannelID >= NUM_OF_TYPES) {
        return false;
    }
    return array[Copy_enuChannelID]->write(data);
}

Channel& Server::bind(Channel_ID_t Copy_enuChannelID) {
    return *(array[Copy_enuChannelID]);
}