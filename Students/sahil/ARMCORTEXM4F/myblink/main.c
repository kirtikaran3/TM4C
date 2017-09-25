/*
 * main.c
 */
#include<stdint.h>
#include<stdbool.h>
#include "inc/tm4c123gh6pm.h"
#include "inc/hw_types.h"
#include "inc/hw_memmap.h"
#include "driverlib/gpio.h"
#include "driverlib/sysctl.h"
#define led GPIO_PIN_0
int main(void) {
	
	SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOD);
	GPIOPinTypeGPIOOutput(GPIO_PORTD_BASE,led);
	//GPIOPinWrite(GPIO_PORTD_BASE,gnd,0);
	GPIOPinWrite(GPIO_PORTD_BASE,led,led);
	while(1); return 0;
}
