#include "stm32f4xx.h"
#include "stm32f4_discovery.h"


void RCC_Config(void)
{
	//8 000 000 -> 168 000 000
	RCC->CR &= ~(1 << 0);				//HSI OFF
	RCC->CR |= 1 << 16;					//HSE ON
	while(!(RCC->CR & (1 << 17)));		//wait HSE active
	RCC->CR |= 1 << 19;
	RCC->PLLCFGR = 0X00000000;		//PLLCFGR Reset
	RCC->PLLCFGR |= (1 << 22);		//PLL Sorce HSE
	RCC->PLLCFGR |= (4 << 0);		//PLL M 4
	RCC->PLLCFGR |= (168 << 6);		//PLL N 168

	RCC->CR |= (1 << 24);				//PLL ON
	while(!(RCC->CR & ~(1 << 25)));		//Wait PLL active

	RCC->CFGR &= ~(1 << 0);
	RCC->CFGR |= (1 << 1);				//System Clock is PLL

	while(!(RCC->CFGR & (1 << 1))); 	//Select system clock is PLL clock
}

void GPIO_Config(void)
{

	RCC->AHB1ENR |= 1 << 3;     	//clock activated for d port of ahb1

	GPIOD->MODER |= 1 << 24;
	GPIOD->MODER &= ~(1 << 25);		//GPIOD 12. pin output
	GPIOD->MODER |= 1 << 26;
	GPIOD->MODER &= ~(1 << 27);		//GPIOD 13. pin output
	GPIOD->MODER |= 1 << 28;
	GPIOD->MODER &= ~(1 << 29);		//GPIOD 14.pin output
	GPIOD->MODER |= 1 << 30;
	GPIOD->MODER &= ~(1 << 31);		//GPIOD 15.pin output

	GPIOD->OSPEEDR |= 0xFF000000;	//GPIOD 12,13,14,15th pins are high speed

}
int main(void)
{

	RCC_Config();

	SystemCoreClockUpdate();

	GPIO_Config();

  while (1)
  {

	  GPIOD->ODR |= 1 << 12;
	  GPIOD->ODR |= 1 << 13;
	  GPIOD->ODR |= 1 << 14;
	  GPIOD->ODR |= 1 << 15;		//pins are set

	  for(int i =0; i < 1680000; i++);

	  GPIOD->ODR &= ~(1 << 12);
	  GPIOD->ODR &= ~(1 << 13);
	  GPIOD->ODR &= ~(1 << 14);
	  GPIOD->ODR &= ~(1 << 15);		//pins are reset

	  for(int i = 0; i < 1680000; i++);

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
