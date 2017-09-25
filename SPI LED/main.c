/*
 * main.c
 */

// LED
#define BLUE_LED       GPIO_PIN_2

// SPI
#define PIN_SSI_CLK		GPIO_PIN_4
#define PIN_SSI_FSS     GPIO_PIN_5
#define PIN_SSI_RX      GPIO_PIN_6
#define PIN_SSI_TX      GPIO_PIN_7
#define GPIO_SSI_BASE   GPIO_PORTB_BASE

#include <stdint.h>
#include <stdbool.h>

#include "inc/hw_memmap.h"
#include "inc/hw_ssi.h"
#include "inc/hw_types.h"
#include "driverlib/ssi.h"
#include "driverlib/gpio.h"
#include "driverlib/pin_map.h"
#include "driverlib/sysctl.h"
#include "utils/uartstdio.h"


int main(void) {

	uint32_t dataTx[5];
	uint32_t dataRx[5];
	uint32_t index;

	// configure clock
	SysCtlClockSet(SYSCTL_SYSDIV_1 | SYSCTL_USE_PLL |SYSCTL_USE_OSC | SYSCTL_OSC_MAIN | SYSCTL_XTAL_16MHZ);

	// configure SPI 2 on GPIO Port B
	SysCtlPeripheralEnable(SYSCTL_PERIPH_SSI2);
	SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOB);

	// configure SPI 2
	GPIOPinConfigure(GPIO_PB4_SSI2CLK);
	GPIOPinConfigure(GPIO_PB5_SSI2FSS);
	GPIOPinConfigure(GPIO_PB6_SSI2RX);
	GPIOPinConfigure(GPIO_PB7_SSI2TX);
	GPIOPinTypeSSI(GPIO_SSI_BASE,PIN_SSI_CLK  |PIN_SSI_FSS |PIN_SSI_RX |PIN_SSI_TX);

	// enable SPI 2
	SSIConfigSetExpClk(SSI2_BASE, SysCtlClockGet(), SSI_FRF_MOTO_MODE_0, SSI_MODE_MASTER, 10000, 16);
	SSIEnable(SSI2_BASE);

	// configure UART0 . Rx = PA_0, Tx = PA_1
	SysCtlPeripheralEnable(SYSCTL_PERIPH_UART0);
	SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOA);
	GPIOPinConfigure(GPIO_PA0_U0RX);
	GPIOPinConfigure(GPIO_PA1_U0TX);
	GPIOPinTypeUART(GPIO_PORTA_BASE, GPIO_PIN_0 | GPIO_PIN_1);

	// configure UART 0 speed
	UARTStdioConfig(0, 115200, 16000000);

	// configure red LED
	SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOF);
	GPIOPinTypeGPIOOutput(GPIO_PORTF_BASE, BLUE_LED);

	// initialize data
	dataTx[0] = 'K';
	dataTx[1] = 'i';
	dataTx[2] = 'r';
	dataTx[3] = 't';
	dataTx[3] = 'i';

	while(1){

		// send data
		GPIOPinWrite(GPIO_PORTF_BASE, BLUE_LED, BLUE_LED);
		UARTprintf("Sent data\n");
		for(index = 0; index < 4; index++){
			SSIDataPut(SSI2_BASE, dataTx[index]);
			UARTprintf("%c", dataTx[index]);
		}
		UARTprintf("\n");
		while(SSIBusy(SSI2_BASE)) // waiting if data is sent
		{
		}

		// receive data
		UARTprintf("Received\n");
		for(index = 0; index < 4; index++) {
			SSIDataGet(SSI2_BASE, &dataRx[index]);
			//dataRx[index] &= 0x00FF;

			UARTprintf("%c", dataRx[index]);
		}
		UARTprintf("\n");
		GPIOPinWrite(GPIO_PORTF_BASE, BLUE_LED, 0);
		SysCtlDelay(8000000);
	}

}
