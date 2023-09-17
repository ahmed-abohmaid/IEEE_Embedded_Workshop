/********************************************************************/
/*************** Author      : Ahmed Ramadan Youssif  ***************/
/*************** Date        : 14 Sep 2023            ***************/
/*************** Version     : 0.1                    ***************/
/*************** Module Name : SCB_program.c          ***************/
/********************************************************************/

/*****************************< LIB *****************************/
#include "STD_TYPES.h"
#include "BIT_MATH.h"
/*****************************< MCAL_SCB *****************************/
#include "SCB_interface.h"
#include "SCB_private.h"
#include "SCB_config.h"
/*****************************< Function Implementations *****************************/

void SCB_SetPriorityGrouping(u32 Copy_PriorityGrouping)
{
    /* Clear the PRIGROUP bits in AIRCR and set them to the configured value */
    SCB_AIRCR = Copy_PriorityGrouping;
}