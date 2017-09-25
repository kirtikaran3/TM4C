#include<stdint.h>
#include<stdbool.h>
#include "inc/tm4c123gh6pm.h"
#include "inc/hw_types.h"
#include "inc/hw_memmap.h"
#include "driverlib/gpio.h"
#include "driverlib/sysctl.h"
#include "driverlib/adc.h"
#include "driverlib/uart.h"
#include "driverlib/uart.c"
//#include "util/uartstdio.h"
#define red GPIO_PIN_1
int main(void) {
	char data='h';

	SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOB);
	SysCtlPeripheralEnable(SYSCTL_PERIPH_UART0);
	UARTClockSourceSet(UART0_BASE,UART_CLOCK_SYSTEM);
	UARTParityModeSet(UART0_BASE,UART_CONFIG_PAR_EVEN);
	UARTConfigSetExpClk(UART0_BASE,UART_CLOCK_SYSTEM,9600,UART_CONFIG_WLEN_8|UART_CONFIG_STOP_ONE,UART_CONFIG_PAR_EVEN);

	UARTIntEnable(UART0_BASE,UART_INT_TX);
	UARTIntRegister(UART0_BASE,&txint);
	UARTEnable(UART0_BASE);
	UARTCharPut(UART0_BASE,data);
	while(1);

}

void txint(){

	UARTIntClear(UART0_BASE);
	SysCtlPeripheralEnable(SYSCTL_PERIPH_PORTF);
	GPIOPinTypeGPIOOutput(GPIO_PORTF_BASE,red);
	GPIOPinWrite(GPIO_PORTF_BASE,red,red);

}

