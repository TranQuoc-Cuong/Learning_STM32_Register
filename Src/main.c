#include <stdio.h>
#include <stdint.h>

#include "RCC.h"
#include "GPIO.h"
#include "TIM.h"

void m_delay(volatile uint32_t time);
void m_delay(volatile uint32_t time) {
	while(time--);
}

volatile uint8_t blink_status = 0;

int main() 
{
	RCC_enable_port_C();
	RCC_enable_TIM2();
	
	GPIO_config(GPIO_C_BASE, GPIO_PIN_13, GPIO_MODE_OUTPUT_PP);
	TIM2_init_IT();
	while(1) {
		if (1 == blink_status) {
			GPIO_write_pin(GPIO_C_BASE, GPIO_PIN_13, 1);
		} else {
			GPIO_write_pin(GPIO_C_BASE, GPIO_PIN_13, 0);
		}

	}
}
