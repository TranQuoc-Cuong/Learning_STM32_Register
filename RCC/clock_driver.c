#include "clock_driver.h"

#include <stdbool.h>

#include "S32K144_clock_mock.h"

#define BOARD_SOSC_HIGH_GAIN (1UL)
#define CLOCK_TIMEOUT_LOOPS (1000000UL)

static bool clock_wait_flag_set(volatile const uint32_t* reg, uint32_t mask) {
  uint32_t timeout = CLOCK_TIMEOUT_LOOPS;

  while(((*reg & mask) == 0UL) && (timeout > 0UL)) {
    timeout--;
  }

  return ((*reg & mask) != 0UL);
}

static bool clock_wait_field(volatile const uint32_t* reg, uint32_t mask, uint32_t expected) {
  uint32_t timeout = CLOCK_TIMEOUT_LOOPS;

  while(((*reg & mask) != expected) && (timeout > 0UL)) {
    timeout--;
  }

  return ((*reg & mask) == expected);
}

static bool clock_is_system_source(uint32_t source) {
  uint32_t current_source;
  uint32_t expected_source;

  current_source = SCG->CSR & SCG_CSR_SCS_MASK;
  expected_source = SCG_CSR_SCS(source);

  return (current_source == expected_source);
}

static clock_status_t clock_init_sosc(void) {
  if (clock_wait_flag_set(SCG->SOSCCSR, SCG_SOSCCSR_SOSCEN_MASK)) {
    return CLOCK_STATUS_SOSC_IN_USE;
  }

  SCG->SOSCCSR &= ~SCG_SOSCCSR_LK_MASK;
  

}