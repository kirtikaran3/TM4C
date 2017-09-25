#include<stdint.h>
#include<stdbool.h>
#include "inc/tm4c123gh6pm.h"
#include "inc/hw_types.h"
#include "inc/hw_memmap.h"
#include "driverlib/gpio.h"
#include "driverlib/gpio.c"
#include "driverlib/sysctl.h"
//#include "driverlib/adc.h"
#include "driverlib/uart.h"
#include "driverlib/uart.c"
#include "utils/uartstdio.h"
#include "driverlib/pin_map.h"
#define red GPIO_PIN_1
void rxint();
int32_t buff;

int main(void) {

	//SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOF|SYSCTL_PERIPH_GPIOA|SYSCTL_PERIPH_UART0);
	SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOF);
	SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOB);
	SysCtlPeripheralEnable(SYSCTL_PERIPH_UART1);

	GPIOPinTypeUART(GPIO_PORTB_BASE,GPIO_PIN_0|GPIO_PIN_1);
	GPIOPinTypeGPIOOutput(GPIO_PORTF_BASE,red);
	GPIOPinConfigure(GPIO_PB0_U1RX);
	GPIOPinConfigure(GPIO_PB1_U1TX);

	UARTConfigSetExpClk(UART1_BASE,SysCtlClockGet(),9600,UART_CONFIG_WLEN_8|UART_CONFIG_STOP_ONE|UART_CONFIG_PAR_NONE);
	UARTIntEnable(UART1_BASE,UART_INT_RX);
	//UARTIntRegister(UART0_BASE,&rxint);

	UARTEnable(UART1_BASE);
	UARTCharPut(UART1_BASE,'h');

	while(1){
		//while(!UARTCharsAvail(UART0_BASE));
		//buff=UARTCharGet(UART0_BASE);
		UARTCharPut(UART1_BASE,UARTCharGet(UART1_BASE));

	}

	return 0;
}
void rxint(){

	buff=UARTCharGet(UART1_BASE);
	UARTCharPut(UART1_BASE,buff);
}

