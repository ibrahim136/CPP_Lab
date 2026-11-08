#include "server.h"

Server::Server() {
    array[Speed] = new Channel_Speed();
    array[Temp]  = new Channel_Temp();
    array[RPM]   = new Channel_RPM();
}

Server::~Server() {
    for (int i = 0; i < NUM_OF_TYPES; i++) {
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