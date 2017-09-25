#include<stdint.h>
#include<stdbool.h>
#include "inc/tm4c123gh6pm.h"
#include "inc/hw_types.h"
#include "inc/hw_memmap.h"
#include "driverlib/gpio.h"
#include "driverlib/sysctl.h"
#include "driverlib/timer.h"
#include "driverlib/interrupt.h"
//#include  "inc/hw_ints.h"
#define led GPIO_PIN_1
void funct();
int main(void) {
	
	SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOF);
	SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOD);

	GPIOPinTypeGPIOOutput(GPIO_PORTF_BASE,led);
	GPIOPinTypeGPIOInput(GPIO_PORTD_BASE,GPIO_PIN_0);

	GPIOIntTypeSet(GPIO_PORTD_BASE,GPIO_PIN_0,GPIO_HIGH_LEVEL);
	GPIOIntRegister(GPIO_PORTD_BASE,&funct);
	GPIOIntEnable(GPIO_PORTD_BASE,GPIO_INT_PIN_0);
	while(1){
		GPIOPinWrite(GPIO_PORTF_BASE,led,!led);
	}
//	return 0;
}

void funct(){

	GPIOIntClear(GPIO_PORTD_BASE,GPIO_INT_PIN_0);
	GPIOPinWrite(GPIO_PORTF_BASE,led,led);

}
