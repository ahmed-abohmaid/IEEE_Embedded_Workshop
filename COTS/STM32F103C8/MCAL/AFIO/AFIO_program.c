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
  Std_ReturnType Local_FunctnStatus;

  if (Copy_Line > 15 || Copy_PortMap > 2)
  {
    return Local_FunctnStatus;
  }

  u8 Local_RegIndex = Copy_Line / 4;
  Copy_Line %= 4;

  AFIO->AFIO_EXTICR[Local_RegIndex] &= ~((0b1111) << (Copy_Line * 4));
  AFIO->AFIO_EXTICR[Local_RegIndex] |= Copy_PortMap << (Copy_Line * 4);

  return Local_FunctnStatus;
}