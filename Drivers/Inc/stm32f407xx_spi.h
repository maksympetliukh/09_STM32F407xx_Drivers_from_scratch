/*
 * stm32f407xx_spi.h
 *
 *  Created on: Feb 10, 2026
 *      Author: maksympetliukh
 */

#ifndef INC_STM32F407XX_SPI_H_
#define INC_STM32F407XX_SPI_H_

#include "stm32f407xx.h"
/*
 * Configuration structure for SPIx peripheral
 */
typedef struct{
	uint8_t spi_device_mode;
	uint8_t spi_bus_config;
	uint8_t spi_clock_speed;
	uint8_t spi_dff;
	uint8_t spi_cpol;
	uint8_t spi_cpha;
	uint8_t spi_ssm;
}SPI_CFG_t;

/*
 * @spi_devise_mode macros
 */
#define SPI_DEVICE_MODE_MASTER 1
#define SPI_DEVICE_MODE_SLAVE  0

/*
 * @spi_bus_config macros
 */
#define SPI_BUS_CFG_FD               1
#define SPI_BUS_CFG_HD               2
#define SPI_BUS_CFG_SIMPLEX_RXONLY   3

/*
 * @spi_clock_speed macros
 */
#define SPI_SCLK_SPEED_DIV2      0
#define SPI_SCLK_SPEED_DIV4      1
#define SPI_SCLK_SPEED_DIV8      2
#define SPI_SCLK_SPEED_DIV16     3
#define SPI_SCLK_SPEED_DIV32     4
#define SPI_SCLK_SPEED_DIV64     5
#define SPI_SCLK_SPEED_DIV128    6
#define SPI_SCLK_SPEED_DIV256    7

/*
 * @spi_dff macros
 */
#define SPI_DFF_8B   0
#define SPI_DFF_16B  1

/*
 *@spi_cpol macros
 */
#define SPI_CPOL_HIGH 1
#define SPI_CPOL_LOW  0

/*
 *@spi_cpha macros
 */
#define SPI_CPHA_HIGH 1
#define SPI_CPHA_LOW  0

/*
 * @spi_ssm macros
 */
#define SPI_SSM_EN 1
#define SPI_SSM_DI 0

/*
 * Handle structure for SPIx peripheral
 */
typedef struct{
	SPI_REG_t *pSPIx;
	SPI_CFG_t SPI_Configs;
}SPI_Handle_t;


void SPI_Init(SPI_Handle_t *pSPI_Handle);
void SPI_DeInit(SPI_REG_t *pSPIx);
void SPI_ClockControl(SPI_REG_t *pSPIx, uint8_t en_di_mode);
void SPI_Data_Transmitt(SPI_REG_t *pSPIx, uint8_t *pTX_buffer, uint32_t len);
void SPI_Data_Receive(SPI_REG_t *pSPIx, uint8_t *pRX_buffer, uint32_t len);
void SPI_IRQ_Interrupt_CFG(uint8_t IRQ_Number, uint8_t en_di_mode);
void SPI_IRQ_Priority_CFG(uint8_t IRQ_Number, uint8_t IRQ_Priority);
void SPI_IRQ_Handler(SPI_Handle_t *pHandle);


#endif /* INC_STM32F407XX_SPI_H_ */
