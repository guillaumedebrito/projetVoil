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


int main (void)
{
	//enable clock
	RCC->APB2ENR|=RCC_APB2ENR_ADC1EN ;  
	
	//active ADC
	ADC1->CR2|=ADC_CR2_ADON ; 
	
	//active acquisition
	ADC1->CR2|=ADC_CR2_ADON ; 
	
	while(1) {
		if((ADC1->SR&ADC_SR_EOC)==1) {
			
		}
	} 
	return 0;
}

