#include "../inc/SPI.h"
#include <iostream>

SPI::SPI()= default;
SPI::~SPI() = default;
void SPI::send(int x)
{
    std::cout << x << " from SPI\n";
}
