
#define GREEN_LED       GPIO_PIN_3

// I2C
#define PIN_I2C_SCL		GPIO_PIN_0
#define PIN_I2C_SDA     GPIO_PIN_1
#define GPIO_I2C_BASE   GPIO_PORTD_BASE

// PCF8591 AD/DA module
#define Tiva2 (0x76 >> 1)  // Device address


#include <stdarg.h>
#include <stdbool.h>
#include <stdint.h>

#include "inc/hw_i2c.h"
#include "inc/hw_memmap.h"
#include "inc/hw_types.h"
#include "inc/hw_gpio.h"
#include "driverlib/i2c.h"
#include "driverlib/sysctl.h"
#include "driverlib/gpio.h"
#include "driverlib/pin_map.h"


uint32_t Tiva2Routine(uint8_t channel){
    // set slave address
    I2CMasterSlaveAddrSet(I2C3_BASE, Tiva2, false);
    //specify register to be read
    I2CMasterDataPut(I2C3_BASE, channel);
    //send control byte and register address byte to slave device
    I2CMasterControl(I2C3_BASE, I2C_MASTER_CMD_BURST_SEND_START);
    //wait for MCU to finish transaction
    while(I2CMasterBusy(I2C3_BASE));

    ////////// read two byte from PCF8591 module
    // read from slave device
    I2CMasterSlaveAddrSet(I2C3_BASE, Tiva2, true);

    // read first byte
    I2CMasterControl(I2C3_BASE, I2C_MASTER_CMD_BURST_RECEIVE_START);
    while(I2CMasterBusy(I2C3_BASE));
    I2CMasterDataGet(I2C3_BASE);
    // read second byte
    I2CMasterControl(I2C3_BASE, I2C_MASTER_CMD_BURST_RECEIVE_FINISH);
	while(I2CMasterBusy(I2C3_BASE));

    return I2CMasterDataGet(I2C3_BASE);
}

int main(void) {

	// configure clock
	SysCtlClockSet(SYSCTL_SYSDIV_1 | SYSCTL_USE_PLL |SYSCTL_USE_OSC | SYSCTL_OSC_MAIN | SYSCTL_XTAL_16MHZ);
	
	/////////////////////////// initialize I2C
	//enable I2C module 3
	SysCtlPeripheralEnable(SYSCTL_PERIPH_I2C3);
	//reset module
	SysCtlPeripheralReset(SYSCTL_PERIPH_I2C3);

	//enable GPIO peripheral that contains I2C 3
	SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOD);

	// Configure I2C3 functions on port D0 and D1.
	GPIOPinConfigure(GPIO_PD0_I2C3SCL);
	GPIOPinConfigure(GPIO_PD1_I2C3SDA);

	// Select the I2C function for these pins.
	GPIOPinTypeI2CSCL(GPIO_I2C_BASE, PIN_I2C_SCL);
	GPIOPinTypeI2C(GPIO_I2C_BASE, PIN_I2C_SDA);

	// Enable and initialize the I2C3 master module.
	I2CMasterInitExpClk(I2C3_BASE, SysCtlClockGet(), false);
	/////////////////////////// end of I2C initialization



	// configure green LED
	SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOF);
	GPIOPinTypeGPIOOutput(GPIO_PORTF_BASE, GREEN_LED);

	while(1){

		GPIOPinWrite(GPIO_PORTF_BASE, GREEN_LED, GREEN_LED);

		SysCtlDelay(8000000);

		GPIOPinWrite(GPIO_PORTF_BASE, GREEN_LED, 0);

		SysCtlDelay(8000000);
	}
}
