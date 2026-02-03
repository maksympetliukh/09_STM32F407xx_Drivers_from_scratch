/*
 * stm32f407xx.h
 *
 *  Created on: Jan 31, 2026
 *      Author: maksympetliukh
 */

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include "stm32f407xx_gpio.h"

#ifndef INC_STM32F407XX_H_
#define INC_STM32F407XX_H_

/*
 * Base addresses of FLASH and SRAM memories
 */
#define FLASH_BASE 0x08000000UL /*512 KB read-only memory*/
#define SRAM1_BASE 0x20000000UL /*112 KB SRAM1*/
#define SRAM2_BASE 0x2001C000UL /*16  KB SRAM2*/
#define ROM_BASE   FLASH_BASE   /*Alias*/
#define SRAM_BASE  SRAM1_BASE   /*General SRAM*/

/*
 * AHBx and APBx bus peripheral base addresses
 */
#define PERIPH_BASE     0x40000000UL
#define APB1PERIPH_BASE PERIPH_BASE  /*APB1*/
#define APB2PERIPH_BASE 0x40010000UL /*APB2*/
#define AHB1PERIPH_BASE 0x40020000UL /*AHB1*/
#define AHB2PERIPH_BASE 0x50000000UL /*AHB2*/
#define RCC_BASE        0x40023800UL /*RCC*/

/*
 * AHB1 peripherals
 */
#define GPIOA_BASE 0x40020000UL /*GPIOA port base address*/
#define GPIOB_BASE 0x40020400UL /*GPIOB port base address*/
#define GPIOC_BASE 0x40020800UL /*GPIOC port base address*/
#define GPIOD_BASE 0x40020C00UL /*GPIOD port base address*/
#define GPIOE_BASE 0x40021000UL /*GPIOE port base address*/
#define GPIOF_BASE 0x40021400UL /*GPIOF port base address*/
#define GPIOG_BASE 0x40021800UL /*GPIOG port base address*/
#define GPIOH_BASE 0x40021C00UL /*GPIOH port base address*/
#define GPIOI_BASE 0x40022000UL /*GPIOI port base address*/

/*
 * APB1 peripherals
 */
#define I2C1_BASE   0x40005400UL /*I2C1*/
#define I2C2_BASE   0x40005800UL /*I2C2*/
#define I2C3_BASE   0x40005C00UL /*I2C3*/
#define SPI2_BASE   0x40003800UL /*SPI2/I2S2*/
#define SPI3_BASE   0x40003C00UL /*SPI3/I2S3*/
#define USART2_BASE 0x40004400UL /*USART2*/
#define USART3_BASE 0x40004800UL /*USART3*/
#define UART4_BASE  0x40004C00UL /*UART4*/
#define UART5_BASE  0x40005000UL /*UART5*/

/*
 * APB2 peripherals
 */
#define SPI1_BASE    0x40013000UL /*SPI1*/
#define USART1_BASE  0x40011000UL /*USART1*/
#define USART6_BASE  0x40011400UL /*USART6*/
#define EXTI_BASE    0x40013C00UL /*EXTI*/
#define SYSCFG_BASE 0x40013800UL  /*SYSCFG*/

/*
 * Peripheral register structure for GPIO
 */
typedef struct{
	uint32_t volatile MODER;   /*GPIO port mode register                        offset: 0x00*/
	uint32_t volatile OTYPER;  /*GPIO port output type register                 offset: 0x04*/
	uint32_t volatile OSPEEDR; /*GPIO port output speed register                offset: 0x08*/
	uint32_t volatile PUPDR;   /*GPIO port pull-up/pull-down register           offset: 0x0C*/
	uint32_t volatile IDR;     /*GPIO port input data register                  offset: 0x10*/
	uint32_t volatile ODR;     /*GPIO port output data register         		offset: 0x14*/
	uint32_t volatile BSRR;    /*GPIO port bit set/reset register               offset: 0x18*/
	uint32_t volatile LCKR;    /*GPIO port configuration lock register          offset: 0x1C*/
	uint32_t volatile AFRL;    /*GPIO port alternative function low register    offset: 0x20*/
	uint32_t volatile AFRH;    /*GPIO port alternative function high register   offset: 0x24*/
}GPIO_REG_t;

/*
 * Peripheral definitions for GPIO
 */
