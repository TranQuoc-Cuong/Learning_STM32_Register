#include <stdio.h>
#include <stdint.h>

#include "RCC.h"

void m_delay(volatile uint32_t time);
void m_delay(volatile uint32_t time) {
	while(time--);
}

int main() 
{
	
	while(1) 
	{

	}
}
