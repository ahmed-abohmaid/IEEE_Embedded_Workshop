/********************************************************************/
/*************** Author      : Ahmed Ramadan Youssif  ***************/
/*************** Date        : 9 Sep 2023             ***************/
/*************** Version     : 0.1                    ***************/
/*************** Module Name : LED_program.c          ***************/
/*************** Layer       : HAL                    ***************/
/********************************************************************/

/*****************************< LIB *****************************/
#include "STD_TYPES.h"
#include "BIT_MATH.h"
/*****************************< MCAL *****************************/
/**< GPIO */
#include "GPIO_interface.h"
/**< STK */
#include "STK_interface.h"
/**< LED */
#include "LED_interface.h"
#include "LED_private.h"
#include "LED_config.h"
/*****************************< Function Implementations *****************************/

Std_ReturnType LED_Init(u8 Copy_PortId, u8 Copy_PinId)
{
  return MCAL_GPIO_SetPinMode(Copy_PortId, Copy_PinId, GPIO_OUTPUT_PUSH_PULL_2MHZ);
}

Std_ReturnType LED_On(u8 Copy_PortId, u8 Copy_PinId)
{
  return MCAL_GPIO_SetPinValue(Copy_PortId, Copy_PinId, LED_HIGH);
}

Std_ReturnType LED_Off(u8 Copy_PortId, u8 Copy_PinId)
{
  return MCAL_GPIO_SetPinValue(Copy_PortId, Copy_PinId, LED_LOW);
}

Std_ReturnType LED_Blink(u8 Copy_PortId, u8 Copy_PinId, u32 Copy_BlinkTime)
{
    if(MCAL_GPIO_SetPinValue(Copy_PortId, Copy_PinId, GPIO_HIGH) == E_NOT_OK)
    {
        return E_NOT_OK;
    }

    if(STK_SetDelay_ms(Copy_BlinkTime) == E_NOT_OK)
    {
        return E_NOT_OK;
    }

    if(MCAL_GPIO_SetPinValue(Copy_PortId, Copy_PinId, GPIO_LOW) == E_NOT_OK)
    {
        return E_NOT_OK;
    }

    return E_OK;
}