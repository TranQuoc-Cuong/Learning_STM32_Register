#ifndef CLOCK_DRIVER_H_
#define CLOCK_DRIVER_H_

#include <stdint.h>

typedef enum {
  CLOCK_STATUS_OK = 0,
  CLOCK_STATUS_INVALID,
  CLOCK_STATUS_SWITCH_TIMEOUT,

  CLOCK_STATUS_SOSC_IN_USE,
  CLOCK_STATUS_SOSC_TIMEOUT,

  CLOCK_STATUS_SPLL_IN_USE,
  CLOCK_STATUS_SPLL_TIMEOUT,
} clock_status_t;

clock_status_t clock_init(void);

#endif //CLOCK_DRIVER_H_