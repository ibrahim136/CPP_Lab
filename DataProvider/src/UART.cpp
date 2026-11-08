#include "../inc/UART.h"
#include <iostream>

UART::UART()= default;
UART::~UART() = default;
void UART::send(int x)
{
    std::cout << x << " from UART\n";
}
