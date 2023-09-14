/********************************************************************/
/*************** Author      : Ahmed Ramadan Youssif ****************/
/*************** Date        : 12 SEP 2023            ***************/
/*************** Version     : 0.1                    ***************/
/*************** Module Name : AFIO_interface.h       ***************/
/********************************************************************/
#ifndef AFIO_INTERFACE_H
#define AFIO_INTERFACE_H

#define AFIO_PORTA 0
#define AFIO_PORTB 1
#define AFIO_PORTC 2

Std_ReturnType MCAL_AFIO_SetEXTIConfiguration(u8 Copy_Line, u8 Copy_PortMap);

#endif // AFIO_INTERFACE_H