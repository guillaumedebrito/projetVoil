//__________________________________________________________
// BINOME :
// ETAT : 
//__________________________________________________________

//____ registres de périphériques du stm_32

#ifndef STM32
#define STM32
#include "stm32f10x.h"
#endif

#ifndef	CLOCK
#define CLOCK
#include "clock.h"
#include "clock_conf.h"
#endif 

#ifndef GPIO
#define GPIO
#include "gpio.h"
#endif

#ifndef TIMER
#define TIMER
#include "timer.h"
#endif 


int main (void)
{	
	
	
	
	
	Timer_1234_Init(TIM2,500000)  ;
	
	//config diodes 
	RCC->APB2ENR|=RCC_APB2ENR_IOPBEN ; 
	Port_IO_Init_Output(GPIOB,8) ; 
	
	while(1) {
		if(((TIM2->SR)&TIM_SR_UIF)==1) {
			TIM2->SR&=~(TIM_SR_UIF) ; 
			Port_IO_Blink(GPIOB,8) ; 
		} 
		
	}
	
	
	return 0;
}

