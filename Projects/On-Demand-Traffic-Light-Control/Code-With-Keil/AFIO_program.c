/********************************************************************/
/*************** Author      : Ahmed Ramadan Youssif ****************/
/*************** Date        : 12 SEP 2023            ***************/
/*************** Version     : 0.1                    ***************/
/*************** Module Name : AFIO_program.h         ***************/
/********************************************************************/

/*****************************< LIB *****************************/
#include "STD_TYPES.h"
#include "BIT_MATH.h"
/*****************************< MCAL_AFIO *****************************/
#include "AFIO_interface.h"
#include "AFIO_private.h"
#include "AFIO_config.h"
/*****************************< Function Implementations *****************************/

Std_ReturnType MCAL_AFIO_SetEXTIConfiguration(u8 Copy_Line, u8 Copy_PortMap)
{
  Std_ReturnType Local_FunctionStatus = E_NOT_OK;

  if (Copy_Line > 15 || Copy_PortMap > 2)
  {
    return Local_FunctionStatus;
  }

    /**< Calculate the index of the EXTI control register for the specified line */ 
    u8 Local_RegIndex = Copy_Line / 4;

    /**< Calculate the bit position within the EXTI control register for the specified line */ 
    Copy_Line %= 4;

    /**< Clear the bits that correspond to the EXTI line within the EXTI control register */ 
    AFIO->EXTICR[Local_RegIndex] &= ~((0x0F) << (Copy_Line * 4));

    /**< Set the new PortMap value for the EXTI line within the EXTI control register */ 
    AFIO->EXTICR[Local_RegIndex] |= Copy_PortMap << (Copy_Line * 4);

    /**< Configuration is successful, set the function status to E_OK */ 
    Local_FunctionStatus = E_OK;

  return Local_FunctionStatus;
}