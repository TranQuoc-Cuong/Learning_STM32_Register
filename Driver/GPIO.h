#ifndef __GPIO_H_
#define __GPIO_H_

#include <stdint.h>

#define GPIO_PIN_0  ((uint16_t)0x0001)
#define GPIO_PIN_1  ((uint16_t)0x0002)
#define GPIO_PIN_2  ((uint16_t)0x0004)
#define GPIO_PIN_3  ((uint16_t)0x0008)
#define GPIO_PIN_4  ((uint16_t)0x0010)
#define GPIO_PIN_5  ((uint16_t)0x0020)
#define GPIO_PIN_6  ((uint16_t)0x0040)
#define GPIO_PIN_7  ((uint16_t)0x0080)
#define GPIO_PIN_8  ((uint16_t)0x0100)
#define GPIO_PIN_9  ((uint16_t)0x0200)
#define GPIO_PIN_10 ((uint16_t)0x0400)
#define GPIO_PIN_11 ((uint16_t)0x0800)
#define GPIO_PIN_12 ((uint16_t)0x1000)
#define GPIO_PIN_13 ((uint16_t)0x2000)
#define GPIO_PIN_14 ((uint16_t)0x4000)
#define GPIO_PIN_15 ((uint16_t)0x8000)

#define GPIO_MODE_INPUT_FLOATING  0x00
#define GPIO_MODE_OUTPUT_PP       0x01
#define GPIO_MODE_OUTPUT_OD       0x02
#define GPIO_MODE_AF_PP           0x03
#define GPIO_MODE_AF_OD           0x04
#define GPIO_MODE_INPUT_ANALOG    0x05
#define GPIO_MODE_INPUT_PU        0x06
#define GPIO_MODE_INPUT_PD        0x07

#define GPIO_A_BASE (0x40010800UL)
#define GPIO_B_BASE (0x40010C00UL)
#define GPIO_C_BASE (0x40011000UL)
#define GPIO_D_BASE (0x40011400UL)
#define GPIO_E_BASE (0x40011800UL)

#define GPIO_CRL_BASE  (0x00UL)
#define GPIO_CRH_BASE  (0x04UL)
#define GPIO_IDR_BASE  (0x08UL)
#define GPIO_ODR_BASE  (0x0CUL)
#define GPIO_BSRR_BASE (0x10UL)
#define GPIO_BRR_BASE  (0x14UL)
#define GPIO_LCKR_BASE (0x18UL)

#define GPIO_REG(BASE, OFFSET) (*(volatile uint32_t *)((BASE) + (OFFSET)))

// default speed gpio 50MHz
void GPIO_config(uint32_t GPIO_address, uint16_t pin, uint16_t mode);
void GPIO_write_pin(uint32_t GPIO_address, uint16_t pin, uint8_t state);
uint8_t GPIO_read_pin(uint32_t GPIO_address, uint16_t pin);

#endif  // __GPIO_H_
