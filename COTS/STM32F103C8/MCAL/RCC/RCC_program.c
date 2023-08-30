/********************************************************************/
/*************** Author      : Ahmed Ramadan Youssif ****************/
/*************** Date        : 28 Aug 2023           ****************/
/*************** Version     : 0.1                   ****************/
/*************** Module Name : RCC_program.c         ****************/
/********************************************************************/

/*******************************< LIB *******************************/
#include "STD_TYPES.h";
#include "BIT_MATH.h";
/*******************************< MCAL *******************************/
#include "RCC_private.h";
#include "RCC_interface.h";
#include "RCC_config.h";

Std_ReturnType Mcal_Rcc_InitSysClock(void)
{
    Std_ReturnType Local_FunctionStatus = E_NOT_OK;

    #if RCC_SYSCLK == RCC_HSE
        
        /**< Enable the external clock to be the source for the system clock. */
        #if RCC_CLK_BYPASS == RCC_RC_CLK

            SET_BIT(RCC_CR, RCC_CR_HSEBYP); /**< Choose RC as a SYSCLK */

        #elif RCC_CLK_BYPASS == RCC_CRYSTAL_CLK

            CLR_BIT(RCC_CR, RCC_CR_HSEBYP); /**< Choose CRYSTAL as a SYSCLK */

        #else 

            #error "Wrong Choice For RCC_CRYSTAL_CLK !"

        #endif /**< RCC_CLK_BYPASS */

        /**< Enable the High-Speed External clock. */
        SET_BIT(RCC_CR, RCC_CR_HSEON);

        /**< Wait until the High-Speed External clock is stable. */
        while(!GET_BIT(RCC_CR, RCC_CR_HSERDY));

        /**< Select High-Speed External clock as the system clock source. */
        RCC_CFGR = 0x00000001;

        Local_FunctionStatus = E_OK;

    #elif RCC_SYSCLK == RCC_HSI
        
        /**< Enable the High-Speed Internal clock. */
        SET_BIT(RCC_CR, RCC_CR_HSION);

        /**< Wait until the High-Speed Internal clock is stable. */
        while(!GET_BIT(RCC_CR, RCC_CR_HSIRDY));

        /**< Select High-Speed Internal clock as the system clock source. */
        RCC_CFGR = 0x00000000;

        Local_FunctionStatus = E_OK;

    #elif RCC_SYSCLK == RCC_PLL
        /**< Disable the PLL clock. */
        CLR_BIT(RCC_CR, RCC_CR_PLLON);

        /**< Set the desired PLL multiplication factor. */
        RCC_CFGR &= RCC_CFGR_CLR_PLLMUL; // Clear the PLLMUL bits
        RCC_CFGR |= (DesiredMultiplier << RCC_CFGR_PLLMUL_POS);

        /**< Enable the PLL clock. */
        SET_BIT(RCC_CR, RCC_CR_PLLON);

        /**< Wait until the PLL clock is stable. */
        while (!GET_BIT(RCC_CR, RCC_CR_PLLRDY));

        /**< Select PLL as the system clock source. */
        SET_BIT(RCC_CFGR, RCC_CFGR_SW);

        Local_FunctionStatus = E_OK;

    #else
        #error "Wrong Choice For RCC_SYSCLK !"

    #endif /**< RCC_SYSCLK */

    return Local_FunctionStatus;
}

Std_ReturnType Mcal_Rcc_EnablePeripheral(u8 Copy_PeripheralId, u8 Copy_BusId)
{
    Std_ReturnType Local_FunctionStatus = E_NOT_OK;

    switch (Copy_BusId)
    {
        case RCC_AHB:
            SET_BIT(RCC_AHBENR, Copy_PeripheralId);
            Local_FunctionStatus = E_OK;
        break;

        case RCC_APB1:
            SET_BIT(RCC_APB1ENR, Copy_PeripheralId);
            Local_FunctionStatus = E_OK;
        break;

        case RCC_APB2:
            SET_BIT(RCC_APB2ENR, Copy_PeripheralId);
            Local_FunctionStatus = E_OK;
        break;

        default:
            Local_FunctionStatus = E_NOT_OK;
        break;
    }

    return Local_FunctionStatus;
};

Std_ReturnType Mcal_Rcc_DisablePeripheral(u8 Copy_PeripheralId, u8 Copy_BusId)
{
    Std_ReturnType Local_FunctionStatus = E_NOT_OK;

    switch (Copy_BusId)
    {
        case RCC_AHB:
            CLR_BIT(RCC_AHBENR, Copy_PeripheralId);
            Local_FunctionStatus = E_OK;
        break;

        case RCC_APB1:
            CLR_BIT(RCC_APB1ENR, Copy_PeripheralId);
            Local_FunctionStatus = E_OK;
        break;

        case RCC_APB2:
            CLR_BIT(RCC_APB2ENR, Copy_PeripheralId);
            Local_FunctionStatus = E_OK;
        break;

        default:
            Local_FunctionStatus = E_NOT_OK;
        break;
    }

    return Local_FunctionStatus;
};