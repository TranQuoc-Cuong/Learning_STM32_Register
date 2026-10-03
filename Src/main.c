#include <stdio.h>
#include <stdint.h>

#include "RCC.h"
#include "GPIO.h"
#include "EXTI.h"

void m_delay(volatile uint32_t time);
void m_delay(volatile uint32_t time) {
	while(time--);
}

int main() 
{
	RCC_enable_port_A();
	RCC_enable_AFIO();
	
	GPIO_config(GPIO_A_BASE, GPIO_PIN_0, GPIO_MODE_INPUT_PU);
	EXTI_init(GPIO_A_BASE, GPIO_PIN_0, EXTI_FALLING_MODE);
	
	while(1) {
		
		m_delay(10);
	}
}
