#include "client.h"

Client::Client(Server &S, Channel_ID_t ID) {
    channel_ptr = &(S.bind(ID));
}

std::variant<int,float,double> Client::read() {
    return channel_ptr->read();
}