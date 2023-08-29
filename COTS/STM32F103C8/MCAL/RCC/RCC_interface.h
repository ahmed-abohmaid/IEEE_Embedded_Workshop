/********************************************************************/
/*************** Author      : Ahmed Ramadan Youssif ****************/
/*************** Date        : 28 Aug 2023           ****************/
/*************** Version     : 0.1                   ****************/
/*************** Module Name : RCC_interface.h       ****************/
/********************************************************************/
#ifndef RCC_INTERFACE_H
#define RCC_INTERFACE_H

Std_ReturnType Mcal_Rcc_InitSysClock();

Std_ReturnType Mcal_Rcc_EnablePeripheral();

Std_ReturnType Mcal_Rcc_DisablePeripheral();

#endif // RCC_INTERFACE_H