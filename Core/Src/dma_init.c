#include <stdint.h>

#include "stm32f4xx_hal.h"


void CMSIS_DMA2_Init(uint32_t srcAddr, uint32_t destAddr) {
	RCC->AHB1ENR |= RCC_AHB1ENR_DMA2EN;

	DMA2_Stream0->CR |= DMA_SxCR_MSIZE_0; // 16 бит
	DMA2_Stream0->CR |= DMA_SxCR_PSIZE_0; // 16 бит
	DMA2_Stream0->NDTR = 4;
	DMA2_Stream0->CR |= DMA_SxCR_CIRC; // circular mode

	DMA2_Stream0->FCR |= DMA_SxFCR_DMDIS; // отключение direct mode
	DMA2_Stream0->FCR |= DMA_SxFCR_FTH_0; // 1/2 fifo (2 слова)
	DMA2_Stream0->CR |= DMA_SxCR_MBURST_0; // 4 элемента в пачке

	DMA2_Stream0->CR |= DMA_SxCR_MINC; // инкремент адреса памяти

	DMA2_Stream0->CR |= (DMA_SxCR_PL_0 | DMA_SxCR_PL_1); // высокий приоритет

	DMA2_Stream0->PAR = srcAddr;
	DMA2_Stream0->M0AR = destAddr;

	DMA2_Stream0->CR |= DMA_SxCR_TCIE; // прерывание по окончанию передачи
	NVIC_SetPriority(DMA2_Stream0_IRQn, 1);
	NVIC_EnableIRQ(DMA2_Stream0_IRQn);

	DMA2_Stream0->CR |= DMA_SxCR_EN; // включение DMA
}
