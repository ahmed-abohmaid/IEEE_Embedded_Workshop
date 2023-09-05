/********************************************************************/
/*************** Author      : Ahmed Ramadan Youssif ****************/
/*************** Date        : 5 Sep 2023            ****************/
/*************** Version     : 0.1                   ****************/
/*************** Module Name : NVIC_interface.h      ****************/
/********************************************************************/
#ifndef NVIC_PRIVATE_H
#define NVIC_PRIVATE_H

typedef struct
{
  volatile u32 ISER[3];
  volatile u32 reserved_0[29];

  volatile u32 ICER[3];
  volatile u32 reserved_1[29];

  volatile u32 ISPR[3];
  volatile reserved_2[29];

  volatile u32 ICPR[3];
  volatile u32 reserved_3[29];

  volatile u32 IABR[3];
  volatile u32 reserved_4[29];

} NVIC_Typedef;

#endif // NVIC_PRIVATE_H