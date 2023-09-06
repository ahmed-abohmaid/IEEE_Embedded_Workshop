/********************************************************************/
/*************** Author      : Ahmed Ramadan Youssif ****************/
/*************** Date        : 28 Aug 2023           ****************/
/*************** Version     : 0.1                   ****************/
/*************** Module Name : RCC_private.h         ****************/
/********************************************************************/
#ifndef RCC_PRIVATE_H
#define RCC_PRIVATE_H

// u32 because the width of the memory in the arm is 32bit => 4 byte
/**
 * @defgroup RCC_Registers
 * @brief Reset and Clock Control (RCC) Registers
 *
 * This module provides definitions for the RCC (Reset and Clock Control) registers
 * for configuring and controlling system clocks and resets in the microcontroller.
 *
 * @{
 */

/**
 * @brief RCC Control Register (CR)
 *
 * This register provides control over the main and PLL (Phase-Locked Loop) system clocks.
 */
#define RCC_CR                  (*((volatile u32 *)0x40021000))

/**
 * @brief RCC Configuration Register (CFGR)
 *
 * This register configures the system clock sources, prescalers, and peripherals clocks.
 */
#define RCC_CFGR                (*((volatile u32 *)0x40021004))

/**
 * @brief RCC Clock Interrupt Register (CIR)
 *
 * This register manages clock interrupts and flags.
 */
#define RCC_CIR                 (*((volatile u32 *)0x40021008))

/**
 * @brief RCC APB2 Peripheral Reset Register (APB2RSTR)
 *
 * This register controls the reset state of peripherals connected to APB2 bus.
 */
#define RCC_APB2RSTR            (*((volatile u32 *)0x4002100C))

/**
 * @brief RCC APB1 Peripheral Reset Register (APB1RSTR)
 *
 * This register controls the reset state of peripherals connected to APB1 bus.
 */
#define RCC_APB1RSTR            (*((volatile u32 *)0x40021010))

/**
 * @brief RCC AHB Peripheral Clock Enable Register (AHBENR)
 *
 * This register enables clock access for peripherals connected to AHB bus.
 */
#define RCC_AHBENR              (*((volatile u32 *)0x40021014))

/**
 * @brief RCC APB1 Peripheral Clock Enable Register (APB1ENR)
 *
 * This register enables clock access for peripherals connected to APB1 bus.
 */
#define RCC_APB1ENR             (*((volatile u32 *)0x4002101C))

/**
 * @brief RCC APB2 Peripheral Clock Enable Register (APB2ENR)
 *
 * This register enables clock access for peripherals connected to APB2 bus.
 */
#define RCC_APB2ENR             (*((volatile u32 *)0x40021018))

/**
 * @brief RCC Backup Domain Control Register (BDCR)
 *
 * This register provides control over backup domain and RTC (Real-Time Clock).
 */
#define RCC_BDCR                (*((volatile u32 *)0x40021020))

/**
 * @brief RCC Control and Status Register (CSR)
 *
 * This register provides various control and status flags.
 */
#define RCC_CSR                 (*((volatile u32 *)0x40021024))

/** @} */ // end of RCC Control Register (CR)

/**
 * @defgroup FLASH_ACR Flash access control register
 * @{
*/
#define FLASH_ACR               (*((volatile u32 *)0x40022000))  /***< Flash Access Control Register */
#define FLASH_ACR_PRFTBE        4      /***< Prefetch Buffer Enable */
/** @} */ // end of FLASH_ACR

/**
 * @defgroup RCC_CR_Bit_Definitions RCC Control Register (RCC_CR) Bit Definitions
 * @{
 */

#define RCC_CR_HSION        0   /**< Internal High-Speed Clock Enable */
#define RCC_CR_HSIRDY       1   /**< Internal High-Speed Clock Ready */
#define RCC_CR_HSICAL       8   /**< Internal High-Speed Clock Calibration */
#define RCC_CR_HSEON        16  /**< External High-Speed Clock Enable */
#define RCC_CR_HSERDY       17  /**< External High-Speed Clock Ready */
#define RCC_CR_HSEBYP       18  /**< External High-Speed Clock Bypass */
#define RCC_CR_HSEPRE       19  /**< External High-Speed Clock Prescaler */
#define RCC_CR_CSSON        24  /**< Clock Security System Enable */
#define RCC_CR_PLLON        24  /**< PLL Enable */
#define RCC_CR_PLLRDY       25  /**< PLL Ready */

/** @} */ // end of RCC_CR_Bit_Definitions

/**
 * @defgroup RCC_Clock_Source RCC Clock Source Macros
 * @{
 */

#define RCC_HSI             0   /**< High-Speed Internal Clock Source (HSI) */
#define RCC_HSE             1   /**< High-Speed External Clock Source (HSE) */
#define RCC_PLL             2   /**< Phase-Locked Loop Clock Source (PLL) */

/** @} */ // end of RCC_Clock_Source

/**
 * @defgroup RCC_CFGR_Bit_Definitions RCC Clock configuration register Bit Definitions
 * @{
 */
#define RCC_CFGR_SW1            0 /*< First Bit Of System Clock Switch Status */
#define RCC_CFGR_SW2            1 /*< Second Bit Of System Clock Switch Status */
#define RCC_CFGR_HPRE_POS       4 /*< AHB prescaler (HPRE) */
#define RCC_CFGR_PLLSRC         16 /*< PLL entry clock source (PLLSRC) */
#define RCC_CFGR_PLLXTPRE       17 /*< HSE divider for PLL entry (PLLXTPRE) */
#define RCC_CFGR_PLLMUL_POS     18 /*< First Bit Of PLL Multiplication Factor (PLLMUL) */
#define RCC_CFGR_USBPRE         22 /*< USB prescaler (USBPRE) */

/**
 * @brief PLL Entry Clock Source Selection
 * @{
*/
#define RCC_CFGR_PLLSRC_HSI     0  /*< PLL entry clock source as HSI */
#define RCC_CFGR_PLLSRC_HSE     1  /*< PLL entry clock source as HSE */
/**@} */ // end of PLL Entry Clock Source Selection

/**
 * @brief Divider for HSE PLL entry clock source
 * @{
*/
#define RCC_CFGR_PLLSRC_HSE_NOT_DIV  0 /*< HSE clock not divided */
#define RCC_CFGR_PLLSRC_HSE_DIV      1 /*< HSE clock divided by 2 */
/**@} */ // end of Divider for HSE PLL entry clock source

/**
 * @brief Divider for USB PLL Clock (USB prescaler)
 * @{
*/
#define RCC_CFGR_USBPRE_DIV      0 /*< PLL clock is divided by 1.5 */
#define RCC_CFGR_USBPRE_NOT_DIV  1 /*< PLL clock is not divided */
/**@} */ // end of Divider for HSE PLL entry clock source

/** @} */ // end of RCC_CFGR_Bit_Definitions

/**
 * @defgroup RCC_APB1ENR RCC APB1 peripheral clock enable register
 * @{
*/
#define USBEN                    23 /*< USB clock enable */
/** @} */ // end of RCC_APB1ENR

/**
 * @defgroup RCC_Clock_Type RCC Clock Type Macros
 * @{
 */

#define RCC_CRYSTAL_CLK_    0   /**< Crystal Oscillator Clock Type */
#define RCC_RC_CLK_         1   /**< RC Oscillator Clock Type */

/** @} */ // end of RCC_Clock_Type

#endif // RCC_PRIVATE_H