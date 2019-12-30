/*
 *
 * Project_LEDs01
 * Traffic Light Pattern generator
 * Date: 31-December-2019
 * @Author: Abdul Rehman
 * */


#include "stm32f4xx.h"

GPIO_InitTypeDef gpio;

#define LED_PORT	GPIOE
#define LED_Red 	GPIO_Pin_7
#define LED_Yellow	GPIO_Pin_9
#define LED_Green 	GPIO_Pin_11
#define LED_CLK 	RCC_AHB1Periph_GPIOE

void delay_ms(uint32_t ms){
	ms *= 20000;
	while(ms--){
		__NOP();
	}
}

void setup(){
	RCC_AHB1PeriphClockCmd(LED_CLK,ENABLE);//ENABLE CLOCK FIRST
	gpio.GPIO_Mode = GPIO_Mode_OUT;
	gpio.GPIO_Pin = LED_Red | LED_Yellow | LED_Green;
	GPIO_Init(LED_PORT,&gpio);
}

int main(void)
{
	setup();

  while (1)
  {



	  //First Pattern [ Signal is RED ]
	  GPIO_SetBits(LED_PORT,LED_Red);
	  GPIO_ResetBits(LED_PORT,LED_Yellow);
	  GPIO_ResetBits(LED_PORT,LED_Green);
	  delay_ms(5000);

	  //Second Pattern [Signal is Yellow with RED]
	  GPIO_SetBits(LED_PORT,LED_Red);
	  GPIO_SetBits(LED_PORT,LED_Yellow);
	  GPIO_ResetBits(LED_PORT,LED_Green);
	  delay_ms(1000);

	  //Third Pattern [Signal is Green]
	  GPIO_ResetBits(LED_PORT,LED_Red);
	  GPIO_ResetBits(LED_PORT,LED_Yellow);
	  GPIO_SetBits(LED_PORT,LED_Green);
	  delay_ms(3000);

	  //Fourth Pattern [Signal is Yellow ]
	  GPIO_ResetBits(LED_PORT,LED_Red);
	  GPIO_SetBits(LED_PORT,LED_Yellow);
	  GPIO_ResetBits(LED_PORT,LED_Green);
	  delay_ms(1000);



  }
}


