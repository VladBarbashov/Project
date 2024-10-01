#include "stm32f4xx_hal.h"


void CMSIS_ADC1_Init(void) {
	RCC->APB2ENR |= RCC_APB2ENR_ADC1EN;
	ADC1->CR2 |= ADC_CR2_ADON;

	ADC1_COMMON->CCR |= ADC_CCR_TSVREFE; // включение температурного датчика

	ADC1->CR1 |= ADC_CR1_SCAN;
	ADC1->SQR1 |= (ADC_SQR1_L_1 | ADC_SQR1_L_0); // 4 вычисления

	ADC1->SQR3 |= (ADC_SQR3_SQ1_4 | ADC_SQR3_SQ1_1); // выбор первого канала на 18 номер
	ADC1->SQR3 |= (ADC_SQR3_SQ2_4 | ADC_SQR3_SQ2_1); // выбор второго канала на 18 номер
	ADC1->SQR3 |= (ADC_SQR3_SQ3_4 | ADC_SQR3_SQ3_1); // выбор третьего канала на 18 номер
	ADC1->SQR3 |= (ADC_SQR3_SQ4_4 | ADC_SQR3_SQ4_0); // выбор четвертого канала на 17 номер

	ADC1->SMPR1 |= ADC_SMPR1_SMP18_2 | ADC_SMPR1_SMP18_1 | ADC_SMPR1_SMP18_0; // количество циклов выборки
	ADC1->SMPR1 |= ADC_SMPR1_SMP17_2 | ADC_SMPR1_SMP17_1 | ADC_SMPR1_SMP17_0; // количество циклов выборки

	ADC1->CR2 |= ADC_CR2_DDS; // включение повторения dma
	ADC1->CR2 |= ADC_CR2_DMA; // включение dma
}
