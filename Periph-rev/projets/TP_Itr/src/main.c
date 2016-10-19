//__________________________________________________________
// BINOME :
// ETAT : 
//__________________________________________________________



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



void ITR_blink_diode(void)  {
	Port_IO_Blink(GPIOB,8) ; 
}



int main (void)
{
	//config rapide diode 
	RCC->APB2ENR|=RCC_APB2ENR_IOPBEN ; 
	Port_IO_Init_Output(GPIOB,8) ; 
	
	//config du timer 
	Timer_1234_Init(TIM2,500000) ; 
	
	Timer_Active_IT(TIM2,2,ITR_blink_diode) ; 
	

	
	while(1){
		
	}
	
	return 0;
}

