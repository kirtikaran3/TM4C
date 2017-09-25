#include<stdint.h>
#include<stdbool.h>
#include "inc/tm4c123gh6pm.h"
#include "inc/hw_types.h"
#include "inc/hw_memmap.h"
#include "driverlib/gpio.h"
#include "driverlib/sysctl.h"
#include "inc/hw_gpio.h"
#define button GPIO_PIN_0
#define led1 GPIO_PIN_1
#define led2 GPIO_PIN_2
int main(){

	/*SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOF);

	HWREG(GPIO_PORTF_BASE+GPIO_O_LOCK)=GPIO_LOCK_KEY;
	HWREG(GPIO_PORTF_BASE+GPIO_O_CR)=0X1;

	GPIOPinTypeGPIOOutput(GPIO_PORTF_BASE,led1|led2);
	GPIOPinTypeGPIOInput(GPIO_PORTF_BASE,button);

	GPIOPadConfigSet(GPIO_PORTF_BASE,button,GPIO_STRENGTH_2MA,GPIO_PIN_TYPE_STD_WPU);
	GPIOPinWrite(GPIO_PORTF_BASE,led2,led2);
	while(1){
		if(GPIOPinRead(GPIO_PORTF_BASE,button)==0){ GPIOPinWrite(GPIO_PORTF_BASE,led1,led1);  }
		else
			GPIOPinWrite(GPIO_PORTF_BASE,led1,!led1);
	}

*/
	SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOD);
	SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOF);

	GPIOPinTypeGPIOOutput(GPIO_PORTF_BASE,led1|led2);
	GPIOPinTypeGPIOInput(GPIO_PORTD_BASE,button);
	GPIOPadConfigSet(GPIO_PORTD_BASE,button,GPIO_STRENGTH_2MA,GPIO_PIN_TYPE_STD_WPU);
	while(1){
			if(GPIOPinRead(GPIO_PORTD_BASE,button)==0){ GPIOPinWrite(GPIO_PORTF_BASE,led1|led2,led1|led2);  }
			else
				GPIOPinWrite(GPIO_PORTF_BASE,led1|led2,!led1|!led2);
		}

 }
