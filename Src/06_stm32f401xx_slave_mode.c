/*
 * 06_stm32f401xx_slave_mode.c
 *
 *  Created on: Feb 12, 2026
 *      Author: maksympetliukh
 */

#include "stm32f401xx_simple_driver.h"

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

    //slave mode
    spi2_handle.SPI_Configs.spi_device_mode = SPI_DEVICE_MODE_SLAVE;

    //NSS in slave mode is hardware
    spi2_handle.SPI_Configs.spi_ssm = SPI_SSM_DI;

    //This parameters must be equal to the master
    spi2_handle.SPI_Configs.spi_dff  = SPI_DFF_8B;
    spi2_handle.SPI_Configs.spi_cpol = SPI_CPOL_LOW;
    spi2_handle.SPI_Configs.spi_cpha = SPI_CPHA_LOW;

    SPI_Init(&spi2_handle);
}

int main(void){

	uint8_t data;

	//This function is used to initialize the GPIO pins to behave as SPI2 pins in AF mode
	SPI2_GPIO_Inits();

	//This function is used to initialize the SPI2 peripheral parameters
	SPI2_Inits();

	//Enable SPI2 peripheral (ONLY AFTER THE CONFIGURATION OF REQUIRED SPI!!!)
	SPI_PeripheralControl(SPI2, ENABLE);

	//Receive the data
	while(1){
	SPI_Data_Receive(SPI2, &data, 1);
	}

	return EXIT_SUCCESS;
}
