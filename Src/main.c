#include <stdio.h>
#include <stdint.h>

#include "RCC.h"
#include "UART.h"
#include "TIM.h"

void m_delay(volatile uint32_t time);
void m_delay(volatile uint32_t time) {
	while(time--);
}

uint16_t value_adc = 0;

int main() 
{
	RCC_enable_port_A();
	RCC_enable_AFIO();
	RCC_enable_TIM2();
	RCC_enable_UART1();
	
	USART1_init(9600);
	
	while(1) {
		
		
		m_delay(100);
	}
}
