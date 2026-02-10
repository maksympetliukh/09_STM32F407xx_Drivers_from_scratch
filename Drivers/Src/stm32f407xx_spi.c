/*
 * stm32f407xx_spi.c
 *
 *  Created on: Feb 10, 2026
 *      Author: maksympetliukh
 */

#include "stm32f407xx.h"


/*****************************************************
 * @fn            - SPI_Init
 *
 * @brief         - This function initializes the SPI port and pin according to the specified settings in the handle structure.
 *
 * @param[in]     - pointer to the SPI handle structure which contains base address and configuration settings.
 *
 * @return        - none
 *
 * * @note        - none
 */
void SPI_Init(SPI_Handle_t *pSPI_Handle){
	//Configure the CR1 register
	uint32_t tmp = 0;

	//device mode
	tmp |= pSPI_Handle->SPI_Configs.spi_device_mode << SPI_CR1_MSTR;

	//bus configurations
	if(pSPI_Handle->SPI_Configs.spi_bus_config == SPI_BUS_CFG_FD){
		//BIDI mode should be cleared
		tmp &= ~(1 << SPI_CR1_BIDIMODE);
	}else if(pSPI_Handle->SPI_Configs.spi_bus_config == SPI_BUS_CFG_HD){
		//Enable the BIDI mode
		tmp |= (1 << SPI_CR1_BIDIMODE);
	}else if(pSPI_Handle->SPI_Configs.spi_bus_config == SPI_BUS_CFG_SIMPLEX_RXONLY){
		//BIDI mode should be cleared and RXONLY must be set
		tmp &= ~(1 << SPI_CR1_BIDIMODE);
		tmp |= (1 << SPI_CR1_RXONLY);
	}

	//SPI Serial Clock Speed
	tmp |= pSPI_Handle->SPI_Configs.spi_clock_speed << SPI_CR1_BR;

	//DFF
	tmp |= pSPI_Handle->SPI_Configs.spi_dff << SPI_CR1_DFF;

	//CPOL
	tmp |= pSPI_Handle->SPI_Configs.spi_cpol << SPI_CR1_CPOL;

	//CPHA
	tmp |= pSPI_Handle->SPI_Configs.spi_cpha << SPI_CR1_CPHA;

	pSPI_Handle->pSPIx->CR1 |= tmp;
}

/*****************************************************
 * @fn            - SPI_DeInit
 *
 * @brief         -
 *
 * @param[in]     -
 *
 * @return        - none
 *
 * * @note        - none
 */
void SPI_DeInit(SPI_REG_t *pSPIx){
	if(pSPIx == NULL){return;}

	if(pSPIx == SPI1){
		SPI1_REG_RESET();
	}else if(pSPIx == SPI2){
		SPI2_REG_RESET();
	}else if(pSPIx == SPI3){
		SPI3_REG_RESET();
	}else if(pSPIx == SPI4){
		SPI4_REG_RESET();
	}
}

/*****************************************************
 * @fn            - SPI_ClockControl
 *
 * @brief         -
 *
 * @param[in]     -
 * @param[in]     - Enable/Disable mode variable
 *
 * @return        - none
 *
 * * @note        - none
 */
void SPI_ClockControl(SPI_REG_t *pSPIx, uint8_t en_di_mode){
	if(en_di_mode == ENABLE){
		if(pSPIx == SPI1){
			RCC_SPI1_CLK_ENABLE();
		}else if(pSPIx == SPI2){
			RCC_SPI2_CLK_ENABLE();
		}else if(pSPIx == SPI3){
			RCC_SPI3_CLK_ENABLE();
		}else if(pSPIx == SPI4){
			RCC_SPI4_CLK_ENABLE();
		}
	}else if(en_di_mode == DISABLE){
		if(pSPIx == SPI1){
			RCC_SPI1_CLK_DISABLE();
		}else if(pSPIx == SPI2){
			RCC_SPI2_CLK_DISABLE();
		}else if(pSPIx == SPI3){
			RCC_SPI3_CLK_DISABLE();
		}else if(pSPIx == SPI4){
			RCC_SPI4_CLK_DISABLE();
		}
	}
}

/*****************************************************
 * @fn            - GPIO_Init
 *
 * @brief         - This function initializes the GPIO port and pin according to the specified settings in the handle structure.
 *
 * @param[in]     -
 *
 * @return        - none
 *
 * * @note        - none
 */
void SPI_Data_Transmitt(SPI_REG_t *pSPIx, uint8_t *pTX_buffer, uint32_t len){

}

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
void SPI_Data_Receive(SPI_REG_t *pSPIx, uint8_t *pRX_buffer, uint32_t len){

}

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
void SPI_IRQ_Interrupt_CFG(uint8_t IRQ_Number, uint8_t en_di_mode){

}

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
void SPI_IRQ_Priority_CFG(uint8_t IRQ_Number, uint8_t IRQ_Priority){

}

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
void SPI_IRQ_Handler(SPI_Handle_t *pHandle){

}

