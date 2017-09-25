/*
 * main.c
 */

#define RED_LED GPIO_PIN_1

#include <stdint.h>
#include <stdbool.h>

#include "inc/tm4c123gh6pm.h"
#include "inc/hw_memmap.h"
#include "inc/hw_types.h"
#include "driverlib/gpio.h"
#include "driverlib/pin_map.h"
#include "driverlib/sysctl.h"
#include "utils/uartstdio.h"


int main(void) {

	SysCtlClockSet(SYSCTL_SYSDIV_1 | SYSCTL_USE_OSC | SYSCTL_OSC_MAIN | SYSCTL_XTAL_16MHZ);
	
	// configure UART0 . Rx = PA_0, Tx = PA_1
	SysCtlPeripheralEnable(SYSCTL_PERIPH_UART0);
	SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOA);
	GPIOPinConfigure(GPIO_PA0_U0RX);
	GPIOPinConfigure(GPIO_PA1_U0TX);
	GPIOPinTypeUART(GPIO_PORTA_BASE, GPIO_PIN_0 | GPIO_PIN_1);

	// configure UART 0 speed
	UARTStdioConfig(0, 115200, 16000000);

	// print message to UART
	UARTprintf("UART is working\n");

	// configure red LED
	SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOF);
	GPIOPinTypeGPIOOutput(GPIO_PORTF_BASE, RED_LED);

	while(1)
	{
		// Turn on led.
		UARTprintf("ON \n");
		GPIOPinWrite(GPIO_PORTF_BASE, RED_LED, RED_LED);
		SysCtlDelay(8000000);

		// Turn off led.
		UARTprintf("OFF \n");
		GPIOPinWrite(GPIO_PORTF_BASE, RED_LED, 0);
		SysCtlDelay(8000000);
	}

}
