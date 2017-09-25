#include<stdint.h>
#include<stdbool.h>
#include "inc/tm4c123gh6pm.h"
#include "inc/hw_types.h"
#include "inc/hw_memmap.h"
#include "driverlib/gpio.h"
#include "driverlib/gpio.c"
#include "driverlib/sysctl.h"
#include "driverlib/pin_map.h"
#include "driverlib/i2c.c"
#include "driverlib/i2c.h"
#include "driverlib/uart.h"
#include "driverlib/uart.c"
#include "utils/uartstdio.h"

#define red GPIO_PIN_1
uint32_t buff;
int main(void) {

	SysCtlPeripheralEnable(GPIO_PORTD_BASE);
	SysCtlPeripheralEnable(GPIO_PORTF_BASE);
	SysCtlPeripheralEnable(I2C3_BASE);

	SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOA);
	SysCtlPeripheralEnable(SYSCTL_PERIPH_UART0);
	GPIOPinTypeUART(GPIO_PORTA_BASE,GPIO_PIN_0|GPIO_PIN_1);
	GPIOPinConfigure(GPIO_PA0_U0RX);
	GPIOPinConfigure(GPIO_PA1_U0TX);

	UARTConfigSetExpClk(UART0_BASE,SysCtlClockGet(),9600,UART_CONFIG_WLEN_8|UART_CONFIG_STOP_ONE|UART_CONFIG_PAR_NONE);
	GPIOPinTypeI2C(GPIO_PORTD_BASE,GPIO_PIN_1);
	GPIOPinTypeI2CSCL(GPIO_PORTD_BASE,GPIO_PIN_0);
	GPIOPinConfigure(GPIO_PD0_I2C3SCL);
	GPIOPinConfigure(GPIO_PD1_I2C3SDA);

	UARTEnable(UART0_BASE);
//	UARTCharPut(UART0_BASE,'h');


	UARTCharPut(UART0_BASE,'h');

	GPIOPinTypeGPIOOutput(GPIO_PORTF_BASE,red);
	I2CSlaveEnable(I2C3_BASE);
	I2CSlaveInit(I2C3_BASE,0X40);

	while(1){
		while(I2CSlaveStatus(I2C3_BASE)==I2C_SLAVE_ACT_NONE);

		if(I2CSlaveStatus(I2C3_BASE)==I2C_SLAVE_ACT_RREQ){
				buff=I2CSlaveDataGet(I2C3_BASE);
				UARTCharPut(UART0_BASE,buff);
				if(buff=='S'){
					GPIOPinWrite(GPIO_PORTF_BASE,red,red);
				}
			}

	}
		return 0;
}
