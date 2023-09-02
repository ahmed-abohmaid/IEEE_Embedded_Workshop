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
 * @note Choose one of the available options:
 *       - RCC_HSI: High-Speed Internal Clock Source (HSI).
 *                  This option uses the internal high-speed oscillator as the system clock source.
 *                  The HSI provides a stable and accurate clock source, suitable for most applications.
 *       - RCC_HSE: High-Speed External Clock Source (HSE).
 *                  This option uses an external crystal oscillator as the system clock source.
 *                  The HSE provides a higher level of accuracy and stability compared to HSI.
 *                  It is recommended for applications requiring precise timing.
 *       - RCC_PLL: Phase-Locked Loop Clock Source (PLL).
 *                  This option uses the PLL as the system clock source, which multiplies
 *                  the frequency of an input clock source (e.g., HSI or HSE) to generate
 *                  a higher frequency output. PLL provides flexibility in tuning the clock frequency,
 *                  making it suitable for applications with specific performance requirements.
 */
#define RCC_SYSCLK RCC_HSE

/**
 * @brief Configure the clock type for RCC_SYSCLK when using RCC_HSE.
 *        RCC_RC_CLK       - RC oscillator will be the source of the clock system.
 *        RCC_CRYSTAL_CLK  - Crystal oscillator will be the source of the clock system.
 */
#if RCC_SYSCLK == RCC_HSE

#define RCC_CLK_BYPASS RCC_RC_CLK

#endif /**< RCC_SYSCLK */

/**
 * @brief Configure the Multiplication factor (DesiredMultiplier) for RCC_CFGR_PLLMUL when using RCC_PLL.
 *        0b0000: PLL input clock x 2
 *        0b0001: PLL input clock x 3
 *        0b0010: PLL input clock x 4
 *        0b0011: PLL input clock x 5
 *        0b0100: PLL input clock x 6
 *        0b0101: PLL input clock x 7
 *        0b0110: PLL input clock x 8
 *        0b0111: PLL input clock x 9
 *        0b1000: PLL input clock x 10
 *        0b1001: PLL input clock x 11
 *        0b1010: PLL input clock x 12
 *        0b1011: PLL input clock x 13
 *        0b1100: PLL input clock x 14
 *        0b1101: PLL input clock x 15
 *        0b1110: PLL input clock x 16
 *        0b1111: PLL input clock x 16
 */
#if RCC_SYSCLK == RCC_PLL

#define DesiredMultiplier 0b0000

#endif /**< RCC_SYSCLK */

#endif // RCC_CONFIG_H