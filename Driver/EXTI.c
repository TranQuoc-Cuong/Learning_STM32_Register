#include "EXTI.h"

#include "AFIO.h"
#include "GPIO.h"

static uint8_t get_pin_numer(uint16_t gpio_pin) 
{
	for(uint8_t i = 0; i < 16; i++) {
		if((gpio_pin & (1U << i)) != 0) {
			return i;
		}
	}
	return 0xFF;
}

void EXTI_init(uint32_t port, uint16_t gpio_pin, uint8_t type) 
{
	uint8_t port_code;
	
	if(GPIO_A_BASE == port) {
		port_code = 0;
	} else if(GPIO_B_BASE == port) {
		port_code = 1;
	} else if(GPIO_C_BASE == port) {
		port_code = 2;
	} else {
		return;
	}
	
	uint8_t pin = get_pin_numer(gpio_pin);
	uint32_t shift = (pin % 4) * 4;
	
	if(pin < 4) {
		AFIO_EXTICR1 &= ~(uint32_t)(0xF << shift);
		AFIO_EXTICR1 |= (uint32_t)(port_code << shift);
	} else if((pin >= 4) && (pin < 8)) {
		AFIO_EXTICR2 &= ~(uint32_t)(0xF << shift);
		AFIO_EXTICR2 |= (uint32_t)(port_code << shift);
	} else if((pin >= 8) && (pin < 12)) {
		AFIO_EXTICR3 &= ~(uint32_t)(0xF << shift);
		AFIO_EXTICR3 |= (uint32_t)(port_code << shift);
	} else {
		AFIO_EXTICR4 &= ~(uint32_t)(0xF << shift);
		AFIO_EXTICR4 |= (uint32_t)(port_code << shift);
	} 
	
	EXTI->IMR.REG |= (1UL << pin);
	
	switch(type) {
		case EXTI_RISING_MODE:
			EXTI->RTSR.REG |= (1UL << pin);
			EXTI->FTSR.REG &= ~(1UL << pin);
			break;
		
		case EXTI_FALLING_MODE:
			EXTI->RTSR.REG &= ~(1UL << pin);
			EXTI->FTSR.REG |= (1UL << pin);
			break;
		
		case EXTI_BOTH_MODE:
			EXTI->RTSR.REG |= (1UL << pin);
			EXTI->FTSR.REG |= (1UL << pin);
			break;
		
		default:
			break;
	}
	
	if(pin <= 4) {
		NVIC_ISER0 |= (1UL << (pin + 6));
	} else if(pin <= 9) {
		NVIC_ISER0 |= (1 << 23);
	} else if(pin <= 15) {
		NVIC_ISER1 |= (1UL << (40 - 32));
	}
}

void EXTI0_IRQHandler(void) 
{
	if (EXTI->PR.BITS.BIT0) {
		
		EXTI->PR.REG = (1UL << 0);
	}
}
