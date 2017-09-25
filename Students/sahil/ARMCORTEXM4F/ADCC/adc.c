#include<stdint.h>
#include<stdbool.h>
#include "inc/tm4c123gh6pm.h"
#include "inc/hw_types.h"
#include "inc/hw_memmap.h"
#include "driverlib/gpio.h"
#include "driverlib/sysctl.h"
#include "driverlib/adc.h"


int main(){
	uint32_t buffer[1];
	bool status;
	SysCtlPeripheralEnable(SYSCTL_PERIPH_ADC0);
	SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOD);
	GPIOPinTypeADC(GPIO_PORTD_BASE,GPIO_PIN_0);
	ADCClockConfigSet(ADC0_BASE,ADC_CLOCK_SRC_PIOSC|ADC_CLOCK_RATE_FULL,1);
	ADCSequenceStepConfigure(ADC0_BASE,0,0,ADC_CTL_CH7);
	ADCSequenceConfigure(ADC0_BASE,0,ADC_TRIGGER_ALWAYS,0);
	ADCSequenceEnable(ADC0_BASE,0);

	while(1){
		//while(ADCBusy(ADC0_BASE));
		ADCSequenceDataGet(ADC0_BASE,0,&buffer[0]);
	}

}
