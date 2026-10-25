#include "ADC.h"

#include "TIM.h"

void ADC01_CH0_init(void)
{
	ADC01_SMPR2 &= ~(0x07UL << 0);
	ADC01_SMPR2 |= (0x07UL << 0);
	ADC01_SQR3 = 0;
	
	ADC01_CR2 |= (1UL << 1);
	ADC01_CR2 |= (1UL << 0); //ADON
	TIM2_delay_ms(1);
	ADC01_CR2 |= (1UL << 0);
	
	ADC01_CR2 |= (1UL << 3);
	while(((ADC01_CR2 & (1UL << 3)) != 0UL));
	
	ADC01_CR2 |= (1UL << 2);
	while(((ADC01_CR2 & (1UL << 2)) != 0UL)); 
	
	ADC01_CR2 |= (1 << 22);
}

uint16_t ADC01_CH0_read(void)
{
	while((ADC01_SR & (1UL << 1)) == 0UL);
	
	return (uint16_t)(ADC01_DR & 0xFFFF);
}
