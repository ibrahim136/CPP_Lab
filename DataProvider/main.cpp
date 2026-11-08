#include "inc/DataProvider.h"
#include"inc/UART.h"
#include"inc/SPI.h"
#include"inc/Eth.h"

int main(void)
{
    DataProvider dp;
    UART UART;
    SPI SPI;
    Eth Eth;
    dp.register_(&UART);
    dp.register_(&SPI);
    dp.register_(&Eth);
    dp.BroadCast(5);
}