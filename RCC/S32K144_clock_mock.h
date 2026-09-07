#ifndef S32K144_CLOCK_MOCK_H_
#define S32K144_CLOCK_MOCK_H_

#include <stdint.h>

/*
 * Training/host-build mock only.
 * This is NOT the official NXP S32K144 device header and must not be used
 * to access real hardware.
 */

typedef struct
{
    volatile const uint32_t VERID;
    volatile const uint32_t PARAM;
    uint8_t RESERVED_0[8];
    volatile const uint32_t CSR;
    volatile uint32_t RCCR;
    volatile uint32_t VCCR;
    volatile uint32_t HCCR;
    volatile uint32_t CLKOUTCNFG;
    uint8_t RESERVED_1[220];
    volatile uint32_t SOSCCSR;
    volatile uint32_t SOSCDIV;
    volatile uint32_t SOSCCFG;
    uint8_t RESERVED_2[1268];
    volatile uint32_t SPLLCSR;
    volatile uint32_t SPLLDIV;
    volatile uint32_t SPLLCFG;
} SCG_Type;

typedef struct
{
    uint8_t RESERVED_0[0x1CU];
    volatile uint32_t SRIE;
} RCM_Type;

extern SCG_Type g_clockMockScg;
extern RCM_Type g_clockMockRcm;

#define SCG (&g_clockMockScg)
#define RCM (&g_clockMockRcm)

#define SCG_CSR_SCS_MASK             (0xFUL << 24U)
#define SCG_CSR_SCS_SHIFT            (24U)
#define SCG_CSR_SCS(value)           (((uint32_t)(value) << SCG_CSR_SCS_SHIFT) & SCG_CSR_SCS_MASK)

#define SCG_RCCR_SCS_MASK            (0xFUL << 24U)
#define SCG_RCCR_SCS_SHIFT           (24U)
#define SCG_RCCR_SCS(value)          (((uint32_t)(value) << SCG_RCCR_SCS_SHIFT) & SCG_RCCR_SCS_MASK)
#define SCG_RCCR_DIVCORE_MASK        (0xFUL << 16U)
#define SCG_RCCR_DIVCORE_SHIFT       (16U)
#define SCG_RCCR_DIVCORE(value)      (((uint32_t)(value) << SCG_RCCR_DIVCORE_SHIFT) & SCG_RCCR_DIVCORE_MASK)
#define SCG_RCCR_DIVBUS_MASK         (0xFUL << 4U)
#define SCG_RCCR_DIVBUS_SHIFT        (4U)
#define SCG_RCCR_DIVBUS(value)       (((uint32_t)(value) << SCG_RCCR_DIVBUS_SHIFT) & SCG_RCCR_DIVBUS_MASK)
#define SCG_RCCR_DIVSLOW_MASK        (0xFUL)
#define SCG_RCCR_DIVSLOW_SHIFT       (0U)
#define SCG_RCCR_DIVSLOW(value)      (((uint32_t)(value) << SCG_RCCR_DIVSLOW_SHIFT) & SCG_RCCR_DIVSLOW_MASK)

#define SCG_SOSCCSR_SOSCERR_MASK     (1UL << 26U)
#define SCG_SOSCCSR_SOSCSEL_MASK     (1UL << 25U)
#define SCG_SOSCCSR_SOSCVLD_MASK     (1UL << 24U)
#define SCG_SOSCCSR_LK_MASK          (1UL << 23U)
#define SCG_SOSCCSR_SOSCCMRE_MASK    (1UL << 17U)
#define SCG_SOSCCSR_SOSCCM_MASK      (1UL << 16U)
#define SCG_SOSCCSR_SOSCEN_MASK      (1UL)

#define SCG_SOSCDIV_SOSCDIV2_MASK   (0x7UL << 8U)
#define SCG_SOSCDIV_SOSCDIV2_SHIFT  (8U)
#define SCG_SOSCDIV_SOSCDIV2(value) (((uint32_t)(value) << SCG_SOSCDIV_SOSCDIV2_SHIFT) & SCG_SOSCDIV_SOSCDIV2_MASK)
#define SCG_SOSCDIV_SOSCDIV1_MASK   (0x7UL)
#define SCG_SOSCDIV_SOSCDIV1_SHIFT  (0U)
#define SCG_SOSCDIV_SOSCDIV1(value) (((uint32_t)(value) << SCG_SOSCDIV_SOSCDIV1_SHIFT) & SCG_SOSCDIV_SOSCDIV1_MASK)

