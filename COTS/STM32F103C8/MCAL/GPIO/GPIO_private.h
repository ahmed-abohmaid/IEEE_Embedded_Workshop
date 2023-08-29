/********************************************************************/
/*************** Author      : Ahmed Ramadan Youssif ****************/
/*************** Date        : 29 Aug 2023           ****************/
/*************** Version     : 0.1                   ****************/
/*************** Module Name : GPIO_private.h        ****************/
/********************************************************************/
#ifndef GPIO_PRIVATE_H
#define GPIO_PRIVATE_H

#define GPIO_PORTA_BASE_ADDRESS        0x40010800U
#define GPIO_PORTB_BASE_ADDRESS        0x40010C00U
#define GPIO_PORTC_BASE_ADDRESS        0x40011000U

/********************************< REGISTERS ADDRESSES FOR PORT A ********************************/
#define GPIOA_CRL         (*((volatile u32 *)(GPIO_PORTA_BASE_ADDRESS + 0x00)))

#endif // GPIO_PRIVATE_H