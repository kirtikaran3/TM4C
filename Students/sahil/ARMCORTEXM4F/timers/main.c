#include<stdint.h>
#include<stdbool.h>
#include "inc/tm4c123gh6pm.h"
#include "inc/hw_types.h"
#include "inc/hw_memmap.h"
#include "driverlib/gpio.h"
#include "driverlib/sysctl.h"
#include "driverlib/timer.h"
#include "driverlib/interrupt.h"
#define led GPIO_PIN_2
#define led1 GPIO_PIN_3
void func(void);
int i=0;
int status;
int main(void) {
	uint32_t val=100000000/5;

	//SysCtlClockFreqSet(SYSCTL_OSC_INT|SYSCTL_USE_OSC,16000000);
	//SysCtlClockSet(SYSCTL_SYSDIV_5|SYSCTL_USE_PLL|SYSCTL_XTAL_16MHZ|SYSCTL_OSC_MAIN);
	//val=SysCtlClockGet()/10;
	SysCtlPeripheralEnable(SYSCTL_PERIPH_TIMER0);
	SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOF);
	GPIOPinTypeGPIOOutput(GPIO_PORTF_BASE,led|led1);
	TimerConfigure(TIMER0_BASE,TIMER_CFG_A_PERIODIC);
	TimerLoadSet(TIMER0_BASE,TIMER_A,val);
	IntEnable(INT_TIMER0A);
	TimerIntEnable(TIMER0_BASE,TIMER_TIMA_TIMEOUT);
	IntMasterEnable();
	TimerIntRegister(TIMER0_BASE,TIMER_A,&func);
	TimerEnable(TIMER0_BASE,TIMER_A);
	return 0;
}

void func(void){

	i++;
	status=GPIOPinRead(GPIO_PORTF_BASE,led);
	TimerIntClear(TIMER0_BASE,TIMER_TIMA_TIMEOUT);
	if(status==0){
		GPIOPinWrite(GPIO_PORTF_BASE,led,led);
		status=1;
	}
	else{

		GPIOPinWrite(GPIO_PORTF_BASE,led,!led);
		status=0;
	}


}

