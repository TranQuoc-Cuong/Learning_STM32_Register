#include "RCC.h"

void RCC_enable_port_A(void) {
	RCC_APB2ENR |= (1UL << 2);
}

void RCC_enable_port_B(void) {
	RCC_APB2ENR |= (1UL << 3);
}

void RCC_enable_port_C(void) {
	RCC_APB2ENR |= (1UL << 4);
}
