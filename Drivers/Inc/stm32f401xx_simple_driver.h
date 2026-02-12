/*
 * stm32f401xx_simple_driver.h
 *
 *  Created on: Feb 12, 2026
 *      Author: maksympetliukh
 */

#ifndef INC_STM32F401XX_SIMPLE_DRIVER_H_
#define INC_STM32F401XX_SIMPLE_DRIVER_H_

#include <stdint.h>
#include "stm32f407xx.h"

/* basic types */
typedef volatile uint32_t vuint32_t;

/* Peripheral base addresses*/
#define PERIPH_BASE      0x40000000U
#define AHB1PERIPH_BASE  (PERIPH_BASE + 0x00020000U)
#define APB1PERIPH_BASE  (PERIPH_BASE + 0x00000000U)

/* GPIOB and SPI2 Base addresses*/
#define GPIOB_BASE       (AHB1PERIPH_BASE + 0x0400U)
#define SPI2_BASE        (APB1PERIPH_BASE + 0x3800U)

/*GPIO register structure */
typedef struct {
    vuint32_t MODER;
    vuint32_t OTYPER;
    vuint32_t OSPEEDR;
    vuint32_t PUPDR;
    vuint32_t IDR;
    vuint32_t ODR;
    vuint32_t BSRR;
    vuint32_t LCKR;
    vuint32_t AFR[2];
} GPIO_RegDef_t;

/*SPI register structure*/
typedef struct {
    vuint32_t CR1;
    vuint32_t CR2;
    vuint32_t SR;
    vuint32_t DR;
    vuint32_t CRCPR;
    vuint32_t RXCRCR;
    vuint32_t TXCRCR;
    vuint32_t I2SCFGR;
    vuint32_t I2SPR;
} SPI_RegDef_t;

/* GPIOb and SPI2 macros*/
#define GPIOB   ((GPIO_RegDef_t*)GPIOB_BASE)
#define SPI2    ((SPI_RegDef_t*)SPI2_BASE)

/* GPIO pins*/
#define GPIO_PIN_12  12
#define GPIO_PIN_13  13
#define GPIO_PIN_14  14
#define GPIO_PIN_15  15

/* SPI configurations */
#define SPI_DEVICE_MODE_MASTER 1
#define SPI_DEVICE_MODE_SLAVE  0

#define SPI_SSM_EN  1
#define SPI_SSM_DI  0

#define SPI_DFF_8B 0
#define SPI_CPOL_LOW 0
#define SPI_CPHA_LOW 0

#endif /* INC_STM32F401XX_SIMPLE_DRIVER_H_ */
