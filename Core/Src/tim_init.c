#include "stm32f4xx_hal.h"


void CMSIS_TIM2_Init(void) {
	RCC->APB1ENR |= RCC_APB1ENR_TIM2EN;

	TIM2->PSC = HAL_RCC_GetPCLK1Freq() / 1000 - 1;
	TIM2->ARR = 2*1000 - 1;
	TIM2->CR1 |= TIM_CR1_ARPE; // auto reload preload enable

	TIM2->DIER |= TIM_DIER_UIE; // update interrupt enable
	NVIC_SetPriority(TIM2_IRQn, 1);
	NVIC_EnableIRQ(TIM2_IRQn);

	TIM2->CR1 |= TIM_CR1_CEN; // включение таймера
}
