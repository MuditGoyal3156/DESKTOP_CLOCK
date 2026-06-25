/*
 * DHT22.c
 *
 *  Created on: 21-Jun-2026
 *      Author: mudit
 */


#include "DHT22.h"
#include "SYSTIC.h"

/*
 * DATA -> PA10
 */
void DHT_GPIO_INIT(void){
	//Enable clock
	AHB1ENR |= GPIOA_CLK_EN;
}

void DHT_START(void){

	DHT_GPIO_INIT();

	//set output mode
	GPIOA_MODER |= (1U << 20);
	GPIOA_MODER &= ~(1U << 21);

	//Set output to LOW
	GPIOA_ODR &= ~(1U << 10);

	//Wait for >1ms
	uS_delay(1500);

	//Set output to high
	GPIOA_ODR |= (1U << 10);

	//Wait for 40uS
	uS_delay(40);

	//Set pins as input to read data
	GPIOA_MODER &= ~(3U << 20);

	// Enable PULL UP
	GPIOA_PUPDR &= ~(3U << 20);
	GPIOA_PUPDR |=  (1U << 20);
}

uint8_t DHT22_RESPONSE(void){
	uint16_t count;
	//Ideal line is high so wait for low
	count = 0;
	while((GPIOA_IDR & (1 << 10))){
		if(count++ > 1000){
			return 0;
		}
	}

	//Sensor send low voltage level for 80uS
	count = 0;
	while(!(GPIOA_IDR & (1 << 10))){
		if(count++ > 1000){
			return 0;
		}
	}
	//Sensor sends High voltage level for 80uS
	count = 0;
	while((GPIOA_IDR & (1 << 10))){
		if(count++ > 1000){
			return 0;
		}
	}

	return 1;
}
uint8_t read_data_byte(void)
{
	uint8_t data_byte,index=0;
	for(index =0;index < 8;index++){
		while(!(GPIOA_IDR & (1 << 10)));
		uS_delay(50);
		if(GPIOA_IDR & (1 << 10)){
			data_byte |= (1 << (7 - index)); //MSB is transmitted first
		}else{
			data_byte &= ~(1 << (7 - index));
		}
		while(GPIOA_IDR & (1<<10));
	}

	return data_byte;
}
uint8_t DHT22_DATA(DHT_DATA *Data){
	uint8_t bytes_receive[5]={0};
	DHT_START();

	if(!DHT22_RESPONSE()){
		return 0;
	}

	for(int i = 0;i<5;i++){
		bytes_receive[i] = read_data_byte();
	}

	uint8_t checksum = (bytes_receive[0] + bytes_receive[1] + bytes_receive[2] + bytes_receive[3]);
	if(checksum != bytes_receive[4]){
		return 0;
	}
	uint16_t RH =((uint16_t) bytes_receive[0] << 8)|bytes_receive[1];
	uint16_t temp =((uint16_t) bytes_receive[2] << 8)|bytes_receive[3];

	Data->humidity = RH;

    if(temp & 0x8000)
    {
        temp &= 0x7FFF;
        Data->temperature = -(temp);
    }
    else
    {
    	Data->temperature = temp;
    }
    return 1;
}