#define GPIOA ((GPIO_REG_t*)GPIOA_BASE)
#define GPIOB ((GPIO_REG_t*)GPIOB_BASE)
#define GPIOC ((GPIO_REG_t*)GPIOC_BASE)
#define GPIOD ((GPIO_REG_t*)GPIOD_BASE)
#define GPIOE ((GPIO_REG_t*)GPIOE_BASE)
#define GPIOF ((GPIO_REG_t*)GPIOF_BASE)
#define GPIOG ((GPIO_REG_t*)GPIOG_BASE)
#define GPIOH ((GPIO_REG_t*)GPIOH_BASE)
#define GPIOI ((GPIO_REG_t*)GPIOI_BASE)

/*
 * RCC register structure
 */
typedef struct{
	uint32_t volatile CR;            /*Clock control register                                     offset:0x00*/
	uint32_t volatile PLLCFGR;       /*PLL configuration register                                 offset:0x04*/
	uint32_t volatile CFGR;          /*Clock configuration register                               offset:0x08*/
	uint32_t volatile CIR;           /*Clock interrupt register                                   offset:0x0C*/
	uint32_t volatile AHB1RSTR;      /*AHB1 peripheral register                                   offset:0x10*/
	uint32_t volatile AHB2RSTR;      /*AHB2 peripheral register                                   offset:0x14*/
	uint32_t volatile AHB3RSTR;      /*AHB3 peripheral register                                   offset:0x18*/
	uint32_t RESERVED0;              /*Reserved register                                          offset:0x1C*/
	uint32_t volatile APB1RSTR;      /*APB1 peripheral register                                   offset:0x20*/
	uint32_t volatile APB2RSTR;      /*APB2 peripheral register                                   offset:0x24*/
	uint32_t RESERVED1;              /*Reserved register                                          offset:0x28*/
	uint32_t RESERVED2;              /*Reserved register                                          offset:0x2C*/
	uint32_t volatile AHB1ENR;       /*AHB1 peripheral clock enable register                      offset:0x30*/
	uint32_t volatile AHB2ENR;       /*AHB2 peripheral clock enable register                      offset:0x34*/
	uint32_t volatile AHB3ENR;       /*AHB3 peripheral clock enable register                      offset:0x38*/
	uint32_t RESERVED3;              /*Reserved register                                          offset:0x3C*/
	uint32_t volatile APB1ENR;       /*APB1 peripheral clock enable register                      offset:0x40*/
	uint32_t volatile APB2ENR;       /*APB2 peripheral clock enable register                      offset:0x44*/
	uint32_t RESERVED4;              /*Reserved register                                          offset:0x48*/
	uint32_t RESERVED5;              /*Reserved Register                                          offset:0x4C*/
	uint32_t volatile AHB1LPENR;     /*AHB1 peripheral clock enable in low-power mode register    offset:0x50*/
	uint32_t volatile AHB2LPENR;     /*AHB2 peripheral clock enable in low-power mode register    offset:0x54*/
	uint32_t volatile AHB3LPENR;     /*AHB3 peripheral clock enable in low-power mode register    offset:0x58*/
	uint32_t RESERVED6;              /*Reserved register                                          offset:0x5C*/
	uint32_t volatile APB1LPENR;     /*APB1 peripheral clock enable in low-power mode register    offset:0x60*/
	uint32_t volatile APB2LPENR;     /*APB2 peripheral clock enable in low-power mode register    offset:0x64*/
	uint32_t RESERVED7;              /*Reserved register                                          offset:0x68*/
	uint32_t RESERVED8;              /*Reserved register                                          offset:0x6C*/
	uint32_t volatile BDCR;          /*Backup domain register                                     offset:0x70*/
	uint32_t volatile CSR;           /*Clock control & status register                            offset:0x74*/
	uint32_t RESERVED9;              /*Reserved register                                          offset:0x78*/
	uint32_t RESERVED10;             /*Reserved register                                          offset:0x7C*/
	uint32_t volatile SSCGR;         /*Spread spectrum clock generation register                  offset:0x80*/
	uint32_t volatile PLLI2SCFGR;    /*PLLI2S configuration register                              offset:0x84*/
}RCC_REG_t;

/*
 * Peripheral definitions for RCC
 */
#define RCC ((RCC_REG_t*)RCC_BASE)

/*
 * Macros to reset GPIOx peripherals
 */
