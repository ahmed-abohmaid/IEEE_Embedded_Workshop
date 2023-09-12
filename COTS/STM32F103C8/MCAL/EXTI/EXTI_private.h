/********************************************************************/
/*************** Author      : Ahmed Ramadan Youssif ****************/
/*************** Date        : 9 SEP 2023            ****************/
/*************** Version     : 0.1                   ****************/
/*************** Module Name : EXTI_private.h         ****************/
/********************************************************************/
#ifndef EXTI_PRIVATE_H
#define EXTI_PRIVATE_H

#define EXTI_BASE_ADDRESS 0x40010400U

typedef struct
{
  u32 EXTI_IMR;
  u32 EXTI_EMR;
  u32 EXTI_RTSR;
  u32 EXTI_FTSR;
  u32 EXTI_SWIER;
  u32 EXTI_PR;

} volatile EXTI_RegDef_t;

#define EXTI ((EXTI_RegDef_t *)(EXTI_BASE_ADDRESS))

#endif // EXTI_PRIVATE_H