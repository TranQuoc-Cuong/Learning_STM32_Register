#include "GPIO.h"

void GPIO_config(uint32_t GPIO_address, uint16_t pin, uint16_t mode) 
{
  uint32_t position = 0;
	uint32_t config = 0;
	
	for (position = 0; position < 16; position++) {
		if (0UL != (pin & (1UL << position))) {
			if (position < 8) {
				GPIO_REG(GPIO_address, GPIO_CRL_BASE) &= ~(0xF << (position * 4));
				
			} else {
				GPIO_REG(GPIO_address, GPIO_CRH_BASE) &= ~(0xF << ((position - 8) * 4));
			}
			
			switch (mode) {
				case GPIO_MODE_OUTPUT_PP:
					config = (0x03 << 0) | (0x00 << 2);
					break;
				
				case GPIO_MODE_OUTPUT_OD:
					config = (0x03 << 0) | (0x01 << 2);
					break;
				
				case GPIO_MODE_AF_PP:
					config = (0x03 << 0) | (0x02 << 2);
					break;
				
				case GPIO_MODE_AF_OD:
					config = (0x03 << 0) | (0x03 << 2);
					break;
				
				case GPIO_MODE_INPUT_ANALOG:
					config = (0x00 << 0) | (0x00 << 2);
					break;
				
				case GPIO_MODE_INPUT_FLOATING:
					config = (0x00 << 0) | (0x01 << 2);
					break;
				
				case GPIO_MODE_INPUT_PU:
					config = (0x00 << 0) | (0x02 << 2);
					GPIO_REG(GPIO_address, GPIO_ODR_BASE) |= (1UL << position);
					break;
				
				case GPIO_MODE_INPUT_PD:
					config = (0x00 << 0) | (0x02 << 2);
					GPIO_REG(GPIO_address, GPIO_ODR_BASE) &= ~(1UL << position);
					break;
			}
			
			if (position < 8) {
				GPIO_REG(GPIO_address, GPIO_CRL_BASE) |= (config << (position * 4));
			} else {
				GPIO_REG(GPIO_address, GPIO_CRH_BASE) |= (config << ((position - 8) * 4));
			}
		}
	}
}

void GPIO_write_pin(uint32_t GPIO_address, uint16_t pin, uint8_t state) 
{
	if (1U == state) {
		GPIO_REG(GPIO_address, GPIO_BSRR_BASE) = pin;
	} else {
		GPIO_REG(GPIO_address, GPIO_BSRR_BASE) = ((uint32_t)pin << 16);
	}
}

uint8_t GPIO_read_pin(uint32_t GPIO_address, uint16_t pin) 
{
	if (0UL != (GPIO_REG(GPIO_address, GPIO_IDR_BASE) & pin)) {
		return 1;
	} else {
		return 0;
	}
}
