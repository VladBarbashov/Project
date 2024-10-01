#include "usart1_init.h"


bool HAL_USART1_Init(UART_HandleTypeDef *const huart1) {
	UART_InitTypeDef uartInit = {};

	uartInit.BaudRate = 9600;
	uartInit.OverSampling = UART_OVERSAMPLING_16;
	uartInit.HwFlowCtl = UART_HWCONTROL_NONE;

	uartInit.Mode = UART_MODE_TX_RX;
	uartInit.WordLength = UART_WORDLENGTH_8B;
	uartInit.StopBits = UART_STOPBITS_1;
	uartInit.Parity = UART_PARITY_NONE;

	huart1->Init = uartInit;
	huart1->Instance = USART1;

	if (HAL_UART_Init(&(*huart1)) != HAL_OK) {
		return false;
	}
	return true;
}
