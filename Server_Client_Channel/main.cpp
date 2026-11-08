#include "inc/client.h"
#include "inc/channel.h"
#include <iostream>

int main(void) {
    Server myServer;

    Client rpmClient(myServer, RPM);
    Client speedClient(myServer, Speed);

    myServer.write_channel(RPM, 3500);
    myServer.write_channel(Speed, 120);

    int rpmValue = rpmClient.read();
    int speedValue = speedClient.read();

    std::cout << "Client got RPM: " << rpmValue << "\n";
    std::cout << "Client got Speed: " << speedValue << "\n";

    return 0;
}