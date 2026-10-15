#include "TIM.h"

#include "EXTI.h"

extern volatile uint8_t blink_status; 

void TIM2_init_IT(void) 
{
  TIM2_PSC = 7999;
	
	TIM2_ARR = 999;
	
	TIM2_DIER |= (1UL << 0);
	TIM2_CR1 |= (1UL << 0);
	
	NVIC_ISER0 |= (1UL << 28);
}

void TIM2_IRQHandler(void) 
{
  if ((TIM2_SR & (1UL << 0)) == (1UL << 0)) {
      // doing something
			if (1 == blink_status) {
				blink_status = 0;
			} else {
				blink_status = 1;
			}
			
			TIM2_SR &= ~(1UL << 0);
  }
}

void TIM2_delay_ms(uint32_t time_ms) 
{
	TIM2_PSC = 7999;
	TIM2_ARR = time_ms;
	
	TIM2_CNT = 0;
	TIM2_CR1 |= (1UL << 0);
	
	while(TIM2_CNT < time_ms) {}
	
	TIM2_CR1 &= ~(1UL << 0);
	TIM2_CNT = 0;
}
