#include<stdint.h>
#include<stdbool.h>
#include "inc/tm4c123gh6pm.h"
#include "inc/hw_types.h"
#include "inc/hw_memmap.h"
#include "driverlib/gpio.h"
#include "driverlib/gpio.c"
#include "driverlib/sysctl.h"
#include "driverlib/adc.h"
#include "driverlib/uart.h"
#include "driverlib/uart.c"
#include "utils/uartstdio.h"
#include "driverlib/pin_map.h"
#define red GPIO_PIN_1
void txint();
int main(void) {
	char data='h';
	SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOF);
	SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOA);
	SysCtlPeripheralEnable(SYSCTL_PERIPH_UART0);

	GPIOPinTypeGPIOOutput(GPIO_PORTF_BASE,red);
	GPIOPinTypeUART(GPIO_PORTA_BASE,GPIO_PIN_0|GPIO_PIN_1);
	GPIOPinConfigure(GPIO_PA0_U0RX);
	GPIOPinConfigure(GPIO_PA1_U0TX);

	//UARTClockSourceSet(UART0_BASE,UART_CLOCK_SYSTEM);
	//UARTParityModeSet(UART0_BASE,UART_CONFIG_PAR_NONE);
	UARTConfigSetExpClk(UART0_BASE,SysCtlClockGet(),9600,UART_CONFIG_WLEN_8|UART_CONFIG_STOP_ONE|UART_CONFIG_PAR_NONE);

	UARTIntEnable(UART0_BASE,UART_INT_TX);
	UARTIntRegister(UART0_BASE,&txint);
	UARTEnable(UART0_BASE);

	UARTCharPut(UART0_BASE,'s');


}

void txint(){

	UARTIntClear(UART0_BASE,UART_INT_TX);
	GPIOPinWrite(GPIO_PORTF_BASE,red,red);
	UARTCharPut(UART0_BASE,'g');
///	SysCtlDelay(800000000);

}

