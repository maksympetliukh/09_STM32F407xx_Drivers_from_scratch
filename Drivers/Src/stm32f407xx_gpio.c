/*
 * stm32f407xx_gpio.c
 *
 *  Created on: Jan 31, 2026
 *      Author: maksympetliukh
 */


#include "stm32f407xx.h"

/*****************************************************
 * @fn            - GPIO_Init
 *
 * @brief         - This function initializes the GPIO port and pin according to the specified settings in the handle structure.
 *
 * @param[in]     - pointer to the GPIO handle structure which contains base address and configuration settings.
 *
 * @return        - none
 *
 * * @note        - none
 */
void GPIO_Init(GPIO_Handle_t *pGPIO_Handle){
	uint32_t tmp = 0;//temporary register
	//GPIO pin mode configuration
	if(pGPIO_Handle->GPIOx_CFG.pin_mode <= GPIO_MODE_ANALOG){ //non-interrupt mode
		//Multiplied by 2 because every pin takes 2 bit fields
		tmp = (pGPIO_Handle->GPIOx_CFG.pin_mode << (2 * pGPIO_Handle->GPIOx_CFG.pin_number));

		pGPIO_Handle->pGPIOx->MODER &= ~(0x3 << pGPIO_Handle->GPIOx_CFG.pin_number);//clearing
		pGPIO_Handle->pGPIOx->MODER |= tmp;//setting
	}else{
		if(pGPIO_Handle->GPIOx_CFG.pin_mode == GPIO_MODE_IT_FT){
			//Configure the FTSR
			EXTI->FTSR |= (1 << pGPIO_Handle->GPIOx_CFG.pin_number);

			//Clear the RTSR bit
			EXTI->RTSR &= ~(1 << pGPIO_Handle->GPIOx_CFG.pin_number);

		}else if(pGPIO_Handle->GPIOx_CFG.pin_mode == GPIO_MODE_IT_RT){
			//Configure the RTSR
			EXTI->RTSR |= (1 << pGPIO_Handle->GPIOx_CFG.pin_number);

			//Clear the FTSR bit
			EXTI->FTSR &= ~(1 << pGPIO_Handle->GPIOx_CFG.pin_number);

		}else if(pGPIO_Handle->GPIOx_CFG.pin_mode == GPIO_MODE_IT_RFT){
			//Configure both FTSR and RTSR
			EXTI->FTSR |= (1 << pGPIO_Handle->GPIOx_CFG.pin_number);
			EXTI->RTSR |= (1 << pGPIO_Handle->GPIOx_CFG.pin_number);
		}

		//Configure the GPIO port selection in EXTICR
		RCC_SYSCFG_CLK_ENABLE();


		//Enable the EXTI interrupt delivery using IMR
		EXTI->IMR |= (1 << pGPIO_Handle->GPIOx_CFG,pin_number);
	}

	tmp = 0;
	//GPIO pin output speed configuration
	tmp = (pGPIO_Handle->GPIOx_CFG.pin_speed << (2 * pGPIO_Handle->GPIOx_CFG.pin_number));

	pGPIO_Handle->pGPIOx->OSPEEDR &= ~(0x3 << pGPIO_Handle->GPIOx_CFG.pin_number);
	pGPIO_Handle->pGPIOx->OSPEEDR |= tmp;

	tmp = 0;
	//GPIO pin PUPD configuration
	tmp = (pGPIO_Handle->GPIOx_CFG.pin_pu_pd_ctrl << (2 * pGPIO_Handle->GPIOx_CFG.pin_number));

	pGPIO_Handle->pGPIOx->PUPDR &= ~(0x3 << pGPIO_Handle->GPIOx_CFG.pin_number);
	pGPIO_Handle->pGPIOx->PUPDR |= tmp;

	tmp = 0;
	//GPIO pin OUTPUTTYPE configuration
	tmp = (pGPIO_Handle->GPIOx_CFG.pin_op_type << (pGPIO_Handle->GPIOx_CFG.pin_number));

	pGPIO_Handle->pGPIOx->OTYPER &= ~(0x1 << pGPIO_Handle->GPIOx_CFG.pin_number);
	pGPIO_Handle->pGPIOx->OTYPER |= tmp;

	tmp = 0;
	//GPIO pin Alternate Functionality mode configuration
	if(pGPIO_Handle->GPIOx_CFG.pin_mode == GPIO_MODE_ALT_FN){
		uint32_t pin = pGPIO_Handle->GPIOx_CFG.pin_number;
		uint32_t af = pGPIO_Handle->GPIOx_CFG.pin_alt_func_mode;

		if(pin <= 7){
			pGPIO_Handle->pGPIOx->AFRL &= ~(0xF << (pin * 4)); //Clear the old bit field
			pGPIO_Handle->pGPIOx->AFRL |= (af << (pin * 4));
		}else if(pin <= 15){
			pGPIO_Handle->pGPIOx->AFRH &= ~(0xF << ((pin - 8) * 4));
			pGPIO_Handle->pGPIOx->AFRH |= (af << ((pin - 8) * 4));
		}
    }
}

