/********************************************************************/
/*************** Author      : Ahmed Ramadan Youssif  ***************/
/*************** Date        : 23 Sep 2023            ***************/
/*************** Version     : 0.1                    ***************/
/*************** Module Name : UART_private.h         ***************/
/********************************************************************/
#ifndef UART_PRIVATE_H
#define UART_PRIVATE_H

#define UART1_BASE_ADDRESS             0x40013800
#define UART2_BASE_ADDRESS             0x40004400
#define UART3_BASE_ADDRESS             0x40004800
#define UART4_BASE_ADDRESS             0x40004C00
#define UART5_BASE_ADDRESS             0x40005000

typedef struct
{
  u32 SR;
  u32 DR;
  u32 BRR;
  u32 CR1;
  u32 CR2;
  u32 CR3;
  u32 GTPR;
} volatile UART_RegDef_t;

// #define UART ((UART_RegDef_t *)(UART1_BASE_ADDRESS))                            


#endif // UART_PRIVATE_H