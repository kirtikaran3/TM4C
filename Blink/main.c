/*
 * main.c
 */
#define red GPIO_PIN_1
#define blue GPIO_PIN_2
#define green GPIO_PIN_3

#include<stdint.h>
#include<stdbool.h>
#include "inc/tm4c123gh6pm.h"
#include "inc/hw_types.h"
#include "inc/hw_memmap.h"
#include "driverlib/gpio.h"
#include "driverlib/sysctl.h"


int main(void) {

		SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOF);
		GPIOPinTypeGPIOOutput(GPIO_PORTF_BASE,red|blue|green);

		while(1){

			GPIOPinWrite(GPIO_PORTF_BASE,red|green|blue,red);
			SysCtlDelay(8000000);

			GPIOPinWrite(GPIO_PORTF_BASE,red|green|blue,blue);
						SysCtlDelay(8000000);

						GPIOPinWrite(GPIO_PORTF_BASE,red|green|blue,green);
									SysCtlDelay(8000000);



		}


	//	return 0;
}
