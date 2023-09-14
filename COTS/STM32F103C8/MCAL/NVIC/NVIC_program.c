/********************************************************************/
/*************** Author      : Ahmed Ramadan Youssif ****************/
/*************** Date        : 5 Sep 2023            ****************/
/*************** Version     : 0.1                   ****************/
/*************** Module Name : NVIC_interface.h      ****************/
/********************************************************************/

/*****************************< LIB *****************************/
#include "STD_TYPES.h"
#include "BIT_MATH.h"
/*****************************< MCAL_NVIC *****************************/
#include "NVIC_interface.h"
#include "NVIC_private.h"
#include "NVIC_config.h"
/*****************************< SCB *****************************/
#include "SCB_interface.h"

/*****************************< Function Implementations *****************************/

Std_ReturnType MCAL_NVIC_EnableIRQ(IRQn_Type Copy_IRQn)
{
  Std_ReturnType Local_FunctionStatus = E_NOT_OK;

  if (Copy_IRQn < 32)
  {
    NVIC_ISER0 = (1U << Copy_IRQn);
    Local_FunctionStatus = E_OK;
  }
  else if (Copy_IRQn < 64)
  {
    NVIC_ISER1 = (1U << (Copy_IRQn - 32));
    Local_FunctionStatus = E_OK;
  }
  else if (Copy_IRQn < 68)
  {
    NVIC_ISER2 = (1U << (Copy_IRQn - 64));
    Local_FunctionStatus = E_OK;
  }
  else
  {
    Local_FunctionStatus = E_NOT_OK;
  }

  return Local_FunctionStatus;
}

Std_ReturnType MCAL_NVIC_DisableIRQ(IRQn_Type Copy_IRQn)
{
  Std_ReturnType Local_FunctionStatus = E_NOT_OK;

  if (Copy_IRQn < 32)
  {
    NVIC_ICER0 = (1U << Copy_IRQn);
    Local_FunctionStatus = E_OK;
  }
  else if (Copy_IRQn < 64)
  {
    NVIC_ICER1 = (1U << (Copy_IRQn - 32));
    Local_FunctionStatus = E_OK;
  }
  else if (Copy_IRQn < 68)
  {
    NVIC_ICER2 = (1U << (Copy_IRQn - 64));
    Local_FunctionStatus = E_OK;
  }
  else
  {
    Local_FunctionStatus = E_NOT_OK;
  }

  return Local_FunctionStatus;
}

Std_ReturnType MCAL_NVIC_SetPendingIRQ(IRQn_Type Copy_IRQn)
{
  Std_ReturnType Local_FunctionStatus = E_NOT_OK;

  if (Copy_IRQn < 32)
  {
    NVIC_ISPR0 = (1U << Copy_IRQn);
    Local_FunctionStatus = E_OK;
  }
  else if (Copy_IRQn < 64)
  {
    NVIC_ISPR1 = (1U << (Copy_IRQn - 32));
    Local_FunctionStatus = E_OK;
  }
  else if (Copy_IRQn < 68)
  {
    NVIC_ISPR2 = (1U << (Copy_IRQn - 64));
    Local_FunctionStatus = E_OK;
  }
  else
  {
    Local_FunctionStatus = E_NOT_OK;
  }

  return Local_FunctionStatus;
}

Std_ReturnType MCAL_NVIC_ClearPendingIRQ(IRQn_Type Copy_IRQn)
{
  Std_ReturnType Local_FunctionStatus = E_NOT_OK;

  if (Copy_IRQn < 32)
  {
    NVIC_ICPR0 = (1U << Copy_IRQn);
    Local_FunctionStatus = E_OK;
  }
  else if (Copy_IRQn < 64)
  {
    NVIC_ICPR1 = (1U << (Copy_IRQn - 32));
    Local_FunctionStatus = E_OK;
  }
  else if (Copy_IRQn < 68)
  {
    NVIC_ICPR2 = (1U << (Copy_IRQn - 64));
    Local_FunctionStatus = E_OK;
  }

  return Local_FunctionStatus;
}

Std_ReturnType MCAL_NVIC_GetPendingIRQ(IRQn_Type Copy_IRQn, u8 *Copy_ReturnPendingFlag)
{
  Std_ReturnType Local_FunctionStatus = E_NOT_OK;

  if (Copy_ReturnPendingFlag != NULL)
  {
    /**< Check the pending flag based on the interrupt number */
    if (Copy_IRQn < 32)
    {
      /**< Check the bit corresponding to the interrupt */
      if (NVIC_ISPR0 & (1U << Copy_IRQn))
      {
        *Copy_ReturnPendingFlag = 1; /**< Set to 1 if the flag is pending */
      }
      else
      {
        *Copy_ReturnPendingFlag = 0; /**< Set to 0 if the flag is not pending */
      }
      Local_FunctionStatus = E_OK;
    }
    else if (Copy_IRQn < 64)
    {
      /**< Check the bit corresponding to the interrupt */
      if (NVIC_ISPR1 & (1U << (Copy_IRQn - 32)))
      {
        *Copy_ReturnPendingFlag = 1; /**< Set to 1 if the flag is pending */
      }
      else
      {
        *Copy_ReturnPendingFlag = 0; /**< Set to 0 if the flag is not pending */
      }
      Local_FunctionStatus = E_OK;
    }
    else if (Copy_IRQn < 68)
    {
      /**< Check the bit corresponding to the interrupt */
      if (NVIC_ISPR2 & (1U << (Copy_IRQn - 64)))
      {
        *Copy_ReturnPendingFlag = 1; /**< Set to 1 if the flag is pending */
      }
      else
      {
        *Copy_ReturnPendingFlag = 0; /**< Set to 0 if the flag is not pending */
      }
      Local_FunctionStatus = E_OK;
    }
    else
    {
      Local_FunctionStatus = E_NOT_OK;
    }
  }

  return Local_FunctionStatus;
}

Std_ReturnType MCAL_NVIC_xSetPriority(IRQn_Type Copy_IRQn, u8 Copy_Priority)
{
    Std_ReturnType Local_FunctionStatus = E_NOT_OK;

    if (Copy_IRQn < 0 || Copy_IRQn >= NUMBER_OF_INTERRUPTS) /**< Check if IRQn is within valid range */ 
    {
        return Local_FunctionStatus;
    }

    if (Copy_Priority <= NVIC_MAX_PRIORITY) /**< Ensure the priority value is within the valid range (0-255) */ 
    {
        /**< Set the group and sub-group priority for interrupt handling in SCB_AIRCR register */
        SCB_SetPriorityGrouping(NVIC_0GROUP_16SUB);
        
        /**< Calculate the register index (IPRx) and bit position within the register */ 
        u32 RegisterIndex = Copy_IRQn / 4;     /**< Divide by 4 to get the register index */  
        u32 BitPosition = (Copy_IRQn % 4) * 8; /**< Multiply by 8 to get the bit position */

        /**< Clear the bits that control the priority for the given interrupt */ 
        NVIC_IPR_BASE_ADDRESS[RegisterIndex] &= ~(0xFF << BitPosition);

        /**< Set the priority in the appropriate IPRx register */ 
        NVIC_IPR_BASE_ADDRESS[RegisterIndex] = (Copy_Priority << (BitPosition << 4));

        Local_FunctionStatus = E_OK;
    }

    return Local_FunctionStatus;
}
