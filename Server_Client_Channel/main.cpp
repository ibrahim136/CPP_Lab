#include "server.h"
#include "client.h"
#include <iostream>


int main(void){
    Server s;
    s.write_channel(Temp,1);
    s.write_channel(Temp,2);
    s.write_channel(Temp,3);
    s.write_channel(Temp,4);
    s.write_channel(Temp,5);
    if (s.write_channel(Temp,6))
    {
        std::cout << "Writing 6 Succeeded\n\n";
    }
    else{
        std::cout << "Writing 6 Failed\n\n";
    }
    Client C1(s,Temp);
    int data = C1.read();
    std::cout << data<< std::endl;
    data = C1.read();
    std::cout << data << std::endl;
    data = C1.read();
    std::cout << data << std::endl;
    data = C1.read();
    std::cout << data << std::endl;
    data = C1.read();
    std::cout << data << std::endl;
    data = C1.read();
    std::cout << data << std::endl;
    data = C1.read();
    std::cout << data << std::endl;
    data = C1.read();
    std::cout << data << std::endl;
    data = C1.read();
    std::cout << data << std::endl;
    return 0;
}