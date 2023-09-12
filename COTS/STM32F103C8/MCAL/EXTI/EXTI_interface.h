/********************************************************************/
/*************** Author      : Ahmed Ramadan Youssif ****************/
/*************** Date        : 9 SEP 2023            ****************/
/*************** Version     : 0.1                   ****************/
/*************** Module Name : EXTI_interface.h         ****************/
/********************************************************************/
#ifndef EXTI_INTERFACE_H
#define EXTI_INTERFACE_H

#define EXTI_FAILING_EDGE         0
#define EXTI_RISING_EDGE          1
#define EXTI_BOTH_EDGE            2

#define EXTI0                     0
#define EXTI1                     1
#define EXTI2                     2
#define EXTI3                     3
#define EXTI4                     4
#define EXTI5                     5
#define EXTI6                     6
#define EXTI7                     7
#define EXTI8                     8
#define EXTI9                     9
#define EXTI10                    10
#define EXTI11                    11
#define EXTI12                    12
#define EXTI13                    13
#define EXTI14                    14
#define EXTI15                    15

Std_ReturnType EXTI_Init(void);

Std_ReturnType EXTI_Enable(u8 Copy_Line);

Std_ReturnType EXTI_Disable(u8 Copy_Line);

Std_ReturnType EXTI_SetPinTrigger(u8 Copy_Line, u8 Copy_Mode);

#endif // EXTI_INTERFACE_H