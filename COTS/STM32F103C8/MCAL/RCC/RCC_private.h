/********************************************************************/
/*************** Author      : Ahmed Ramadan Youssif ****************/
/*************** Date        : 28 Aug 2023           ****************/
/*************** Version     : 0.1                   ****************/
/*************** Module Name : RCC_private.h         ****************/
/********************************************************************/
#ifndef RCC_PRIVATE_H
#define RCC_PRIVATE_H

// u32 because the width of the memory in the arm is 32bit => 4 byte
#define RCC_CR         (*((volatile u32 *)0x40021000 + 0x00))
#define RCC_CFGR       (*((volatile u32 *)0x40021000 + 0x04))
#define RCC_CIR        (*((volatile u32 *)0x40021000 + 0x08))
#define RCC_APB2RSTR   (*((volatile u32 *)0x40021000 + 0x0C))
#define RCC_APB1RSTR   (*((volatile u32 *)0x40021000 + 0x010))
#define RCC_AHBENR     (*((volatile u32 *)0x40021000 + 0x14))
#define RCC_APB2ENR    (*((volatile u32 *)0x40021000 + 0x18))
#define RCC_APB1ENR    (*((volatile u32 *)0x40021000 + 0x1C))
#define RCC_BDCR       (*((volatile u32 *)0x40021000 + 0x20))

/**
 * @brief RCC_CR_Bit_Definitions
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

#define RCC_HSI 0
#define RCC_HSE 1
#define RCC_PLL 2

/**
 * @brief RCC_CFGR_Bit_Definitions
 */
#define RCC_CFGR_SW             1
#define RCC_CFGR_PLLMUL_POS     18
#define RCC_CFGR_CLR_PLLMUL     (0x0000 << RCC_CFGR_PLLMUL_POS)

#define RCC_CRYSTAL_CLK 0
#define RCC_RC_CLK 1

#endif // RCC_PRIVATE_H