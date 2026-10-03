#ifndef __EXTI_H
#define __EXTI_H

#include "TYPE.h"

#define NVIC_ISER0  (*(volatile uint32_t *)(0xE000E100UL))
#define NVIC_ISER1  (*(volatile uint32_t *)(0xE000E104UL))

typedef struct {
	__32BIT IMR;
	__32BIT EMR;
	__32BIT RTSR;
	__32BIT FTSR;
	__32BIT SWIER;
	__32BIT PR;
}EXTI_Typedef;

#define EXTI ((volatile EXTI_Typedef*)(0x40010400UL))
	
#define EXTI_RISING_MODE       0x00
#define EXTI_FALLING_MODE      0x01
#define EXTI_BOTH_MODE         0x02

void EXTI_init(uint32_t port, uint16_t gpio_pin, uint8_t type) ;
void EXTI0_IRQHandler(void);

#endif // __EXTI_H
