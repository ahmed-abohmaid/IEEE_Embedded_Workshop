/********************************************************************/
/*************** Author    : Ahmed Ramadan Youssif ******************/
/*************** Date      : 28 Aug 2023           ******************/
/*************** Version   : 0.1                   ******************/
/*************** File Name : BIT_MATH_H.h           ******************/
/********************************************************************/
#ifndef BIT_MATH_H
#define BIT_MATH_H

#define SET_BIT(REG, BIT_NO) REG |= (1 << BIT_NO)
#define CLR_BIT(REG, BIT_NO) REG &= ~(1 << BIT_NO)
#define TOG_BIT(REG, BIT_NO) REG ^= (1 << BIT_NO)
#define GET_BIT(REG, BIT_NO) (REG & (1 << BIT_NO)) >> BIT_NOb 

#endif // BIT_MATH_H