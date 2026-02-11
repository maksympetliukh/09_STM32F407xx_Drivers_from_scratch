/*
 * 05_SPI_test.c
 *
 *  Created on: Feb 11, 2026
 *      Author: maksympetliukh
 */

#include "stm32f407xx.h"

 /*
 * PB14 --> SPI2_MISO
 * PB15 --> SPI2_MOSI
 * PB13 --> SPI2_SCLK
 * PB12 --> SPI2_NSS
 *
 **********************
 *
 * AF mode - 5
 */

void SPI2_GPIO_Inits(void){
	GPIO_Handle_t spi_pins;

	spi_pins.pGPIOx = GPIOB;
	spi_pins.GPIOx_CFG.pin_mode = GPIO_MODE_ALT_FN;
	spi_pins.GPIOx_CFG.pin_alt_func_mode = 5;
	spi_pins.GPIOx_CFG.pin_op_type = GPIO_OUT_PP;
	spi_pins.GPIOx_CFG.pin_pu_pd_ctrl = GPIO_NO_PUPD;
	spi_pins.GPIOx_CFG.pin_speed = GPIO_OSPEED_HIGH;

	//SCLK
	spi_pins.GPIOx_CFG.pin_number = GPIO_PIN_13;
	GPIO_Init(&spi_pins);

	//MOSI
	spi_pins.GPIOx_CFG.pin_number = GPIO_PIN_15;
	GPIO_Init(&spi_pins);

	//MISO
	spi_pins.GPIOx_CFG.pin_number = GPIO_PIN_14;
	GPIO_Init(&spi_pins);

	//NSS
	spi_pins.GPIOx_CFG.pin_number = GPIO_PIN_12;
	GPIO_Init(&spi_pins);
}

void SPI2_Inits(void){
	SPI_Handle_t spi2_handle;

	spi2_handle.pSPIx = SPI2;
	spi2_handle.SPI_Configs.spi_bus_config = SPI_BUS_CFG_FD;
	spi2_handle.SPI_Configs.spi_device_mode = SPI_DEVICE_MODE_MASTER;
	spi2_handle.SPI_Configs.spi_clock_speed = SPI_SCLK_SPEED_DIV8;
	spi2_handle.SPI_Configs.spi_dff = SPI_DFF_8B;
	spi2_handle.SPI_Configs.spi_cpol = SPI_CPOL_LOW;
	spi2_handle.SPI_Configs.spi_cpha = SPI_CPHA_LOW;
	spi2_handle.SPI_Configs.spi_ssm = SPI_SSM_EN;

	SPI_Init(&spi2_handle);

}



int main(void){

	char user_data[] = "Hello, World";

	//This function is used to initialize the GPIO pins to behave as SPI2 pins in AF mode
	SPI2_GPIO_Inits();

	//This function is used to initialize the SPI2 peripheral parameters
	SPI2_Inits();

	//SPI SSI Configuration (makes NSS signal internally high and avoids MODF error)
	SPI_SSI_CFG(SPI2, ENABLE);

	//Enable SPI2 peripheral (ONLY AFTER THE CONFIGURATION OF REQUIRED SPI!!!)
	SPI_PeripheralControl(SPI2, ENABLE);

	//Send the data
	SPI_Data_Transmit(SPI2, (uint8_t*)user_data, strlen(user_data));

	SPI_PeripheralControl(SPI2, DISABLE);

	while(1);

	return EXIT_SUCCESS;
}
