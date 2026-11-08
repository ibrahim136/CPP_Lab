extern "C" {
#include "rcc.h"
#include "GPIO.h"
#include "HLED_cfg.h"
#include "HLED.h"
}

#include "client.h"
#include "server.h"
#include <variant>

int main(void) {
    RCC_enuCTRLPeripheral(Peripheral_GPIOA, Peripheral_Enable);
    RCC_enuCTRLPeripheral(Peripheral_GPIOB, Peripheral_Enable);

    HLED_enuInit();

    PIN_PORT_Conf_t PORTB_conf = {
        .PORT = GPIO_PORTB,
        .PIN_State = PIN_LOW,
        .PIN_Speed = Low_Speed,
        .PIN_PUPD = Pull_down,
        .PIN_Mode = Mode_Input,
        .PIN_Type = Push_Pull,
        .PIN_AF = AF0,
        .PIN = PIN0
    };
    GPIO_enuPinInit(&PORTB_conf);

    Server myServer;
    Client myClient(myServer, Speed);

    GPIO_PIN_State_t buttonState;
    int readValue;

    while (1) {
        GPIO_enuPinReadInput(GPIO_PORTB, PIN0, &buttonState);
        
        myServer.write_channel(Speed, (int)buttonState);
        ChannelData data = myClient.read();
        readValue = std::get<int>(data);

        if (readValue == PIN_HIGH) {
            HLED_enuTurnOn(PINA0);
        } else {
            HLED_enuTurnOff(PINA0);
        }
    }
    return 0;
}