#define GPIOA_REG_RESET() do{(RCC->AHB1RSTR |= (1 << 0)); (RCC->AHB1RSTR &= ~(1 << 0));}while(0)
#define GPIOB_REG_RESET() do{(RCC->AHB1RSTR |= (1 << 1)); (RCC->AHB1RSTR &= ~(1 << 1));}while(0)
#define GPIOC_REG_RESET() do{(RCC->AHB1RSTR |= (1 << 2)); (RCC->AHB1RSTR &= ~(1 << 2));}while(0)
#define GPIOD_REG_RESET() do{(RCC->AHB1RSTR |= (1 << 3)); (RCC->AHB1RSTR &= ~(1 << 3));}while(0)
#define GPIOE_REG_RESET() do{(RCC->AHB1RSTR |= (1 << 4)); (RCC->AHB1RSTR &= ~(1 << 4));}while(0)
#define GPIOF_REG_RESET() do{(RCC->AHB1RSTR |= (1 << 5)); (RCC->AHB1RSTR &= ~(1 << 5));}while(0)
#define GPIOG_REG_RESET() do{(RCC->AHB1RSTR |= (1 << 6)); (RCC->AHB1RSTR &= ~(1 << 6));}while(0)
#define GPIOH_REG_RESET() do{(RCC->AHB1RSTR |= (1 << 7)); (RCC->AHB1RSTR &= ~(1 << 7));}while(0)
#define GPIOI_REG_RESET() do{(RCC->AHB1RSTR |= (1 << 8)); (RCC->AHB1RSTR &= ~(1 << 8));}while(0)

/*
 * Clock enable macro for GPIOx peripherals
 */
#define RCC_GPIOA_CLK_ENABLE()   ((RCC->AHB1ENR) |= (1 << 0))
#define RCC_GPIOB_CLK_ENABLE()   ((RCC->AHB1ENR) |= (1 << 1))
#define RCC_GPIOC_CLK_ENABLE()   ((RCC->AHB1ENR) |= (1 << 2))
#define RCC_GPIOD_CLK_ENABLE()   ((RCC->AHB1ENR) |= (1 << 3))
#define RCC_GPIOE_CLK_ENABLE()   ((RCC->AHB1ENR) |= (1 << 4))
#define RCC_GPIOF_CLK_ENABLE()   ((RCC->AHB1ENR) |= (1 << 5))
#define RCC_GPIOG_CLK_ENABLE()   ((RCC->AHB1ENR) |= (1 << 6))
#define RCC_GPIOH_CLK_ENABLE()   ((RCC->AHB1ENR) |= (1 << 7))
#define RCC_GPIOI_CLK_ENABLE()   ((RCC->AHB1ENR) |= (1 << 8))

/*
 * Clock disable macro for GPIOx peripherals
 */
#define RCC_GPIOA_CLK_DISABLE()   ((RCC->AHB1ENR) &= ~(1 << 0))
#define RCC_GPIOB_CLK_DISABLE()   ((RCC->AHB1ENR) &= ~(1 << 1))
#define RCC_GPIOC_CLK_DISABLE()   ((RCC->AHB1ENR) &= ~(1 << 2))
#define RCC_GPIOD_CLK_DISABLE()   ((RCC->AHB1ENR) &= ~(1 << 3))
#define RCC_GPIOE_CLK_DISABLE()   ((RCC->AHB1ENR) &= ~(1 << 4))
#define RCC_GPIOF_CLK_DISABLE()   ((RCC->AHB1ENR) &= ~(1 << 5))
#define RCC_GPIOG_CLK_DISABLE()   ((RCC->AHB1ENR) &= ~(1 << 6))
#define RCC_GPIOH_CLK_DISABLE()   ((RCC->AHB1ENR) &= ~(1 << 7))
#define RCC_GPIOI_CLK_DISABLE()   ((RCC->AHB1ENR) &= ~(1 << 8))

/*
 * Clock enable macro for I2Cx peripherals
 */
#define RCC_I2C1_CLK_ENABLE()    ((RCC->APB1ENR) |= (1 << 21))
#define RCC_I2C2_CLK_ENABLE()    ((RCC->APB1ENR) |= (1 << 22))
#define RCC_I2C3_CLK_ENABLE()    ((RCC->APB1ENR) |= (1 << 23))

/*
 *Clock disable macro for I2Cx peripherals
 */
#define RCC_I2C1_CLK_DISABLE()    ((RCC->APB1ENR) &= ~(1 << 21))
#define RCC_I2C2_CLK_DISABLE()    ((RCC->APB1ENR) &= ~(1 << 22))
#define RCC_I2C3_CLK_DISABLE()    ((RCC->APB1ENR) &= ~(1 << 23))

/*
 * Clock enable macro for SPIx peripherals
 */
#define RCC_SPI1_CLK_ENABLE()      ((RCC->APB2ENR) |= (1 << 12))
#define RCC_SPI2_CLK_ENABLE()      ((RCC->APB1ENR) |= (1 << 14))
#define RCC_SPI3_CLK_ENABLE()      ((RCC->APB2ENR) |= (1 << 15))

