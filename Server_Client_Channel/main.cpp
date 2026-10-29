#include "channel.h"
#include "server.h"
#include "client.h"
#include <iostream>


int main(void){
    Server s;
    s.write_channel(Temp,1);
    s.write_channel(Temp,2);
    s.write_channel(Temp,3);
    s.write_channel(Temp,4);
    Client C1(s,Temp);
    int data = C1.read();
    std::cout << data;
    return 0;
}