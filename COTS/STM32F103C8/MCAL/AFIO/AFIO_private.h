/********************************************************************/
/*************** Author      : Ahmed Ramadan Youssif ****************/
/*************** Date        : 12 SEP 2023           ****************/
/*************** Version     : 0.1                   ****************/
/*************** Module Name : AFIO_private.h       *****************/
/********************************************************************/
#ifndef AFIO_PRIVATE_H
#define AFIO_PRIVATE_H

#define AFIO_BASE_ADDRESS 0x40010000

typedef struct
{
  volatile u32 EVCR;
  volatile u32 MAPR;
  volatile u32 EXTICR[4];
  volatile u32 MAPR2;

} AFIO_RegDef_t;

#define AFIO ((AFIO_RegDef_t *)(AFIO_BASE_ADDRESS))

#endif // AFIO_PRIVATE_H