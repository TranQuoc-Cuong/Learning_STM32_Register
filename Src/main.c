#include <stdio.h>
#include <stdint.h>

#include "RCC.h"

//GPIOA
#define GPIOA_BASE (0x40010800)
#define GPIOA_CRH (*(volatile uint32_t*)(GPIOA_BASE + 0x04))

//GPIOC
#define GPIOC_CRH (*(volatile uint32_t*)(0x40011000 + 0x04))
#define GPIOC_ODR (*(volatile uint32_t*)(0x40011000 + 0x0C))
 
void m_delay(volatile uint32_t time);
void m_delay(volatile uint32_t time) 
{
	while(time--);
}

int main() 
{
	RCC_Config_72MHz();
	RCC_enable_port_A();
	
	RCC_CFGR |= (1UL << 26);
	
	GPIOA_CRH |= (1UL << 0);
	GPIOA_CRH |= (1UL << 1);

	GPIOA_CRH &= ~(1UL << 2);
	GPIOA_CRH |= (1UL << 3);
	
	while(1) 
	{
	}
}
