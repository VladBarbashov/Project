#include "rtc_init.h"
#include "stm32f4xx_hal_rtc.h"


void HAL_RTClk_Init(RTC_HandleTypeDef *const hrtc, UART_HandleTypeDef *const huart) {
	RTC_InitTypeDef initStruct = {};

	uint8_t recievedData[17];
	RTC_TimeTypeDef sTime = {0};
	RTC_DateTypeDef sDate = {0};

	while (HAL_UART_Receive(huart, recievedData, 19, HAL_MAX_DELAY) != HAL_OK);
	HAL_UART_Transmit(huart, (uint8_t*)"OK", 2, HAL_MAX_DELAY);

	int date = 0;
	int month = 0;
	int year = 0;

	int hours = 0;
	int minutes = 0;
	int seconds = 0;

	sscanf(recievedData, "%02d.%02d.%02d %02d:%02d:%02d",
		  &date, &month, &year, &hours, &minutes, &seconds);

	sDate.Date = date;
	sDate.Month = month;
	sDate.Year = year;
	sDate.WeekDay = RTC_WEEKDAY_FRIDAY;

	sTime.Hours = hours;
	sTime.Minutes = minutes;
	sTime.Seconds = seconds;
	sTime.DayLightSaving = RTC_DAYLIGHTSAVING_NONE;
	sTime.StoreOperation = RTC_STOREOPERATION_RESET;

	initStruct.HourFormat = RTC_HOURFORMAT_24;
	initStruct.AsynchPrediv = 127;
	initStruct.SynchPrediv = 255;
	initStruct.OutPut = RTC_OUTPUT_DISABLE;
	initStruct.OutPutPolarity = RTC_OUTPUT_POLARITY_HIGH;
	initStruct.OutPutType = RTC_OUTPUT_TYPE_OPENDRAIN;

	hrtc->Instance = RTC;
	hrtc->Init = initStruct;

	HAL_StatusTypeDef st = HAL_RTC_Init(hrtc);
	HAL_StatusTypeDef st2 = HAL_RTC_SetDate(hrtc, &sDate, RTC_FORMAT_BIN);
	HAL_StatusTypeDef st3 = HAL_RTC_SetTime(hrtc, &sTime, RTC_FORMAT_BIN);

	//HAL_RTCEx_SetCalibrationOutPut(hrtc, RTC_CALIBOUTPUT_1HZ);
}