#define SCG_SOSCCFG_RANGE_MASK       (0x3UL << 4U)
#define SCG_SOSCCFG_RANGE_SHIFT      (4U)
#define SCG_SOSCCFG_RANGE(value)     (((uint32_t)(value) << SCG_SOSCCFG_RANGE_SHIFT) & SCG_SOSCCFG_RANGE_MASK)
#define SCG_SOSCCFG_HGO_MASK         (1UL << 3U)
#define SCG_SOSCCFG_EREFS_MASK       (1UL << 2U)

#define SCG_SPLLCSR_SPLLERR_MASK     (1UL << 26U)
#define SCG_SPLLCSR_SPLLSEL_MASK     (1UL << 25U)
#define SCG_SPLLCSR_SPLLVLD_MASK     (1UL << 24U)
#define SCG_SPLLCSR_LK_MASK          (1UL << 23U)
#define SCG_SPLLCSR_SPLLCMRE_MASK    (1UL << 17U)
#define SCG_SPLLCSR_SPLLCM_MASK      (1UL << 16U)
#define SCG_SPLLCSR_SPLLEN_MASK      (1UL)

#define SCG_SPLLDIV_SPLLDIV2_MASK   (0x7UL << 8U)
#define SCG_SPLLDIV_SPLLDIV2_SHIFT  (8U)
#define SCG_SPLLDIV_SPLLDIV2(value) (((uint32_t)(value) << SCG_SPLLDIV_SPLLDIV2_SHIFT) & SCG_SPLLDIV_SPLLDIV2_MASK)
#define SCG_SPLLDIV_SPLLDIV1_MASK   (0x7UL)
#define SCG_SPLLDIV_SPLLDIV1_SHIFT  (0U)
#define SCG_SPLLDIV_SPLLDIV1(value) (((uint32_t)(value) << SCG_SPLLDIV_SPLLDIV1_SHIFT) & SCG_SPLLDIV_SPLLDIV1_MASK)

#define SCG_SPLLCFG_MULT_MASK       (0x1FUL << 16U)
#define SCG_SPLLCFG_MULT_SHIFT      (16U)
#define SCG_SPLLCFG_MULT(value)     (((uint32_t)(value) << SCG_SPLLCFG_MULT_SHIFT) & SCG_SPLLCFG_MULT_MASK)
#define SCG_SPLLCFG_PREDIV_MASK     (0x7UL << 8U)
#define SCG_SPLLCFG_PREDIV_SHIFT    (8U)
#define SCG_SPLLCFG_PREDIV(value)   (((uint32_t)(value) << SCG_SPLLCFG_PREDIV_SHIFT) & SCG_SPLLCFG_PREDIV_MASK)
#define SCG_SPLLCFG_SOURCE_MASK     (1UL)
#define SCG_SPLLCFG_SOURCE_SHIFT    (0U)
#define SCG_SPLLCFG_SOURCE(value)   (((uint32_t)(value) << SCG_SPLLCFG_SOURCE_SHIFT) & SCG_SPLLCFG_SOURCE_MASK)

#define RCM_SRIE_SACKERR_MASK       (1UL << 13U)
#define RCM_SRIE_MDM_AP_MASK        (1UL << 11U)
#define RCM_SRIE_SW_MASK            (1UL << 10U)
#define RCM_SRIE_LOCKUP_MASK        (1UL << 9U)
#define RCM_SRIE_JTAG_MASK          (1UL << 8U)
#define RCM_SRIE_GIE_MASK           (1UL << 7U)
#define RCM_SRIE_PIN_MASK           (1UL << 6U)
#define RCM_SRIE_WDOG_MASK          (1UL << 5U)
#define RCM_SRIE_CMU_LOC_MASK       (1UL << 4U)
#define RCM_SRIE_LOL_MASK           (1UL << 3U)
#define RCM_SRIE_LOC_MASK           (1UL << 2U)
#define RCM_SRIE_DELAY_MASK         (0x3UL)
#define RCM_SRIE_DELAY_SHIFT        (0U)
#define RCM_SRIE_DELAY(value)       (((uint32_t)(value) << RCM_SRIE_DELAY_SHIFT) & RCM_SRIE_DELAY_MASK)

#endif /* S32K144_CLOCK_MOCK_H_ */