/*****************************************************
 * @fn            - GPIO_DeInit
 *
 * @brief         - This function resets all the registers of a given GPIO port
 *
 * @param[in]     - pointer to the base address of the GPIO peripheral
 *
 * @return        - none
 *
 * @note          - none
 */
void GPIO_DeInit(GPIO_REG_t *pGPIOx){
	if(pGPIOx == NULL){return;}

	if(pGPIOx == GPIOA){
		GPIOA_REG_RESET();
	}else if(pGPIOx == GPIOB){
		GPIOB_REG_RESET();
	}else if(pGPIOx == GPIOC){
		GPIOC_REG_RESET();
	}else if(pGPIOx == GPIOD){
		GPIOD_REG_RESET();
	}else if(pGPIOx == GPIOE){
		GPIOE_REG_RESET();
	}else if(pGPIOx == GPIOF){
		GPIOF_REG_RESET();
	}else if(pGPIOx == GPIOG){
		GPIOG_REG_RESET();
	}else if(pGPIOx == GPIOH){
		GPIOH_REG_RESET();
	}else if(pGPIOx == GPIOI){
		GPIOI_REG_RESET();
	}else{return;}
}

/*****************************************************
 * @fn            - GPIO_ClockControl
 *
 * @brief         - This function enables/disables peripheral clock for the given GPIO port.
 *
 * @param[in]     - base address of the GPIO peripheral.
 * @param[in]     - ENABLE or DISABLE mode (macros).
 *
 * @return        - none
 *
 * @note          - none
 */
void GPIO_ClockControl(GPIO_REG_t *pGPIOx, uint8_t EnDiState){
	if(pGPIOx == NULL){return;}

	if(EnDiState == ENABLE){
		if(pGPIOx == GPIOA){
			RCC_GPIOA_CLK_ENABLE();
		}else if(pGPIOx == GPIOB){
			RCC_GPIOB_CLK_ENABLE();
		}else if(pGPIOx == GPIOC){
			RCC_GPIOC_CLK_ENABLE();
		}else if(pGPIOx == GPIOD){
			RCC_GPIOD_CLK_ENABLE();
		}else if(pGPIOx == GPIOE){
			RCC_GPIOE_CLK_ENABLE();
		}else if(pGPIOx == GPIOF){
			RCC_GPIOF_CLK_ENABLE();
		}else if(pGPIOx == GPIOG){
			RCC_GPIOG_CLK_ENABLE();
		}else if(pGPIOx == GPIOH){
			RCC_GPIOH_CLK_ENABLE();
		}else if(pGPIOx == GPIOI){
			RCC_GPIOI_CLK_ENABLE();
		}
	}else if(EnDiState == DISABLE){
		if(pGPIOx == GPIOA){
					RCC_GPIOA_CLK_DISABLE();
				}else if(pGPIOx == GPIOB){
					RCC_GPIOB_CLK_DISABLE();
				}else if(pGPIOx == GPIOC){
					RCC_GPIOC_CLK_DISABLE();
				}else if(pGPIOx == GPIOD){
					RCC_GPIOD_CLK_DISABLE();
				}else if(pGPIOx == GPIOE){
					RCC_GPIOE_CLK_DISABLE();
				}else if(pGPIOx == GPIOF){
					RCC_GPIOF_CLK_DISABLE();
				}else if(pGPIOx == GPIOG){
					RCC_GPIOG_CLK_DISABLE();
				}else if(pGPIOx == GPIOH){
					RCC_GPIOH_CLK_DISABLE();
				}else if(pGPIOx == GPIOI){
					RCC_GPIOI_CLK_DISABLE();
				}
	}
}


