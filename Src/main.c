#include <stdio.h>
#include <stdint.h>

#include "RCC.h"
#include "GPIO.h"

void m_delay(volatile uint32_t time);
void m_delay(volatile uint32_t time) 
{
	while(time--);
}

int main() 
{
	RCC_enable_port_B();
	
	GPIO_config(GPIO_B_BASE, GPIO_PIN_5, GPIO_MODE_OUTPUT_PP);
	
	while(1) {
		GPIO_write_pin(GPIO_B_BASE, GPIO_PIN_5, 0);
		m_delay(500000);
		GPIO_write_pin(GPIO_B_BASE, GPIO_PIN_5, 1);
		m_delay(500000);
	}
}
