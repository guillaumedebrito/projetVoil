#ifndef STM32
#define STM32
#include "stm32f10x.h"
#endif

//fonction qui permet de configurer une broche d'un port en output push-pull.
void Port_IO_Init_Output( GPIO_TypeDef * Port, u8 Broche) {
	if (Broche<8) {
		Port->CRL|=(0x01<<(Broche*4)) ; 
	}else {
		Port->CRH|=(0x01<<((Broche%8)*4)) ; 
	}
	
}	

// fonction qui permet de configurer une broche d'un port en input floating.
void Port_IO_Init_Input( GPIO_TypeDef * Port, u8 Broche) {
	if(Broche<8) {
		Port->CRL|=(0x01<<((Broche*4)+2)) ; 
	} else {
		Port->CRH|=(0x01<<(((Broche%8)*4)+2)) ; 
	}
}

//fonction qui permet de mettre à 1 une broche d'un port
void Port_IO_Set(GPIO_TypeDef * Port, u8 Broche) {
	Port->BSRR|=(0x01<<Broche)  ; 
}

//fonction qui permet de mettre à 0 une broche d'un port
void Port_IO_Reset(GPIO_TypeDef * Port, u8 Broche) {
	Port->BSRR|=(0x01<<(Broche+16)) ; 
}

//fonction qui inverse l'état d'une broche
void Port_IO_Blink(GPIO_TypeDef * Port, u8 Broche) {
	if((Port->ODR&(0x01<<Broche))==0) {
		Port_IO_Set(Port,Broche) ; 
	} else {
		Port_IO_Reset(Port,Broche) ; 
	}
}

//fonction qui permet de lire l'état d'une broche d'un port
unsigned int Port_IO_Read(GPIO_TypeDef * Port, u8 Broche) {
	return ((Port->IDR&(0x01<<Broche))>>Broche)  ; 
}
