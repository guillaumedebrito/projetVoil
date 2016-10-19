#ifndef STM32
#define STM32
#include "stm32f10x.h"
#endif

//fonction qui permet de configurer une broche d'un port en output push-pull.
char Port_IO_Init_Output( GPIO_TypeDef * Port, u8 Broche) ; 

// fonction qui permet de configurer une broche d'un port en input floating.
char Port_IO_Init_Input( GPIO_TypeDef * Port, u8 Broche) ; 

//fonction qui permet de mettre à 1 une broche d'un port
void Port_IO_Set(GPIO_TypeDef * Port, u8 Broche) ; 

//fonction qui permet de mettre à 0 une broche d'un port
void Port_IO_Reset(GPIO_TypeDef * Port, u8 Broche) ; 

//fonction qui inverse l'état d'une broche
void Port_IO_Blink(GPIO_TypeDef * Port, u8 Broche) ; 

//fonction qui permet de lire l'état d'une broche d'un port
unsigned int Port_IO_Read(GPIO_TypeDef * Port, u8 Broche) ; 