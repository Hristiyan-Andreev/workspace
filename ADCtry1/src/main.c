/**
  ******************************************************************************
  * @file    main.c
  * @author  Ac6
  * @version V1.0
  * @date    01-December-2013
  * @brief   Default main function.
  ******************************************************************************
*/
#include "stm32l1xx.h"
#include "stm32l1xx_gpio.h"
#include "stm32l1xx_rcc.h"
#include "stm32l1xx_nucleo.h"


#define A0 GPIO_Pin_0
uint8_t SysClockSource;

static __IO uint32_t TimingDelay;
GPIO_InitTypeDef GPIOPortA;  //Structure variable to save configuration settings for Port A
RCC_ClocksTypeDef RCC_Clocks;
			
void Init(void)
{
	RCC_GetClocksFreq(&RCC_Clocks);

	RCC_AHBPeriphClockCmd(RCC_AHBPeriph_GPIOA, ENABLE); // Enable clock for port A

	GPIO_StructInit(&GPIOPortA);	// Fill the variable with default settings
	GPIOPortA.GPIO_Pin = A0;
	GPIOPortA.GPIO_Mode = GPIO_Mode_AN;
	GPIO_Init(GPIOA, &GPIOPortA);


	if (SysTick_Config(SystemCoreClock / 1000))
	{
			while(1);
	}
}

void Delay(uint32_t nTime)
{
	TimingDelay = nTime;
	while(TimingDelay != 0);
}

int main(void)
{

	for(;;);
}

void SysTick_Handler(void)
{
	if(TimingDelay != 0x00)
	{
		TimingDelay--;
	}
}