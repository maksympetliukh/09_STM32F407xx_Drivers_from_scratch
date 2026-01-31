/*
 * stm32f407xx_gpio.c
 *
 *  Created on: Jan 31, 2026
 *      Author: maksympetliukh
 */


#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include "stm32f407xx_gpio.h"

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
void GPIO_Init(GPIO_Handle_t *pGPIO_Handle);

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
void GPIO_DeInit(GPIO_REG_t *pGPIOx);

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
void GPIO_ClockControl(GPIO_REG_t *pGPIOx, uint8_t EnDiMode);

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
uint8_t GPIO_ReadPin(GPIO_REG_t *pGPIOx, uint8_t PinNumber);

/*********************************************************
 * fn             - GPIO_ReadPort
 *
 * @brief         - This function reads required GPIO port.
 *
 * @param[in]     - base address of the GPIO port.
 *
 * @return        - uint16_t
 *
 * @note          - none
 */
uint16_t GPIO_ReadPort(GPIO_REG_t *pGPIOx);

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
void GPIO_WritePin(GPIO_REG_t *pGPIOx, uint8_t PinNumber, uint8_t value);

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
void GPIO_WritePort(GPIO_REG_t *pGPIOx, uint16_t value);

/**********************************************************
 * @fn            - GPIO_TogglePin
 *
 * @brief         - This function switches the GPIO pin mode (enable or disable).
 *
 * @param[in]     - GPIO port base address.
 * @param[in]     - GPIO pin number.
 *
 * @return        - none
 *
 * @note          - none
 */
void GPIO_TogglePin(GPIO_REG_t *pGPIOx, uint8_t PinNumber);

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

int main(void){

	return EXIT_SUCCESS;
}
