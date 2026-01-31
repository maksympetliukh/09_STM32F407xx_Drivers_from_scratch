/*
 * stm32f407xx_gpio.h
 *
 *  Created on: Jan 31, 2026
 *      Author: maksympetliukh
 */

#ifndef INC_STM32F407XX_GPIO_H_
#define INC_STM32F407XX_GPIO_H_

#include "stm32f407xx.h"

/*
 * GPIO pin configuration structure
 */
typedef struct {
	uint8_t pin_number;
	uint8_t pin_mode;
	uint8_t pin_speed;
	uint8_t pin_pu_pd_ctrl;
	uint8_t pin_op_type;
	uint8_t pin_alt_func_mode;
}GPIO_PinConfig_t;

/*
 * GPIO handle structure
 */
typedef struct {
	GPIO_REG_t *pGPIOx; //This pointer holds the base address of the GPIO port to which the pin belongs
	GPIO_PinConfig_t GPIOx_CFG; //This structure includes GPIO pin configuration settings

}GPIO_Handle_t;

/*
 * GPIO APIs
 */
void GPIO_Init(GPIO_Handle_t *pGPIO_Handle);
void GPIO_DeInit(GPIO_REG_t *pGPIOx);
void GPIO_ClockControl(GPIO_REG_t *pGPIOx, uint8_t EnDiMode);
uint8_t GPIO_ReadPin(GPIO_REG_t *pGPIOx, uint8_t PinNumber);
uint16_t GPIO_ReadPort(GPIO_REG_t *pGPIOx);
void GPIO_WritePin(GPIO_REG_t *pGPIOx, uint8_t PinNumber, uint8_t value);
void GPIO_WritePort(GPIO_REG_t *pGPIOx, uint16_t value);
void GPIO_TogglePin(GPIO_REG_t *pGPIOx, uint8_t PinNumber);
void GPIO_IRQ_Config(uint8_t IRQ_Number, uint8_t IRQ_Priority, uint8_t EnDiMode);
void GPIO_IRQ_Handler(uint8_t PinNumber);


#endif /* INC_STM32F407XX_GPIO_H_ */
