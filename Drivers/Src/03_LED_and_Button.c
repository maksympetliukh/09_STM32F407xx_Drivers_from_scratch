/*
 * 03_LED_and_Button.c
 *
 *  Created on: Feb 1, 2026
 *      Author: maksympetliukh
 */

#include "stm32f407xx.h"

void Delay(void){
	for(volatile uint32_t i = 0; i < 500000; i++){
	}
}

int main(void){
	GPIO_Handle_t gpio_led, gpio_button;

	gpio_led.pGPIOx = GPIOA;

	gpio_led.GPIOx_CFG.pin_number = GPIO_PIN_7;
	gpio_led.GPIOx_CFG.pin_mode = GPIO_MODE_OUT;
	gpio_led.GPIOx_CFG.pin_speed = GPIO_OSPEED_HIGH;
	gpio_led.GPIOx_CFG.pin_op_type = GPIO_OUT_OPDRN;
	gpio_led.GPIOx_CFG.pin_pu_pd_ctrl = GPIO_PIN_PU;

	GPIO_ClockControl(GPIOA, ENABLE);

	GPIO_Init(&gpio_led);

	gpio_button.pGPIOx = GPIOE;

	gpio_button.GPIOx_CFG.pin_number = GPIO_PIN_3;
	gpio_button.GPIOx_CFG.pin_mode = GPIO_MODE_IN;
	gpio_button.GPIOx_CFG.pin_speed = GPIO_OSPEED_HIGH;
	gpio_button.GPIOx_CFG.pin_pu_pd_ctrl = GPIO_PIN_PU;

	GPIO_ClockControl(GPIOE, ENABLE);
	GPIO_Init(&gpio_button);

	while(1){
		if(GPIO_ReadPin(GPIOE, GPIO_PIN_3) == BUTTON_PRESSED){
            Delay();

			GPIO_TogglePin(GPIOA, GPIO_PIN_7);
		}
	}

	return EXIT_SUCCESS;
}
