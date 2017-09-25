/*
 * main.c
 */

/*
 * ledbuttonpatern.c
 *
 *  Created on: 16-Dec-2016
 *      Author: HP
 */
#include<stdint.h>
#include<stdbool.h>

#include "inc/hw_types.h"
#include "inc/hw_memmap.h"
#include "driverlib/gpio.h"
#include "driverlib/sysctl.h"
#include "inc/hw_gpio.h"

#define RED GPIO_PIN_1
#define GREEN GPIO_PIN_2
#define BLUE GPIO_PIN_3

#define sw2 GPIO_PIN_4


int main(void){

	SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOF);

	HWREG(GPIO_PORTF_BASE+GPIO_O_LOCK)=GPIO_LOCK_KEY;
	HWREG(GPIO_PORTF_BASE+GPIO_O_CR)=0X1;

	GPIOPinTypeGPIOInput(GPIO_PORTF_BASE,sw2);
	GPIOPadConfigSet(GPIO_PORTF_BASE,sw2,GPIO_STRENGTH_2MA,GPIO_PIN_TYPE_STD_WPU);


	GPIOPinTypeGPIOOutput(GPIO_PORTF_BASE,RED|GREEN|BLUE);

	while(1){

			if((GPIOPinRead(GPIO_PORTF_BASE,sw2))){

					GPIOPinWrite(GPIO_PORTF_BASE,RED|GREEN|BLUE,RED|GREEN|BLUE);
					SysCtlDelay(8000000);
					GPIOPinWrite(GPIO_PORTF_BASE,RED|GREEN|BLUE,!RED|!GREEN|!BLUE);
					SysCtlDelay(8000000);
		}


}

