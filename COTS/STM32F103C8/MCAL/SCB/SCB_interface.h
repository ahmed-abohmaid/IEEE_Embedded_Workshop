/********************************************************************/
/*************** Author      : Ahmed Ramadan Youssif  ***************/
/*************** Date        : 14 Sep 2023            ***************/
/*************** Version     : 0.1                    ***************/
/*************** Module Name : SCB_interface.h        ***************/
/********************************************************************/
#ifndef SCB_INTERFACE_H
#define SCB_INTERFACE_H
/*****************************< Function to enable/disable global interrupts *****************************/
/**
 * @brief Set the Priority Grouping in the System Control Block (SCB).
 *
 * This function sets the priority grouping for the Nested Vectored Interrupt Controller (NVIC)
 * in the ARM Cortex-M microcontroller. The priority grouping determines how interrupt priorities
 * are organized.
 *
 * @param[in] Copy_PriorityGrouping The priority grouping configuration to set.
 *
 * @return None
 *
 * @note The "Copy_PriorityGrouping" parameter should be one of the predefined values for priority grouping.
 * @see SCB_PRIORITY_GROUPING
 */
void SCB_SetPriorityGrouping(u32 Copy_PriorityGrouping);


#endif // SCB_INTERFACE_H