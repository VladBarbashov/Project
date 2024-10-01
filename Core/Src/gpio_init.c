#include "stm32f4xx_hal.h"


void HAL_GPIOC_Init(void) {
	GPIO_InitTypeDef initStruct = {};
	initStruct.Mode = GPIO_MODE_OUTPUT_PP;
	initStruct.Pin = GPIO_PIN_13;

	__HAL_RCC_GPIOC_CLK_ENABLE();

	HAL_GPIO_Init(GPIOC, &initStruct);
}
