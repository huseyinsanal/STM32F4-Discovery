
#include "stm32f4xx.h"
#include "stm32f4_discovery.h"

GPIO_InitTypeDef GPIO_InitStruct;

int count = 0;

void GPIO_Config()
{

	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOA, ENABLE);
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOD, ENABLE);

	GPIO_InitStruct.GPIO_Pin = GPIO_Pin_0;
	GPIO_InitStruct.GPIO_Mode = GPIO_Mode_IN;
	GPIO_InitStruct.GPIO_OType = GPIO_OType_PP;
	GPIO_InitStruct.GPIO_PuPd = GPIO_PuPd_DOWN;
	GPIO_InitStruct.GPIO_Speed = GPIO_Speed_100MHz;


	GPIO_Init(GPIOA, &GPIO_InitStruct);

	GPIO_InitStruct.GPIO_Pin = GPIO_Pin_12 | GPIO_Pin_13 | GPIO_Pin_14 | GPIO_Pin_15;
	GPIO_InitStruct.GPIO_Mode = GPIO_Mode_OUT;
	GPIO_InitStruct.GPIO_OType = GPIO_OType_PP;
	GPIO_InitStruct.GPIO_PuPd = GPIO_PuPd_NOPULL;
	GPIO_InitStruct.GPIO_Speed = GPIO_Speed_100MHz;


	GPIO_Init(GPIOD, &GPIO_InitStruct);

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
	  if(GPIO_ReadInputDataBit(GPIOA, GPIO_Pin_0))
	  {
		  while(GPIO_ReadInputDataBit(GPIOA, GPIO_Pin_0));

	  	  delay(168000);

	  	  count++;
	  }

	  if(count % 8 == 1)

	  {
		  GPIO_SetBits(GPIOD, GPIO_Pin_12);
	  }

	  else if(count % 8 == 2)
	  {
		  GPIO_SetBits(GPIOD, GPIO_Pin_13);
	  }
	  else if(count % 8 == 3)
	  {
		  GPIO_SetBits(GPIOD, GPIO_Pin_14);
	  }
	  else if(count % 8 == 4)
	  {
		  GPIO_SetBits(GPIOD, GPIO_Pin_15);
	  }
	  else if(count % 8 == 5)
	  {
		  GPIO_ResetBits(GPIOD, GPIO_Pin_15);
	  }
	  else if(count % 8 == 6)
	  {
		  GPIO_ResetBits(GPIOD, GPIO_Pin_14);
	  }

	  else if(count % 8 == 7)
	  {
		  GPIO_ResetBits(GPIOD, GPIO_Pin_13);
	  }
	  else if(count % 8 == 0)
	    {
	  	  GPIO_ResetBits(GPIOD, GPIO_Pin_12);
	    }
	  else
	  {
		  count = 0;
	  }
  }

}


/*
 * Callback used by stm32f4_discovery_audio_codec.c.
 * Refer to stm32f4_discovery_audio_codec.h for more info.
 */
void EVAL_AUDIO_TransferComplete_CallBack(uint32_t pBuffer, uint32_t Size){
  /* TODO, implement your code here */
  return;
}

/*
 * Callback used by stm324xg_eval_audio_codec.c.
 * Refer to stm324xg_eval_audio_codec.h for more info.
 */
uint16_t EVAL_AUDIO_GetSampleCallBack(void){
  /* TODO, implement your code here */
  return -1;
}
