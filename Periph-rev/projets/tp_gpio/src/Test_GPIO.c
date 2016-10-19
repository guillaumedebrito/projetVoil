//__________________________________________________________
// projet/TP_GPIO/      MAIN.C
// Tentative de faire clignoter une diode
// BINOME :
// ETAT : compilé et testé
// MODIFICATIONS :
// 14/09     : suppression des options de compilation et nettoyage des TODO
// 1/09/2013 : 0xACC0 => Nettoyage des chemins pour windows 7 + question sur le .h
//__________________________________________________________



#ifndef STM32
#define STM32
#include "stm32f10x.h"
#endif

#ifndef GPIO
#define GPIO
#include "gpio.h"
#endif



//____ registres de périphériques du stm_32
// Clic droit sur stm32f10X.h et faire "open document"  pour ouvrir le fichier
//TODO :
// appréciez la déclaration de GPIOB ligne 1409 :-) la valeur numérique GPIOB_BASE (ligne 1316)
// est castée en pointeur sur une structure de type GPIO_Typedef.
// A quelle adresse pointe ce pointeur (complétez la ligne suivante) ?
// GPIOB_BASE  = APB2PERIPH_BASE + 0x0C00 = 0x40010C00
// APB2PERIPH_BASE = PERIPH_BASE + 0x10000
// PERIPH_BASE = 0x40000000
// GPIOB <=> ( ( GPIO_Typedef *) 0x40010C00 ) 
// On construit ainsi un pointeur à l'adresse désirée. Vérifiez cette adresse
// avec la doc du Reference Manual page 167 et la Table 1 de la page 41. 
// 
// Observez la déclaration de la structure GPIO_Typedef ligne 1000 à 1010
// Sachant que GPIOB->CRH est une notation simplifiée de (*GPIOB).CRH, le terme GPIOB->CRH est-il
//  c) une macro donnant un registre
// A quelle adresse agit GPIOB->CRH ? 0x40010C04








int main (void)
{
	
 	// Cette ligne valide les horloges de quelques périphériques, pour le moment ignorez-la 
	// mais CONSERVEZ CETTE LIGNE EN DEBUT DE PROGRAMME !
 	(RCC->APB2ENR)|= RCC_APB2ENR_IOPAEN | RCC_APB2ENR_IOPBEN | RCC_APB2ENR_IOPCEN;

	
	// On met tous les bits du registre CRH de GPIOB à 1
	// CRH = 1111 1111 : 1111 1111 : 1111 1111 : 1111 1111 
	GPIOB->CRH = 0xFFFFFFFF;
	// TODO : Vérifiez le bon fonctionnement en passant en simulation (debug-> start)
	// Puis ensimu cliquez sur Peripherals->GPIOB et observez le contenu du registre.
	
	// La ligne suivante est équivalente mais elle mets des 0
	(*GPIOB).CRH = 0;
	
	//__ configuration du port PB.9 en sortie (output push-pull)
	// CRH = xxxx xxxx : xxxx xxxx : xxxx xxxx : 0001 xxxx 	
	//GPIOB->CRH = (0x01 << 4);
	// TODO : Qu'est-ce que veut dire (x << y) ? décaler à gauche 1 de 4 
	// TODO : Pour ne pas toucher aux bits autres que ceux de configruation du port 9, il faut faire un masque. Faites le ! 
	//GPIOB->CRH |= (0x01 <<4) | (0x01 <<8) ; 
	Port_IO_Init_Output(GPIOB,10) ; 
	Port_IO_Init_Output(GPIOB,9) ; 
	
	//GPIOA->CRL |= (0x01<<2) ; 
	Port_IO_Init_Input(GPIOA,0) ; 
	
	// Faire clignoter la diode sur le port PB.9
	while(1)
	{
		//CHECK port A.0
		if(Port_IO_Read(GPIOA,0)==1) {			
			//DIODE 10 
			//GPIOB->ODR |= (0x01 << 10);
			Port_IO_Set(GPIOB,10) ; 
		} else {
			//GPIOB->ODR &= ~(0x01<<10);
			Port_IO_Reset(GPIOB,10) ; 
		}
		
		
		Port_IO_Blink(GPIOB,9) ; 
		/*
		//DIODE 9 
		if((GPIOB->ODR&(0x01<<9))==0) {
			//GPIOB->ODR |= (0x01 << 9);
			Port_IO_Set(GPIOB,9) ; 
		} else {
			//GPIOB->ODR &= ~(0x01<<9);
			Port_IO_Reset(GPIOB,9) ; 
		}
		*/

		/*
		//OLD
		if (flipflop == 1) {
		// ODR = xxxx xxxx : xxxx xxxx : xxxx xx1x : xxxx xxxx 
			//GPIOB->ODR = (0x01 << 9); 
			// TODO : Comment faire pour ne changer que le bit 9 ?
			//On fait un masque 
			GPIOB->ODR |= (0x01 << 9);
			flipflop = 0;
			// TODO : Comment faier pour se passer du flipflop en utilisant directement la valeur de ODR ?
		} else {
		// ODR=xxxx xxxx | xxxx xxxx | xxxx xx0x |xxxx xxxx 
			GPIOB->ODR = 0x00; 
			flipflop = 1;
		}
		*/
	}

	return 0;
}

