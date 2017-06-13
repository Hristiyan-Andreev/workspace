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

#define LED2 GPIO_Pin_5

GPIO_InitTypeDef GPIOPortAInit;  //Structure variable to save configuration settings for Port A
static int ledval = 0;			//Used to toggle 1 and 0 for the LED



void Init(void)
{
	RCC_APB1PeriphClockCmd(RCC_AHBPeriph_GPIOA, ENABLE); // Enable clock for port A

	GPIO_StructInit(&GPIOPortAInit);	// Fill the variable with default settings
	GPIOPortAInit.GPIO_Pin = LED2;   // Specify LED2, PA.5
	GPIOPortAInit.GPIO_Mode = GPIO_Mode_OUT;    //Config output mode
	GPIOPortAInit.GPIO_OType = GPIO_OType_PP;	//Config Push-Pull mode
	GPIOPortAInit.GPIO_Speed = GPIO_Speed_2MHz;  //Maximum speed 2MHz
	GPIOPortAInit.GPIO_PuPd = GPIO_PuPd_NOPULL; // Push-pull no pull-up, pull-down
	GPIO_Init(GPIOA, &GPIOPortAInit);			// Initialize Port A with the settings saved in the structure variable




}
static __IO uint32_t TimingDelay;

void Delay(uint32_t nTime)		// Delay function
{
	TimingDelay = nTime;
	while(TimingDelay != 0);
}

int main(void)
{
	Init();

	if(SysTick_Config(SystemCoreClock / 1000))			// Reduce Ti
		while(1);

	while (1)
	{
		GPIO_WriteBit(GPIOA, LED2, (ledval) ? Bit_SET : Bit_RESET);
		ledval = 1 - ledval;
		Delay(500);
	}


}



void SysTick_Handler (void)
{
	if (TimingDelay != 0x00)
	{
		TimingDelay--;
	}
}
