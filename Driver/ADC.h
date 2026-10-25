#ifndef __ADC_H
#define __ADC_H

#include <stdint.h>

#define ADC01_BASE_ADDRESS (0x40012400UL)
#define ADC02_BASE_ADDRESS (0x40012800UL)

#define ADC_SR_BASE    0x00
#define ADC_CR1_BASE   0x04
#define ADC_CR2_BASE   0x08
#define ADC_SMPR1_BASE 0x0C
#define ADC_SMPR2_BASE 0x10
#define ADC_JOFR1_BASE 0x14
#define ADC_JOFR2_BASE 0x18
#define ADC_JOFR3_BASE 0x1C
#define ADC_JOFR4_BASE 0x20
#define ADC_HTR_BASE   0x24
#define ADC_LTR_BASE   0x28
#define ADC_SQR1_BASE  0x2C
#define ADC_SQR2_BASE  0x30
#define ADC_SQR3_BASE  0x34
#define ADC_JSQR_BASE  0x38
#define ADC_JDR1_BASE  0x3C
#define ADC_JDR2_BASE  0x40
#define ADC_JDR3_BASE  0x44
#define ADC_JDR4_BASE  0x48
#define ADC_DR_BASE    0x4C

// --- ADC01 ---
#define ADC01_SR    (*(volatile uint32_t*)(ADC01_BASE_ADDRESS + ADC_SR_BASE))
#define ADC01_CR1   (*(volatile uint32_t*)(ADC01_BASE_ADDRESS + ADC_CR1_BASE))
#define ADC01_CR2   (*(volatile uint32_t*)(ADC01_BASE_ADDRESS + ADC_CR2_BASE))
#define ADC01_SMPR1 (*(volatile uint32_t*)(ADC01_BASE_ADDRESS + ADC_SMPR1_BASE))
#define ADC01_SMPR2 (*(volatile uint32_t*)(ADC01_BASE_ADDRESS + ADC_SMPR2_BASE))
#define ADC01_JOFR1 (*(volatile uint32_t*)(ADC01_BASE_ADDRESS + ADC_JOFR1_BASE))
#define ADC01_JOFR2 (*(volatile uint32_t*)(ADC01_BASE_ADDRESS + ADC_JOFR2_BASE))
#define ADC01_JOFR3 (*(volatile uint32_t*)(ADC01_BASE_ADDRESS + ADC_JOFR3_BASE))
#define ADC01_JOFR4 (*(volatile uint32_t*)(ADC01_BASE_ADDRESS + ADC_JOFR4_BASE))
#define ADC01_HTR   (*(volatile uint32_t*)(ADC01_BASE_ADDRESS + ADC_HTR_BASE))
#define ADC01_LTR   (*(volatile uint32_t*)(ADC01_BASE_ADDRESS + ADC_LTR_BASE))
#define ADC01_SQR1  (*(volatile uint32_t*)(ADC01_BASE_ADDRESS + ADC_SQR1_BASE))
#define ADC01_SQR2  (*(volatile uint32_t*)(ADC01_BASE_ADDRESS + ADC_SQR2_BASE))
#define ADC01_SQR3  (*(volatile uint32_t*)(ADC01_BASE_ADDRESS + ADC_SQR3_BASE))
#define ADC01_JSQR  (*(volatile uint32_t*)(ADC01_BASE_ADDRESS + ADC_JSQR_BASE))
#define ADC01_JDR1  (*(volatile uint32_t*)(ADC01_BASE_ADDRESS + ADC_JDR1_BASE))
#define ADC01_JDR2  (*(volatile uint32_t*)(ADC01_BASE_ADDRESS + ADC_JDR2_BASE))
#define ADC01_JDR3  (*(volatile uint32_t*)(ADC01_BASE_ADDRESS + ADC_JDR3_BASE))
#define ADC01_JDR4  (*(volatile uint32_t*)(ADC01_BASE_ADDRESS + ADC_JDR4_BASE))
#define ADC01_DR    (*(volatile uint32_t*)(ADC01_BASE_ADDRESS + ADC_DR_BASE))
	
void ADC01_CH0_init(void);

uint16_t ADC01_CH0_read(void);

#endif  //__ADC_H
