/********************************************************************/
/*************** Author      : Ahmed Ramadan Youssif ****************/
/*************** Date        : 5 Sep 2023            ****************/
/*************** Version     : 0.1                   ****************/
/*************** Module Name : NVIC_program.c        ****************/
/********************************************************************/

/*****************************< LIB *****************************/
#include "STD_TYPES.h"
#include "BIT_MATH.h"
/*****************************< MCAL_NVIC *****************************/
#include "NVIC_interface.h"
#include "NVIC_private.h"
#include "NVIC_config.h"
/*****************************< SCB *****************************/
// #include "SCB_interface.h"

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

// Std_ReturnType MCAL_NVIC_xSetPriority(IRQn_Type Copy_IRQn, u8 Copy_Priority)
// {
//   Std_ReturnType Local_FunctionStatus = E_NOT_OK;
// 
//   if (Copy_IRQn < 0 || Copy_IRQn > NUMBER_OF_INTERRUPTS) /**< Check if IRQn is within valid range */
//   {
//     return Local_FunctionStatus;
//   }
// 
//   if (Copy_Priority <= NVIC_MAX_PRIORITY) /**< Ensure the priority value is within the valid range (0-255) */
//   {
//     /**< Set the group and sub-group priority for interrupt handling in SCB_AIRCR register */
//     SCB_SetPriorityGrouping(NVIC_0GROUP_16SUB);
// 
//     /**< Calculate the register index (IPRx) and bit position within the register */
//     u32 RegisterIndex = Copy_IRQn / 4;     /**< Divide by 4 to get the register index */
//     u32 BitPosition = (Copy_IRQn % 4) * 8; /**< Multiply by 8 to get the bit position */
// 
//     /**< Clear the bits that control the priority for the given interrupt */
//     NVIC_IPR_BASE_ADDRESS[RegisterIndex] &= ~(0xFF << BitPosition);
// 
//     /**< Set the priority in the appropriate IPRx register */
//     NVIC_IPR_BASE_ADDRESS[RegisterIndex] |= (Copy_Priority << (BitPosition << 4));
// 
//     Local_FunctionStatus = E_OK;
//   }
// 
//   return Local_FunctionStatus;
// }

