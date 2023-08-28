/********************************************************************/
/*************** Author      : Ahmed Ramadan Youssif ****************/
/*************** Date        : 28 Aug 2023           ****************/
/*************** Version     : 0.1                   ****************/
/*************** Module Name : RCC_private.h         ****************/
/********************************************************************/
#ifndef RCC_PRIVATE_H
#define RCC_PRIVATE_H

// u32 because the width of the memory in the arm is 32bit => 4 byte
#define RCC_CR (*((volatile u32 *)0x40021000 + 0x00));
#define RCC_CFGR (*((volatile u32 *)0x40021000 + 0x04));
#define RCC_CIR (*((volatile u32 *)0x40021000 + 0x08));
#define RCC_APB2RSTR (*((volatile u32 *)0x40021000 + 0x0C));
#define RCC_APB1RSTR (*((volatile u32 *)0x40021000 + 0x010));
#define RCC_AHBENR (*((volatile u32 *)0x40021000 + 0x14));
#define RCC_APB2ENR (*((volatile u32 *)0x40021000 + 0x18));
#define RCC_APB1ENR (*((volatile u32 *)0x40021000 + 0x1C));
#define RCC_BDCR (*((volatile u32 *)0x40021000 + 0x20));

#endif // RCC_PRIVATE_H