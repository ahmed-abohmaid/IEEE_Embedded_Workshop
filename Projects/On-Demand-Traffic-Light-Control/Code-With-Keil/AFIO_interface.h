/********************************************************************/
/*************** Author      : Ahmed Ramadan Youssif ****************/
/*************** Date        : 12 SEP 2023            ***************/
/*************** Version     : 0.1                    ***************/
/*************** Module Name : AFIO_interface.h       ***************/
/********************************************************************/
#ifndef AFIO_INTERFACE_H
#define AFIO_INTERFACE_H

/**
 * @brief Configures EXTI (External Interrupt) line mapping for a specific GPIO port.
 *
 * This function maps a specific GPIO pin to an EXTI line by configuring the EXTI
 * control registers. EXTI lines are used to trigger external interrupts based on
 * GPIO pin events.
 *
 * @param[in] Copy_Line The EXTI line number (0 to 15) to configure.
 * @param[in] Copy_PortMap The GPIO port mapping configuration (0 [GPIO_PORTA], 1 [GPIO_PORTB], or 2 [GPIO_PORTC]) for the EXTI line.
 *
 * @note This function should be called to configure EXTI mapping for GPIO pins that will
 *       trigger external interrupts.
 *
 * @return Std_ReturnType E_OK if the configuration is successful, E_NOT_OK otherwise.
 *
 * @code
 * /// Example usage:
 * /// Configure EXTI line 4 to use GPIO port B mapping.
 * Std_ReturnType result = MCAL_AFIO_SetEXTIConfiguration(EXTI_LINE4, EXTI_PORTMAP_GPIOB);
 * if (result == E_OK) {
 *     /// Configuration successful
 * } else {
 *     /// Configuration failed
 * }
 * @endcode
 */
Std_ReturnType MCAL_AFIO_SetEXTIConfiguration(u8 Copy_Line, u8 Copy_PortMap);

#endif // AFIO_INTERFACE_H