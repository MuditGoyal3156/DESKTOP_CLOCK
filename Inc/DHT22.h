#ifndef DHT22_H_
#define DHT22_H_

#include <stdint.h>

#define RCC_BASE_ADDR		0x40023800U
#define AHB1ENR		(*(volatile uint32_t* )(RCC_BASE_ADDR + 0x30U))

#define GPIOA_BASE_ADDR		0x40020000U
#define GPIOA_MODER			(*(volatile uint32_t* )(GPIOA_BASE_ADDR + 0x00U))
#define GPIOA_IDR			(*(volatile uint32_t* )(GPIOA_BASE_ADDR + 0x10U))
#define GPIOA_ODR			(*(volatile uint32_t* )(GPIOA_BASE_ADDR + 0x14U))
#define GPIOA_PUPDR  (*(volatile uint32_t*)(GPIOA_BASE_ADDR + 0x0CU))

#define GPIOA_CLK_EN		(1U << 0)
#define PIN_10			(1U << 10)

typedef struct{
	uint16_t temperature;
	uint16_t humidity;
}DHT_DATA;

uint8_t DHT22_DATA(DHT_DATA *Data);
#endif
