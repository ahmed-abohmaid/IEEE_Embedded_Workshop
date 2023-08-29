/********************************************************************/
/*************** Author      : Ahmed Ramadan Youssif ****************/
/*************** Date        : 28 Aug 2023           ****************/
/*************** Version     : 0.1                   ****************/
/*************** Module Name : RCC_config.h          ****************/
/********************************************************************/
#ifndef RCC_CONFIG_H
#define RCC_CONFIG_H

/**
 * @brief Select the system clock source.
 *        Your options: RCC_HSI
 *                      RCC_HSE
 *                      RCC_PLL
 */
#define RCC_SYSCLK RCC_HSE

/**
 * @brief Configure the clock type for RCC_SYSCLK when using RCC_HSE.
 *        RCC_RC_CLK_       - RC oscillator will be the source of the clock system.
 *        RCC_CRYSTAL_CLK_  - Crystal oscillator will be the source of the clock system.
 */
#if RCC_SYSCLK == RCC_HSE

#define RCC_CLK_BYPASS RCC_RC_CLK

#endif /**< RCC_SYSCLK */

#endif // RCC_CONFIG_H