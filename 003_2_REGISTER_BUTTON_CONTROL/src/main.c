
#include "stm32f4xx.h"
#include "stm32f4_discovery.h"

int count = 0;

void delay(uint32_t time)
{
	while(time--);
}
void GPIO_Config()
{
	RCC->CR |= 0x30000;				//HSE ON
	while(!(RCC->CR & 0x20000));	//HSE ON ready flag wait
	RCC->CR |= 0x00080000;			//CSS ON

	RCC->PLLCFGR |= 0x400000;		//PLL ON
	RCC->PLLCFGR |= 0x4;			//PLLM = 4
	RCC->PLLCFGR |= 0x2A00;			//PLLN = 168
	RCC->PLLCFGR |= 0x00000000;		//PLLP = 2

	RCC->CFGR |= 0x00000000;		//AHB  = 1
	RCC->CFGR |= 0x00001400;		//APB1 = 4
	RCC->CFGR |= 0x00008000;		//APB2 = 2

	RCC->CIR |= 0x00800000;			//CSS flag clear

	RCC->AHB1ENR |= 0x9;			//GPIOA and GPIOD activated

	GPIOD->MODER |= 0x55000000;		//12,13,14,15th pins output
	GPIOD->OTYPER |= 0x00000000;	//D port Push-pull
	GPIOD->OSPEEDR |= 0xFF000000;	//very high speed
	GPIOD->PUPDR |= 0x00000000;		//no pull
}

int main(void)
{

	GPIO_Config();

	while (1)
  	{
		if(GPIOA->IDR & 0x0001)			//GPIOA port is set
		{

			while(GPIOA->IDR & 0x0001);
			delay(1680000);

			count++;

		}
		if(count % 2 == 0)

			GPIOD->ODR = 0x00000000;	//All LEDs are RESET

		else

			GPIOD->ODR = 0xF000;		//All LEDs are SET



	}

}



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
