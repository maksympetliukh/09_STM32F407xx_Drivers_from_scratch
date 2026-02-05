/*
 * 04_Interrupt_Handling.c
 *
 *  Created on: Feb 5, 2026
 *      Author: maksympetliukh
 */


#include "stm32f407xx.h"

void Delay(void){
	for(uint32_t i = 0; i < 500000; i++);
}

int main(void){
	/*LED configuration*/
	GPIO_Handle_t gpio_led;
	//set every structure field value as 0 before configuring
	memset(&gpio_led, 0, sizeof(gpio_led));

	gpio_led.pGPIOx = GPIOA;
	gpio_led.GPIOx_CFG.pin_number = GPIO_PIN_6;
	gpio_led.GPIOx_CFG.pin_mode = GPIO_MODE_OUT;
	gpio_led.GPIOx_CFG.pin_speed = GPIO_OSPEED_LOW;
	gpio_led.GPIOx_CFG.pin_op_type = GPIO_OUT_PP;
	gpio_led.GPIOx_CFG.pin_pu_pd_ctrl = GPIO_NO_PUPD;

	GPIO_ClockControl(GPIOA, ENABLE);
	GPIO_Init(&gpio_led);

	/*Button configuration*/
	GPIO_Handle_t gpio_btn;
	memset(&gpio_btn, 0, sizeof(gpio_btn));

	gpio_btn.pGPIOx = GPIOE;
	gpio_btn.GPIOx_CFG.pin_number = GPIO_PIN_4;
	gpio_btn.GPIOx_CFG.pin_mode = GPIO_MODE_IT_FT;
	gpio_btn.GPIOx_CFG.pin_speed = GPIO_OSPEED_HIGH;
	gpio_btn.GPIOx_CFG.pin_pu_pd_ctrl = GPIO_PIN_PU;

	GPIO_ClockControl(GPIOE, ENABLE);
	GPIO_Init(&gpio_btn);

	GPIO_WritePin(GPIOA, GPIO_PIN_6, SET);
	/*IRQ configurations*/
	GPIO_IRQ_Priority_CFG(IRQ_EXTI4, 5);
	GPIO_IRQ_Interrupt_CFG(IRQ_EXTI4, ENABLE);

	while(1);


}

void EXTI4_IRQHandler(void){
	Delay();

	GPIO_IRQ_Handler(GPIO_PIN_4);

	GPIO_TogglePin(GPIOA, GPIO_PIN_6);
}
