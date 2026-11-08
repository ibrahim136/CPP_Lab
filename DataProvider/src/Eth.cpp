#include "../inc/Eth.h"
#include <iostream>

Eth::Eth()= default;
Eth::~Eth() = default;
void Eth::send(int x)
{
    std::cout << x << " from Eth\n";
}
