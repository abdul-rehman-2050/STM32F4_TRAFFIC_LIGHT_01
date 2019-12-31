/*
 *
 * Project_LEDs01
 * Traffic Light Pattern generator
 * Date: 31-December-2019
 * @Author: Abdul Rehman
 * */


#include "stm32f4xx.h"



#define LED_PORT	GPIOE
#define LED_Red 	GPIO_Pin_7
#define LED_Yellow	GPIO_Pin_9
#define LED_Green 	GPIO_Pin_11
#define LED_CLK 	RCC_AHB1Periph_GPIOE

// IR Proximity Sensor Pin declaration
#define IR_PROXY_PORT 	GPIOE
#define IR_PROXY_CLK	RCC_AHB1Periph_GPIOE
#define IR_PROXY_PIN	GPIO_Pin_5



void delay_ms(uint32_t ms){
	ms *= 20000;
	while(ms--){
		  while(!GPIO_ReadInputDataBit(IR_PROXY_PORT,IR_PROXY_PIN)){
			  uint32_t i=0;
			  //Fourth Pattern [Signal is Yellow ]
				 GPIO_ResetBits(LED_PORT,LED_Red);
				 GPIO_ToggleBits(LED_PORT,LED_Yellow);
				 GPIO_ResetBits(LED_PORT,LED_Green);
				 for(i=0;i<20000000;i++){
					 __NOP();
				 }
			  }

	}
}

void LEDs_init(){
	GPIO_InitTypeDef gpio;
	RCC_AHB1PeriphClockCmd(LED_CLK,ENABLE);//ENABLE CLOCK FIRST
	gpio.GPIO_Mode = GPIO_Mode_OUT;
	gpio.GPIO_Pin = LED_Red | LED_Yellow | LED_Green;
	GPIO_Init(LED_PORT,&gpio);
}

void IR_PROXY_init(){
	GPIO_InitTypeDef gpio;
	RCC_AHB1PeriphClockCmd(IR_PROXY_CLK,ENABLE);//ENABLE CLOCK FIRST
	gpio.GPIO_Mode = GPIO_Mode_IN;
	gpio.GPIO_Pin = IR_PROXY_PIN;
	GPIO_Init(IR_PROXY_PORT,&gpio);

}
void setup(){
	LEDs_init();
	IR_PROXY_init();
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


