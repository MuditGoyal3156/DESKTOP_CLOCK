/*
 * RTC.h
 *
 *  Created on: 23-Jun-2026
 *      Author: mudit
 */

#ifndef RTC_H_
#define RTC_H_
#define STM32F446xx
#include "stm32f4xx.h"
#include <stdint.h>

typedef struct{
    uint8_t Date;
    uint8_t Month;
    uint8_t Year;
    uint8_t WeekDay;
}RTC_DATE;

typedef struct
{
    uint8_t Hours;
    uint8_t Minutes;
    uint8_t Seconds;
}RTC_TIME;

void RTC_INIT(void);
void INIT_DATE(void);
void INIT_TIME(void);
void GET_TIME(RTC_TIME *data);
void GET_DATE(RTC_DATE *data);
uint8_t DecimaltoBCD(uint8_t data);
uint8_t BCDtoDecimal(uint8_t data);
#endif /* RTC_H_ */
