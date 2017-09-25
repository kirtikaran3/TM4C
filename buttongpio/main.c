/*
 * main.c
 */

#define sw1 GPIO_PIN_0
#define sw2 GPIO_PIN_4
#define red GPIO_PIN_1
#define blue GPIO_PIN_2
#define green GPIO_PIN_3

#include <stdint.h>
#include <stdbool.h>

#include "inc/hw_gpio.h"
#include "inc/hw_memmap.h"
#include "inc/hw_sysctl.h"
#include "inc/hw_types.h"
#include "driverlib/gpio.h"
#include "driverlib/sysctl.h"


int main(void) {

	int select;

	SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOF);
	GPIOPinTypeGPIOOutput(GPIO_PORTF_BASE,red|blue|green);

	HWREG(GPIO_PORTF_BASE + GPIO_O_LOCK)=GPIO_LOCK_KEY;

	HWREG(GPIO_PORTF_BASE + GPIO_O_CR)=0x1;

	GPIOPinTypeGPIOInput(GPIO_PORTF_BASE,sw1|sw2);

	GPIOPadConfigSet(GPIO_PORTF_BASE,sw1|sw2,GPIO_STRENGTH_2MA,GPIO_PIN_TYPE_STD_WPU);

	while(1){

		select = 0;

		if(GPIOPinRead(GPIO_PORTF_BASE,sw1)&&!(GPIOPinRead(GPIO_PORTF_BASE,sw2))){

			select=red;
		}
		else{
		if(!(GPIOPinRead(GPIO_PORTF_BASE,sw2))){
			select=blue;
		}
		if((GPIOPinRead(GPIO_PORTF_BASE,sw1))){
					select=green;
				}
		}
		GPIOPinWrite(GPIO_PORTF_BASE,red|blue|green,select);
	}

	//return 0;
}
