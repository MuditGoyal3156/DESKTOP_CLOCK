/*
 * SYSTIC.h
 *
 *  Created on: 06-Jun-2026
 *      Author: mudit
 */

#ifndef SYSTIC_H_
#define SYSTIC_H_

#include <stdint.h>

#define SYSTICK_BASE	0xE000E010U
#define SYST_CSR		(*(volatile uint32_t*)(SYSTICK_BASE + 0x00U))
#define SYST_RVR		(*(volatile uint32_t*)(SYSTICK_BASE + 0x04U))
#define SYST_CVR		(*(volatile uint32_t*)(SYSTICK_BASE + 0x08U))
#define SYST_CALIB		(*(volatile uint32_t*)(SYSTICK_BASE + 0x0CU))

#define CLK_SRC			(1U << 2)
#define TICKINT_EN		(1U << 1)
#define COUNTER_EN		(1U << 0)

#define ONE_SEC_VALUE	16000000U
#define ONE_US_VALUE	16U

void one_sec_delay(void);
void uS_delay(int delay);
#endif /* SYSTIC_H_ */
