/*
 * main.c
 */
#include <stdint.h>
#include <stdbool.h>

#include "inc/hw_memmap.h"
#include "inc/hw_types.h"
#include "driverlib/gpio.h"
#include "driverlib/debug.h"
#include "driverlib/sysctl.h"
#include "driverlib/adc.h"

int main(void) {

	uint32_t analogvalue[1];

	SysCtlClockSet(SYSCTL_SYSDIV_10 | SYSCTL_USE_PLL | SYSCTL_OSC_MAIN | SYSCTL_XTAL_16MHZ);
	SysCtlPeripheralEnable(SYSCTL_PERIPH_ADC0);
	SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOE);
	GPIOPinTypeADC(GPIO_PORTE_BASE,GPIO_PIN_3);

	ADCSequenceConfigure(ADC0_BASE,3,ADC_TRIGGER_PROCESSOR,0);
	ADCSequenceStepConfigure(ADC0_BASE,3,0,ADC_CTL_CH0|ADC_CTL_IE|ADC_CTL_END);
	ADCSequenceEnable(ADC0_BASE,3);
	ADCIntClear(ADC0_BASE,3);

	while(1){

		ADCProcessorTrigger(ADC0_BASE,3);
		while(!ADCIntStatus(ADC0_BASE,3,false)){

		}
		ADCIntClear(ADC0_BASE,3);
		ADCSequenceDataGet(ADC0_BASE,3,analogvalue);
		SysCtlDelay(SysCtlClockGet()/120);
	}
	
	//return 0;
}
