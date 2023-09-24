/********************************************************************/
/*************** Author      : Ahmed Ramadan Youssif  ***************/
/*************** Date        : 23 Sep 2023            ***************/
/*************** Version     : 0.1                    ***************/
/*************** Module Name : UART_interface.h       ***************/
/********************************************************************/
#ifndef UART_INTERFACE_H
#define UART_INTERFACE_H

typedef enum
{
  UART1,
  UART2,
  UART3,
  UART4,
  UART5,
} UART_Selection_t;

Std_ReturnType UART_SetUARTNo(UART_Selection_t UARTNo, UART_RegDef_t *Copy_ReturnAddress);

Std_ReturnType UART_init();

#endif // UART_INTERFACE_H
