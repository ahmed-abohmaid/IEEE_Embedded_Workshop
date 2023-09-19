/********************************************************************/
/*************** Author      : Ahmed Ramadan Youssif ****************/
/*************** Date        : 9 SEP 2023            ****************/
/*************** Version     : 0.1                   ****************/
/*************** Module Name : EXTI_program.c         ****************/
/********************************************************************/

/*****************************< LIB *****************************/
#include "STD_TYPES.h"
#include "BIT_MATH.h"
/*****************************< MCAL *****************************/
/**< GPIO */
#include "GPIO_interface.h"
/**< AFIO */
#include "AFIO_interface.h"
/**< EXTI*/
#include "EXTI_interface.h"
#include "EXTI_private.h"
#include "EXTI_config.h"
/*****************************< Function Implementations *****************************/
void EXTI_vInit(void)
{
  Std_ReturnType Local_FunctionStatus = E_NOT_OK;
  for (u8 Line = 0; Line <= EXTI_LINES_COUNT; Line++)
  {
    if (EXTI_Configurations[Line].LineEnabled == EXTI_LINE_ENABLED)
    {
      SET_BIT(EXTI->IMR, Line);

      switch (EXTI_Configurations[Line].TriggerType)
      {
      case EXTI_RISING_EDGE:
        SET_BIT(EXTI->RTSR, Line);
        Local_FunctionStatus = E_OK;
        break;

      case EXTI_FALLING_EDGE:
        SET_BIT(EXTI->FTSR, Line);
        Local_FunctionStatus = E_OK;
        break;

      case EXTI_BOTH_EDGES:
        SET_BIT(EXTI->RTSR, Line);
        SET_BIT(EXTI->FTSR, Line);
        Local_FunctionStatus = E_OK;
        break;

      default:
        Local_FunctionStatus = E_NOT_OK;
        break;
      }

      if (EXTI_Configurations[Line].GPIO_PortMap != EXTI_GPIO_NONE)
      {
        Local_FunctionStatus = MCAL_AFIO_SetEXTIConfiguration(Line, EXTI_Configurations[Line].GPIO_PortMap);
      }
    }
    else
    {
      CLR_BIT(EXTI->IMR, Line);
    }
  }
  return Local_FunctionStatus;
}

Std_ReturnType EXTI_InitForGPIO(u8 GPIO_Pin, u8 GPIO_Port)
{
  /**< Check if GPIO_Pin is within valid range */
  if (GPIO_Pin > EXTI_LINE15 || GPIO_Port > GPIO_PORTC)
  {
    return E_NOT_OK; /**< Invalid GPIO pin or port */
  }

  /**< Determine the GPIO port mapping configuration based on GPIO_Port */
  u8 PortMap = 0;
  if (GPIO_Port == GPIO_PORTA)
  {
    PortMap = EXTI_PORTMAP_GPIOA;
  }
  else if (GPIO_Port == GPIO_PORTB)
  {
    PortMap = EXTI_PORTMAP_GPIOB;
  }
  else if (GPIO_Port == GPIO_PORTC)
  {
    PortMap = EXTI_PORTMAP_GPIOC;
  }
  else
  {
    return E_NOT_OK; /**< Unsupported GPIO port */
  }

  /**< Configure EXTI mapping using AFIO function */
  Std_ReturnType Local_Result = MCAL_AFIO_SetEXTIConfiguration(GPIO_Pin, PortMap);

  /**< Check if the EXTI configuration was successful */
  if (Local_Result == E_OK)
  {
    return E_OK; /**< EXTI initialization successful */
  }
  else
  {
    return E_NOT_OK; /**< EXTI configuration failed */
  }
}

Std_ReturnType EXTI_EnableLine(u8 Copy_Line)
{
  Std_ReturnType Local_FunctionStatus = E_NOT_OK;

  if (Copy_Line < EXTI_LINES_COUNT)
  {
    SET_BIT(EXTI->IMR, Copy_Line);
    Local_FunctionStatus = E_OK;
  }
  else
  {
    Local_FunctionStatus = E_NOT_OK;
  }
  return Local_FunctionStatus;
}

Std_ReturnType EXTI_DisableLine(u8 Copy_Line)
{
  Std_ReturnType Local_FunctionStatus = E_NOT_OK;

  if (Copy_Line < EXTI_LINES_COUNT)
  {
    CLR_BIT(EXTI->IMR, Copy_Line);
    Local_FunctionStatus = E_OK;
  }
  else
  {
    Local_FunctionStatus = E_NOT_OK;
  }
  return Local_FunctionStatus;
}

Std_ReturnType EXTI_SetTrigger(u8 Copy_Line, u8 Copy_Mode)
{
  Std_ReturnType Local_FunctionStatus = E_NOT_OK;
  if (Copy_Line < EXTI_LINES_COUNT)
  {

    switch (Copy_Mode)
    {
    case EXTI_RISING_EDGE:
      SET_BIT(EXTI->RTSR, Copy_Line);
      Local_FunctionStatus = E_OK;
      break;

    case EXTI_FALLING_EDGE:
      SET_BIT(EXTI->FTSR, Copy_Line);
      Local_FunctionStatus = E_OK;
      break;

    case EXTI_BOTH_EDGES:
      SET_BIT(EXTI->RTSR, Copy_Line);
      SET_BIT(EXTI->FTSR, Copy_Line);
      Local_FunctionStatus = E_OK;
      break;

    default:
      Local_FunctionStatus = E_NOT_OK;
      break;
    }
  }

  return Local_FunctionStatus;
}