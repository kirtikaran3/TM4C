#include<stdint.h>
#include<stdbool.h>
#include "inc/tm4c123gh6pm.h"
#include "inc/hw_types.h"
#include "inc/hw_memmap.h"
#include "driverlib/gpio.h"
#include "driverlib/gpio.c"
#include "driverlib/sysctl.h"
#include "driverlib/i2c.c"
#include "driverlib/i2c.h"
#include "driverlib/pin_map.h"
int main(void) {
	SysCtlPeripheralEnable(GPIO_PORTD_BASE);
	SysCtlPeripheralEnable(GPIO_PORTF_BASE);
	SysCtlPeripheralEnable(I2C3_BASE);

	GPIOPinTypeI2C(GPIO_PORTD_BASE,GPIO_PIN_1);
	GPIOPinTypeI2CSCL(GPIO_PORTD_BASE,GPIO_PIN_0);
	GPIOPinConfigure(GPIO_PD0_I2C3SCL);
	GPIOPinConfigure(GPIO_PD1_I2C3SDA);

	I2CMasterInitExpClk(I2C3_BASE,SysCtlClockGet(),0);
	I2CMasterEnable(I2C3_BASE);
	I2CMasterSlaveAddrSet(I2C3_BASE,0X40,0);
	I2CMasterDataPut(I2C3_BASE,'S');
	I2CMasterControl(I2C3_BASE,I2C_MASTER_CMD_SINGLE_SEND);
	while(!I2CMasterBusy(I2C3_BASE));
	return 0;
}
