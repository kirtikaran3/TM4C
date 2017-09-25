/*
 * ledbuttonpatern.c
 *
 *  Created on: 16-Dec-2016
 *      Author: HP
 */
#include<stdint.h>
#include<stdbool.h>
#include "inc/tm4c123gh6pm.h"
#include "inc/hw_types.h"
#include "inc/hw_memmap.h"
#include "driverlib/gpio.h"
#include "driverlib/sysctl.h"
#include "inc/hw_gpio.h"

#define RED GPIO_PIN_1
#define GREEN GPIO_PIN_2
#define BLUE GPIO_PIN_3
#define SWITCH_1 GPIO_PIN_0
#define SWITCH_2 GPIO_PIN_4

void pattern1();
void pattern2();
void pattern3();
void pattern4();
int main(void){

	SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOF);

	HWREG(GPIO_PORTF_BASE+GPIO_O_LOCK)=GPIO_LOCK_KEY;
	HWREG(GPIO_PORTF_BASE+GPIO_O_CR)=0X1;

	GPIOPinTypeGPIOInput(GPIO_PORTF_BASE,SWITCH_1|SWITCH_2);
	GPIOPadConfigSet(GPIO_PORTF_BASE,SWITCH_1|SWITCH_2,GPIO_STRENGTH_2MA,GPIO_PIN_TYPE_STD_WPU);
	//GPIOPadConfigSet(GPIO_PORTF_BASE,SWITCH_2,GPIO_STRENGTH_2MA,GPIO_PIN_TYPE_STD_WPU);

	GPIOPinTypeGPIOOutput(GPIO_PORTF_BASE,RED|GREEN|BLUE);

	while(1){

			if(GPIOPinRead(GPIO_PORTF_BASE,SWITCH_1)==0&&GPIOPinRead(GPIO_PORTF_BASE,SWITCH_2)==1){
			pattern1();
			}

			if(GPIOPinRead(GPIO_PORTF_BASE,SWITCH_1)==1&&GPIOPinRead(GPIO_PORTF_BASE,SWITCH_2)==0){
			pattern2();
		}

			if(!GPIOPinRead(GPIO_PORTF_BASE,SWITCH_1)==1&&GPIOPinRead(GPIO_PORTF_BASE,SWITCH_2)==1){
			pattern3();
		}

			if(GPIOPinRead(GPIO_PORTF_BASE,SWITCH_1)==0&&GPIOPinRead(GPIO_PORTF_BASE,SWITCH_2)==0){
			pattern4();
		}
	}
}
void pattern1(){

	GPIOPinWrite(GPIO_PORTF_BASE,RED|GREEN|BLUE,RED|GREEN|BLUE);
	SysCtlDelay(8000000);
	GPIOPinWrite(GPIO_PORTF_BASE,RED|GREEN|BLUE,!RED|!GREEN|!BLUE);
	SysCtlDelay(8000000);

}

void pattern2(){

	GPIOPinWrite(GPIO_PORTF_BASE,RED|GREEN|BLUE,RED|!GREEN|!BLUE);
	SysCtlDelay(8000000/100);
	GPIOPinWrite(GPIO_PORTF_BASE,RED|GREEN|BLUE,!RED|GREEN|!BLUE);
	SysCtlDelay(8000000/100);
	GPIOPinWrite(GPIO_PORTF_BASE,RED|GREEN|BLUE,!RED|!GREEN|BLUE);
	SysCtlDelay(8000000/100);
}

void pattern3(){

	GPIOPinWrite(GPIO_PORTF_BASE,RED|GREEN|BLUE,RED|GREEN|!BLUE);
	SysCtlDelay(8000000/100);
	GPIOPinWrite(GPIO_PORTF_BASE,RED|GREEN|BLUE,!RED|!GREEN|!BLUE);
	SysCtlDelay(8000000/100);
	GPIOPinWrite(GPIO_PORTF_BASE,RED|GREEN|BLUE,!RED|GREEN|BLUE);
	SysCtlDelay(8000000/100);
	GPIOPinWrite(GPIO_PORTF_BASE,RED|GREEN|BLUE,!RED|!GREEN|!BLUE);
	SysCtlDelay(8000000/100);

}

void pattern4(){

	GPIOPinWrite(GPIO_PORTF_BASE,RED|GREEN|BLUE,!RED|!GREEN|BLUE);
	SysCtlDelay(8000000/100);
	GPIOPinWrite(GPIO_PORTF_BASE,RED|GREEN|BLUE,!RED|!GREEN|!BLUE);
	SysCtlDelay(8000000/100);
	GPIOPinWrite(GPIO_PORTF_BASE,RED|GREEN|BLUE,RED|!GREEN|BLUE);
	SysCtlDelay(8000000/100);
	GPIOPinWrite(GPIO_PORTF_BASE,RED|GREEN|BLUE,!RED|!GREEN|!BLUE);
	SysCtlDelay(8000000/100);

}