/********************************************************
 * @fn            - GPIO_ReadPin
 *
 * @brief         - This function reads the required pin number from current GPIO port.
 *
 * @param[in]     - base address of the GPIO port.
 * @param[in]     - the required pin number.
 *
 * @return        - uint8_t
 *
 * @note          - none
 */
uint8_t GPIO_ReadPin(GPIO_REG_t *pGPIOx, uint8_t PinNumber){
	uint8_t value;
	value = (uint8_t)((pGPIOx->IDR >> PinNumber) & 0x00000001);

	return value;
}

/*********************************************************
 * fn             - GPIO_ReadPort
 *
 * @brief         - This function reads required GPIO port.
 *
 * @param[in]     - base address of the GPIO port.
 *
 * @return        - 0 or 1
 *
 * @note          - none
 */
uint16_t GPIO_ReadPort(GPIO_REG_t *pGPIOx){
	uint16_t value;
	value = (uint16_t)(pGPIOx->IDR);

	return value;
}

/**********************************************************
 * @fn            - GPIO_WritePin
 *
 * @brief         - This function writes a data to the selected GPIO pin.
 *
 * @param[in]     - base address of the GPIO port.
 * @param[in]     - required pin number.
 * @param[in]     - value we write to the GPIO pin.
 *
 * @return        - none
 *
 * @note          - none
 */
void GPIO_WritePin(GPIO_REG_t *pGPIOx, uint8_t PinNumber, uint8_t value){
	if(value == GPIO_PIN_SET){
		//write 1 to the ODR at the bit field corresponding to the pin number
		pGPIOx->ODR |= (1 << PinNumber);
	}else{
		//write 0
		pGPIOx->ODR &= ~(1 << PinNumber);
	}
}

/***********************************************************
 * @fn            - GPIO_WritePort
 *
 * @brief         - This function writes a value to the required GPIO port.
 *
 * @param[in]     - base address of the GPIO port.
 * @param[in]     - value we write to the GPIO port.
 *
 * @return        - none
 *
 * @note          - none
 */
void GPIO_WritePort(GPIO_REG_t *pGPIOx, uint16_t value){
	pGPIOx->ODR = value;
}

/**********************************************************
 * @fn            - GPIO_TogglePin
 *
 * @brief         - This function switches the GPIO pin state (enable or disable).
 *
 * @param[in]     - GPIO port base address.
 * @param[in]     - GPIO pin number.
 *
 * @return        - none
 *
 * @note          - none
 */
void GPIO_TogglePin(GPIO_REG_t *pGPIOx, uint8_t PinNumber){
	pGPIOx->ODR ^= (1 << PinNumber);
}

/************************************************************
 * fn             - GPIO_IRQ_Config
 *
 * @brief         - This function allows to set interruption request parameters (Interruption Request priority, IRQ enable/disable mode).
 *
 * @param[in]     - number of the IRQ.
 * @param[in]     - IRQ priority type.
 * @param[in]     - IRQ enable/disable mode.
 */
void GPIO_IRQ_Config(uint8_t IRQ_Number, uint8_t IRQ_Priority, uint8_t EnDiMode);

/************************************************************
 * @fn            - GPIO_IRQ_Handler
 *
 * @brief         - This function handles the IRQ for the specified GPIO pin.
 *
 * @param[in]     - Specified GPIOx pin number.
 *
 * @return        - none
 *
 * @note          - none
 */
void GPIO_IRQ_Handler(uint8_t PinNumber);


