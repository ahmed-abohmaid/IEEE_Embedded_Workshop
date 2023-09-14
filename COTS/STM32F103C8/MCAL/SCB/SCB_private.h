/********************************************************************/
/*************** Author      : Ahmed Ramadan Youssif  ***************/
/*************** Date        : 14 Sep 2023            ***************/
/*************** Version     : 0.1                    ***************/
/*************** Module Name : SCB_interface.h        ***************/
/********************************************************************/
#ifndef SCB_PRIVATE_H
#define SCB_PRIVATE_H

/**< Base address of the SCB registers */
#define SCB_BASE_ADDRESS    0xE000ED00U
#define SCB_AIRCR           (*((volatile u32 *)(SCB_BASE_ADDRESS + 0x0C))) /**< Application Interrupt and Reset Control Register */

#endif // SCB_PRIVATE_H