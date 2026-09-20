#include <stdio.h>
#include <stdint.h>

#include "RCC.h"

//GPIOC
#define GPIOC_CRH (*(volatile uint32_t*)(0x40011000 + 0x04))
#define GPIOC_ODR (*(volatile uint32_t*)(0x40011000 + 0x0C))
 
void m_delay(volatile uint32_t time);
void m_delay(volatile uint32_t time) {
	while(time--);
}

int main() {
	RCC_Config_72MHz();
	RCC_enable_port_A();
	
	// configure pin 13 port c
	GPIOC_CRH |= (1UL << 20);
	GPIOC_CRH |= (1UL << 21);
	
	GPIOC_CRH &= ~(1UL << 22);
	GPIOC_CRH &= ~(1UL << 23);
	
	GPIOC_ODR |= (1UL << 13);
	
	while(1) {
		GPIOC_ODR &= ~(1UL << 13);
		m_delay(10000000);
		GPIOC_ODR |= (1UL << 13);
		m_delay(10000000);
	}
}
