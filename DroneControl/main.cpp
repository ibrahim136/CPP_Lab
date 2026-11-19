#include "inc/system.h"

int main()
{
    DroneControlStation Drone;
    Drone.RegisterFeed(std::make_unique<LIDAR>());
    auto p = [&]() mutable{Drone.ActivateFeed();Drone.ViewFeed();Drone.DeactivateFeed();std::cout << std::endl;};
    p();
    Drone.RegisterFeed(std::make_unique<Camera>());
    p();
    Drone.RegisterFeed(std::make_unique<Mic>());
    p();
}