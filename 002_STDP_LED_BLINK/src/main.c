
#include "stm32f4xx.h"
#include "stm32f4_discovery.h"

GPIO_InitTypeDef GPIO_InitStruct;


void GPIO_Config()
{
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOD, ENABLE );  //GPIOD port enabled(1)
	GPIO_InitStruct.GPIO_Pin = GPIO_Pin_12 | GPIO_Pin_13 | GPIO_Pin_14 | GPIO_Pin_15; //choosing pins which we use
	GPIO_InitStruct.GPIO_Mode = GPIO_Mode_OUT; //configuration of GPIO as output or input
	GPIO_InitStruct.GPIO_OType = GPIO_OType_PP; //pull-up or pull-down
	GPIO_InitStruct.GPIO_PuPd = GPIO_PuPd_NOPULL; //same as Open Drain GPIO_OType_OD
	GPIO_InitStruct.GPIO_Speed = GPIO_Speed_100MHz;

	GPIO_Init(GPIOD, &GPIO_InitStruct); //initializing the configurations to GPIOD
}


void delay(uint32_t time)
{
	while(time--);
	}
int main(void)
{

	GPIO_Config();

  while (1)
  {
	  GPIO_SetBits(GPIOD, GPIO_Pin_12 | GPIO_Pin_13 | GPIO_Pin_14 | GPIO_Pin_15);
	  delay(16800000);     //wait for 1 second
	  GPIO_ResetBits(GPIOD, GPIO_Pin_12 | GPIO_Pin_13 | GPIO_Pin_14 | GPIO_Pin_15);
	  delay(16800000);     //wait for 1 second
  }
}

void EVAL_AUDIO_TransferComplete_CallBack(uint32_t pBuffer, uint32_t Size){
  /* TODO, implement your code here */
  return;
}

uint16_t EVAL_AUDIO_GetSampleCallBack(void){
  /* TODO, implement your code here */
  return -1;
}
