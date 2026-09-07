#include "S32K144_clock_mock.h"

/* Host-side storage so learning code can compile and link without an MCU. */
SCG_Type g_clockMockScg;
RCM_Type g_clockMockRcm;
