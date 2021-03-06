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
#define LEDPort GPIOA

#define Button1 GPIO_Pin_13
#define ButtonPort GPIOC

uint8_t SysClockSource;

GPIO_InitTypeDef GPIOPortA;  //Structure variable to save configuration settings for Port A
GPIO_InitTypeDef GPIOPortC;

void init(void)
{
	RCC_AHBPeriphClockCmd(RCC_AHBPeriph_GPIOA | RCC_AHBPeriph_GPIOC, ENABLE); // Enable clock for port A and C

	GPIO_StructInit(&GPIOPortA);	// Fill the variable with default settings
	GPIOPortA.GPIO_Pin = LED2;   // Specify LED2, PA.5
	GPIOPortA.GPIO_Mode = GPIO_Mode_OUT;    //Config output mode
	GPIOPortA.GPIO_OType = GPIO_OType_PP;	//Config Push-Pull mode
	GPIOPortA.GPIO_Speed = GPIO_Speed_10MHz;  //Maximum speed
	GPIO_Init(LEDPort, &GPIOPortA);			// Initialize Port A with the settings saved in the structure variable

	GPIO_StructInit(&GPIOPortC);	// Fill the variable with default settings
	GPIOPortC.GPIO_Pin = Button1;
	GPIOPortC.GPIO_Mode = GPIO_Mode_IN;
	GPIOPortC.GPIO_PuPd = GPIO_PuPd_DOWN;
	GPIO_Init(ButtonPort, &GPIOPortC);
}

int main(void)
{
	init();

	while(1)
	{
		if(GPIO_ReadInputDataBit(ButtonPort, Button1) == Bit_SET)
		{
			GPIO_SetBits(LEDPort, LED2);
		}
		else
		{
			GPIO_ResetBits(LEDPort, LED2);
		}
	}
}
