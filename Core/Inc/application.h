#ifndef INC_APPLICATION_H_
#define INC_APPLICATION_H_

#include "stdint.h"

#include "stm32f1xx_hal.h"
// Include for LL
#include "stm32f1xx_ll_system.h"
#include "stm32f1xx_ll_gpio.h"
#include "stm32f1xx_ll_exti.h"
#include "stm32f1xx_ll_bus.h"
#include "stm32f1xx_ll_cortex.h"
#include "stm32f1xx_ll_rcc.h"
#include "stm32f1xx_ll_utils.h"
#include "stm32f1xx_ll_pwr.h"
#include "stm32f1xx_ll_dma.h"

void app_main(void);

#endif /* INC_APPLICATION_H_ */
