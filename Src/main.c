#include <stdio.h>
#include <stdint.h>
#include "SYSTIC.h"
#include "uart.h"
#include "DHT22.h"
#include "SPI.h"
#include "Display.h"
#include "OLED.h"
#include <string.h>
DHT_DATA sensor;

int main(void)
{
	uart2_tx_init();
    SPI1_GPIO_INIT();
    SPI_Master_INIT();
    Display_Init();
    SPI_DMA_INIT();

    while(1)
    {
        if(DHT22_DATA(&sensor))
        {
            printf("Temp = %d.%dC\r\n", (sensor.temperature/10),(sensor.temperature%10));
            printf("Humidity = %d.%d%%\r\n",(sensor.humidity/10),(sensor.humidity%10));


        }
        uS_delay(100000);
    }
}



