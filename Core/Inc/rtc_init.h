#ifndef INC_RTC_INIT_H_
#define INC_RTC_INIT_H_


#include "stm32f4xx_hal.h"


void HAL_RTClk_Init(RTC_HandleTypeDef *const hrtc, UART_HandleTypeDef *const huart);


#endif /* INC_RTC_INIT_H_ */
