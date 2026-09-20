#ifndef _RCC_H_
#define _RCC_H_

#include <stdint.h>

#define RCC_BASE 0x40021000

#define RCC_CR_BASE       0x00
#define RCC_CFGR_BASE     0x04
#define RCC_CIR_BASE      0x08
#define RCC_APB2RSTR_BASE 0x0C
#define RCC_APB1RSTR_BASE 0x10
#define RCC_AHBENR_BASE   0x14
#define RCC_APB2ENR_BASE  0x18
#define RCC_APB1ENR_BASE  0x1C
#define RCC_BDCR_BASE     0x20
#define RCC_CSR_BASE      0x24

#define RCC_CR        (*((volatile uint32_t*)(RCC_BASE + RCC_CR_BASE)))
#define RCC_CFGR      (*((volatile uint32_t*)(RCC_BASE + RCC_CFGR_BASE)))
#define RCC_CIR       (*((volatile uint32_t*)(RCC_BASE + RCC_CIR_BASE)))
#define RCC_APB2RSTR  (*((volatile uint32_t*)(RCC_BASE + RCC_APB2RSTR_BASE)))
#define RCC_APB1RSTR  (*((volatile uint32_t*)(RCC_BASE + RCC_APB1RSTR_BASE)))
#define RCC_AHBENR    (*((volatile uint32_t*)(RCC_BASE + RCC_AHBENR_BASE)))
#define RCC_APB2ENR   (*((volatile uint32_t*)(RCC_BASE + RCC_APB2ENR_BASE)))
#define RCC_APB1ENR   (*((volatile uint32_t*)(RCC_BASE + RCC_APB1ENR_BASE)))
#define RCC_BDCR      (*((volatile uint32_t*)(RCC_BASE + RCC_BDCR_BASE)))
#define RCC_CSR       (*((volatile uint32_t*)(RCC_BASE + RCC_CSR_BASE)))
	
void RCC_enable_port_A(void);
void RCC_enable_port_B(void);
void RCC_enable_port_C(void);

#endif //_RCC_H_
