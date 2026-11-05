#include "UART.h"

#include "EXTI.h"
#include "GPIO.h"

void USART1_init(uint32_t baudrate)
{
	// PA9 TX
	GPIO_config(GPIO_A_BASE, GPIO_PIN_9, GPIO_MODE_AF_PP);
	// PA10 RX
	GPIO_config(GPIO_A_BASE, GPIO_PIN_10, GPIO_MODE_INPUT_FLOATING);
	
	USART1_BRR = 0x0341;
	
	USART1_CR1 |= (1UL << 13);
	USART1_CR1 |= (1UL << 3);
	USART1_CR1 |= (1UL << 2);
	
	USART1_CR1 |= (1UL << 5);
	
	NVIC_enable_USART01();
}

void USART1_send_char(char character)
{
	while((USART1_SR & (1UL << 7)) == 0UL) {
	}
	
	USART1_DR = character;
}

void USART1_send_string(const char* str)
{
	while(*str) {
		USART1_send_char(*str++);
	}
}

void USART1_IRQHandler(void)
{
	if ((USART1_SR & (1UL << 5)) != 0UL) {
		char c = (char)(USART1_DR & 0xFF);
		USART1_send_char(c);
	}
}
