#ifndef __AFIO_H_
#define __AFIO_H_

#define AFIO_BASE_ADDRESS (0x40010000UL)

#define AFIO_EVCR_BASE    (0x00)
#define AFIO_MAPR_BASE    (0x04)
#define AFIO_EXTICR1_BASE (0x08)
#define AFIO_EXTICR2_BASE (0x0C)
#define AFIO_EXTICR3_BASE (0x10)
#define AFIO_EXTICR4_BASE (0x14)
#define AFIO_MAPR2_BASE   (0x1C)

#define AFIO_EVCR    (*(volatile uint32_t*)(AFIO_EVCR_BASE + AFIO_BASE_ADDRESS))
#define AFIO_MAPR    (*(volatile uint32_t*)(AFIO_MAPR_BASE + AFIO_BASE_ADDRESS))
#define AFIO_EXTICR1 (*(volatile uint32_t*)(AFIO_EXTICR1_BASE + AFIO_BASE_ADDRESS))
#define AFIO_EXTICR2 (*(volatile uint32_t*)(AFIO_EXTICR2_BASE + AFIO_BASE_ADDRESS))
#define AFIO_EXTICR3 (*(volatile uint32_t*)(AFIO_EXTICR3_BASE + AFIO_BASE_ADDRESS))
#define AFIO_EXTICR4 (*(volatile uint32_t*)(AFIO_EXTICR4_BASE + AFIO_BASE_ADDRESS))
#define AFIO_MAPR2   (*(volatile uint32_t*)(AFIO_MAPR2_BASE + AFIO_BASE_ADDRESS))
	
#endif //__AFIO_H_
