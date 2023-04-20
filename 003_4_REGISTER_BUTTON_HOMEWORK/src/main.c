
#include "stm32f4xx.h"
#include "stm32f4_discovery.h"

int count = 0;

void GPIO_Config()
{

		RCC->CR |= 0x00030000;				//HSE ON

		while(!(RCC->CR & 0x00020000));	//HSE ON ready flag wait

		RCC->CR |= 0x00080000;			//CSS ON

		RCC->PLLCFGR |= 0x00400000;		//PLL ON
		RCC->PLLCFGR |= 0x00000004;			//PLLM = 4
		RCC->PLLCFGR |= 0x00002A00;			//PLLN = 168
		RCC->PLLCFGR |= 0x00000000;		//PLLP = 2

		RCC->CFGR |= 0x00000000;		//AHB  = 1
		RCC->CFGR |= 0x00001400;		//APB1 = 4
		RCC->CFGR |= 0x00008000;		//APB2 = 2

		RCC->CIR |= 0x00800000;			//CSS flag clear

		RCC->AHB1ENR |= 0x00000009;			//GPIOA and GPIOD activated

		GPIOD->MODER |= 0x55000000; 	//GPIOD 12,13,14,15 output
		GPIOD->OTYPER |= 0x00000000;		//GPIOD 12,13,14,15 push-pull
		GPIOD->OSPEEDR |= 0xFF000000;	//GPIOD 12,13,14,15 max speed
		GPIOD->PUPDR |=	0x00000000;


		//GPIOA->OTYPER |= 0x1;			//GPIOA 0 push-pull
		//GPIOA->PUPDR |= 0x2;			//GPIOA 0 pull-down
		//GPIOA->OSPEEDR |= 0x3;			//max speed


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

		if(GPIOA->IDR & 0x00000001)
		{
			while(GPIOA->IDR & 0x00000001);

			delay(1680000);

			count++;
		}

		if(count == 1)
		{
			GPIOD->ODR = 0x1000;
		}

		else if(count == 2)
		{
			GPIOD->ODR = 0x3000;
		}
		else if(count == 3)
		{
			GPIOD->ODR = 0x7000;
		}
		else if(count == 4)
		{
			GPIOD->ODR = 0xF000;
		}
		else if(count == 5)
		{
			GPIOD->ODR = 0x7000;
		}
		else if(count == 6)
		{
			GPIOD->ODR = 0x3000;
		}
		else if(count == 7)
		{
			GPIOD->ODR = 0x1000;
		}
		else
		{
			GPIOD->ODR = 0x0;
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