/*
 * Clock disable macro for SPIx peripherals
 */
#define RCC_SPI1_CLK_DISABLE      ((RCC->APB2ENR) &= ~(1 << 12))
#define RCC_SPI2_CLK_DISABLE      ((RCC->APB1ENR) &= ~(1 << 14))
#define RCC_SPI3_CLK_DISABLE      ((RCC->APB2ENR) &= ~(1 << 15))

/*
 * Clock enable macro for UART/USARTx peripherals
 */
#define RCC_USART1_CLK_ENABLE()  ((RCC->APB2ENR) |= (1 << 4))
#define RCC_USART2_CLK_ENABLE()  ((RCC->APB1ENR) |= (1 << 17))
#define RCC_USART3_CLK_ENABLE()  ((RCC->APB1ENR) |= (1 << 18))
#define RCC_UART4_CLK_ENABLE()   ((RCC->APB1ENR) |= (1 << 19))
#define RCC_UART5_CLK_ENABLE()   ((RCC->APB1ENR) |= (1 << 20))
#define RCC_USART6_CLK_ENABLE()  ((RCC->APB2ENR) |= (1 << 5))

/*
 * Clock disable macro for UART/USARTx peripherals
 */
#define RCC_USART1_CLK_DISABLE()  ((RCC->APB2ENR) &= ~(1 << 4))
#define RCC_USART2_CLK_DISABLE()  ((RCC->APB1ENR) &= ~(1 << 17))
#define RCC_USART3_CLK_DISABLE()  ((RCC->APB1ENR) &= ~(1 << 18))
#define RCC_UART4_CLK_DISABLE()   ((RCC->APB1ENR) &= ~(1 << 19))
#define RCC_UART5_CLK_DISABLE()   ((RCC->APB1ENR) &= ~(1 << 20))
#define RCC_USART6_CLK_DISABLE()  ((RCC->APB2ENR) &= ~(1 << 5))

/*
 * Clock enable macro for SYSCFG peripheral
 */
#define RCC_SYSCFG_CLK_ENABLE()  ((RCC->APB2ENR) |= (1 << 14))

/*
 * SYSCFG peripheral register structure
 */
typedef struct{
	uint32_t volatile MEMRMP;  /*Memory remap register                           offset: 0x00*/
	uint32_t volatile PMC;     /*Peripheral mode configuration register          offset: 0x04*/
	uint32_t volatile EXTICR1; /*External interrupt configuration register 1     offset: 0x08*/
	uint32_t volatile EXTICR2; /*External interrupt configuration register 2     offset: 0x0C*/
	uint32_t volatile EXTICR3; /*External interrupt configuration register 3     offset: 0x10*/
	uint32_t volatile EXTICR4; /*External interrupt configuration register 4     offset: 0x14*/
	uint32_t RESERVED1;        /*Reserved register                               offset: 0x18*/
	uint32_t RESERVED2;        /*Reserved register                               offset: 0x1C*/
	uint32_t volatile CMPCR;   /*Compensation cell control register              offset: 0x20*/
	uint32_t RESERVED3;        /*Reserved register                               offset: 0x24*/
	uint32_t RESERVED4;        /*Reserved register                               offset: 0x28*/
	uint32_t volatile CFGR;    /*Configuration register                          offset: 0x2C*/
}SYSCFG_REG_t;
/*
 * Clock disable macro for SYSCFG peripheral
 */
#define RCC_SYSCFG_CLK_DISABLE()  ((RCC->APB2ENR) &= ~(1 << 14))

/*
 * EXTI peripheral registers structure
 */

typedef struct{
	uint32_t volatile IMR;   /*Interrupt mask register                    offset: 0x00*/
	uint32_t volatile EMR;   /*Event mask register                        offset: 0x04*/
	uint32_t volatile RTSR;  /*Rising trigger selection register          offset: 0x08*/
	uint32_t volatile FTSR;  /*Falling trigger selection register         offset: 0x0C*/
	uint32_t volatile SWIER; /*Software interrupt event register          offset: 0x10*/
	uint32_t volatile PR;    /*Pending register                           offset: 0x14*/
}EXTI_REG_t;

#define EXTI ((EXTI_REG_t*)EXTI_BASE)

/*
 * Generic macros
 */
#define HIGH            1
#define LOW             0
#define ENABLE          1
#define DISABLE         0
#define SET             ENABLE
#define RESET           DISABLE
#define PRESSED         0
#define RELEASED        1


#endif /* INC_STM32F407XX_H_ */
