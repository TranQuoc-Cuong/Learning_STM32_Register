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
	
	while(1) {
	GPIO_write_pin(GPIO_C_BASE, GPIO_PIN_13, 1);
	TIM2_delay_ms(2000);	
	
	GPIO_write_pin(GPIO_C_BASE, GPIO_PIN_13, 0);	
	TIM2_delay_ms(2000);	
	}
}