Std_ReturnType MCAL_NVIC_vSetPriority(IRQn_Type Copy_IRQn, u8 Copy_GroupPriority, u8 Copy_SubPriority)
{
  Std_ReturnType Local_FunctionStatus = E_NOT_OK;
  u8 NVIC_MAX_Group_Priority;
  u8 NVIC_MAX_Sub_Priority;

#if (PRIORITY_GROUPING == NVIC_16GROUP_0SUB)
  NVIC_MAX_Group_Priority = 15;
  NVIC_MAX_Sub_Priority = NONE;
#elif (PRIORITY_GROUPING == NVIC_8GROUP_2SUB)
  NVIC_MAX_Group_Priority = 7;
  NVIC_MAX_Sub_Priority = 1;
#elif (PRIORITY_GROUPING == NVIC_4GROUP_4SUB)
  NVIC_MAX_Group_Priority = 3;
  NVIC_MAX_Sub_Priority = 3;
#elif (PRIORITY_GROUPING == NVIC_2GROUP_8SUB)
  NVIC_MAX_Group_Priority = 1;
  NVIC_MAX_Sub_Priority = 7;
#elif (PRIORITY_GROUPING == NVIC_0GROUP_16SUB)
  NVIC_MAX_Group_Priority = NONE;
  NVIC_MAX_Sub_Priority = 15;
#else
#error "Invalid PRIORITY_GROUPING value. Please choose from _16GROUP_SUB0, _8GROUP_SUB2, _4GROUP_SUB4, _2GROUP_SUB8, or _0GROUP_SUB16."
#endif

  if (Copy_GroupPriority > NVIC_MAX_Group_Priority || Copy_SubPriority > NVIC_MAX_Sub_Priority)
  {
    /**< Invalid priority value */
    return Local_FunctionStatus;
  }

  if (Copy_IRQn < 0 || Copy_IRQn >= NUMBER_OF_INTERRUPTS) /**< Check if IRQn is within valid range */
  {
    return Local_FunctionStatus;
  }

  /**< Configure the priority grouping for the Nested Vectored Interrupt Controller (NVIC) */
  SCB_SetPriorityGrouping(PRIORITY_GROUPING);

  /**< Calculate the Priority value will be added to the IPRx
   * Lets test:
   * if Copy_SubPriority = 2, Copy_GroupPriority = 1, and we choose NVIC_4GROUP_4SUB as PRIORITY_GROUPING (xx.yy)
   * NVIC_4GROUP_4SUB -> 0x05FA0500, NVIC_16GROUP_0SUB -> 0x05FA0700
   * 1. (PRIORITY_GROUPING - NVIC_16GROUP_0SUB) = 200
   * 2. 200 / 100 = 2
   * 3. Copy_GroupPriority << 1 -> 2 (0b0010) << 2 = 0b0100
   * 4. Copy_SubPriority | 0b0100 -> 0b0010 | 0b0100 = 0b0110 ===> 01 for GroupPriority, 10 for SubPriority
   * 01 == 1 -> GroupPriority which as we need
   * 10 == 2 -> SubPriority which as we need
   */
  u8 Local_Priority = (Copy_SubPriority | (Copy_GroupPriority << (PRIORITY_GROUPING - NVIC_16GROUP_0SUB) / 0x100));

  /**< Calculate the register index (IPRx) and bit position within the register */
  u32 RegisterIndex = Copy_IRQn / 4;     /**< Divide by 4 to get the register index */
  u32 BitPosition = (Copy_IRQn % 4) * 8; /**< Multiply by 8 to get the bit position */

  /**< Clear the bits that control the priority for the given interrupt */
  NVIC_IPR_BASE_ADDRESS[RegisterIndex] &= ~(0xFF << BitPosition);

  /**< Set the priority in the appropriate IPRx register */
  NVIC_IPR_BASE_ADDRESS[RegisterIndex] |= (Local_Priority << (BitPosition << 4));

  return Local_FunctionStatus;
}

// Std_ReturnType MCAL_NVIC_xGetPriority(IRQn_Type Copy_IRQn, u8 *Copy_Priority)
// {
//   Std_ReturnType Local_FunctionStatus = E_NOT_OK;
// 
//   if (Copy_IRQn > NVIC_MAX_PRIORITY)
//   {
//     return Local_FunctionStatus;
//   }
// 
//   /**< Calculate the register index (IPRx) and bit position within the register */
//   u8 RegisterIndex = Copy_IRQn / 4;     /**< Divide by 4 to get the register index */
//   u8 PeripheralIndex = (Copy_IRQn % 4); /**< Remainder of 4 to get the peripheral index */
//   u8 BitPosition = (Copy_IRQn % 4) * 8; /**< Multiply by 8 to get the bit position */
// 
//   /**< Pointer arithmetic to access the IPRx register */
//   u8 *PriorityRegister = (u8 *)&NVIC_IPR_BASE_ADDRESS[RegisterIndex];
// 
//   /**< Extract the priority from the IPRx register 
//    * Lets Test:
//    * if we target IRQn -> 1
//    * RegisterIndex = 0, PeripheralIndex = 1, BitPosition = 8
//    * PriorityRegister (in our case is IPR0) is casted to be u8 instead of u32
//    * so the step is 8 bits so we can move to other peripherals inside IPR0 in one step
//    * we will get this 8 bits for the peripheral we want and shift it to the extreme right using BitPosition
//    * we shift it to the extreme right to read its value correctly (see GET_BIT function in BIT_MATH.h)
//    * we shift it again to the right 4 bits because our MC add the periority on the last 4 bits on the peripheral (1001xxxx)
//   */
//   *Copy_Priority = ((PriorityRegister[PeripheralIndex] >> (BitPosition)) >> 4) & 0xF;
// 
//   Local_FunctionStatus = E_OK;
// 
//   /**< Return the function status here */
//   return Local_FunctionStatus;
// }