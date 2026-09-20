#include "RCC.h"

void RCC_Config_72MHz(void) 
{
	RCC_CR |= (1UL << 16);
	
	while((0UL == (RCC_CR & (1UL << 17))))
	{
		// not thing to do
	};
	
	FLASH_ACR &= ~(1UL << 0);
	FLASH_ACR |= (1UL << 1);
	FLASH_ACR &= ~(1UL << 2);
	
	// pll mul: x9
	RCC_CFGR |= (1UL << 18);
	RCC_CFGR |= (1UL << 19);
	RCC_CFGR |= (1UL << 20);
	RCC_CFGR &= ~(1UL << 21);
	// pll mul: src 
	RCC_CFGR |= (1UL << 16);
	
	// pll mul: on
	RCC_CR |= (1UL << 24);
	while((RCC_CFGR & (3UL << 2)) != (2UL << 2))
	{
		// not thing to do
	};
	
	// APB1 / 2
	RCC_CFGR |= (1UL << 10);
	
	// PLL selected as system clock
	RCC_CFGR &= ~(1UL << 0);
	RCC_CFGR |= (1UL << 1);
	
	// wait status
	while (0UL == (RCC_CFGR & (2UL << 2))) 
	{
		// not thing to do
	}
}

void RCC_enable_port_A(void) 
{
	RCC_APB2ENR |= (1UL << 2);
}

void RCC_enable_port_B(void) 
{
	RCC_APB2ENR |= (1UL << 3);
}

void RCC_enable_port_C(void)
{
	RCC_APB2ENR |= (1UL << 4);
}
