/*
 * 02_Open_Drain_LED_Toggling.c
 *
 *  Created on: Feb 1, 2026
 *      Author: maksympetliukh
 */


#include "stm32f407xx.h"

void Delay(void){
	for(volatile uint32_t i = 0; i < 300000; i++){
	}
}

int main(void){
	//create a structure
	GPIO_Handle_t gpio_led;

	//Choose the required GPIO port
	gpio_led.pGPIOx = GPIOA;

	//Configure the GPIO pin
	gpio_led.GPIOx_CFG.pin_number = GPIO_PIN_6;
	gpio_led.GPIOx_CFG.pin_mode = GPIO_MODE_OUT;
	gpio_led.GPIOx_CFG.pin_speed = GPIO_OSPEED_HIGH;
	gpio_led.GPIOx_CFG.pin_op_type = GPIO_OUT_OPDRN;
	gpio_led.GPIOx_CFG.pin_pu_pd_ctrl = GPIO_PIN_PU;

	//Enable the GPIO peripheral clock
	GPIO_ClockControl(GPIOA, ENABLE);

	//Initialize the GPIO port
	GPIO_Init(&gpio_led);

	while(1){
		GPIO_TogglePin(GPIOA, GPIO_PIN_6);
		Delay();
	}
}
