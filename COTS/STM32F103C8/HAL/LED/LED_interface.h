/********************************************************************/
/*************** Author      : Ahmed Ramadan Youssif  ***************/
/*************** Date        : 9 Sep 2023             ***************/
/*************** Version     : 0.1                    ***************/
/*************** Module Name : LED_interface.h        ***************/
/*************** Layer       : HAL                    ***************/
/********************************************************************/
#ifndef SCB_INTERFACE_H
#define SCB_INTERFACE_H

/**
 * @brief Set The LED Mode.
 *
 * This function used to Set one LED Mode. it sets the pin mode to be Output Push Pull 2MHZ
 * 
 * @param[in] Copy_PortId The ID of the GPIO port (e.g., GPIO_PORTA, GPIO_PORTB, etc.).
 * @param[in] Copy_PinId The ID of the GPIO pin (e.g., GPIO_PIN0, GPIO_PIN1, etc.).
 * 
 * @return Std_ReturnType Returns E_OK if the operation was successful, or E_NOT_OK if an error occurred.
 */
Std_ReturnType LED_SetMode(u8 Copy_PortId, u8 Copy_PinId);

/**
 * @brief Enable The LED.
 *
 * This function used to Enable one LED.
 * 
 * @param[in] Copy_PortId The ID of the GPIO port (e.g., GPIO_PORTA, GPIO_PORTB, etc.).
 * @param[in] Copy_PinId The ID of the GPIO pin (e.g., GPIO_PIN0, GPIO_PIN1, etc.).
 * 
 * @note You Need First To use [LED_SetMode] function.
 * 
 * @return Std_ReturnType Returns E_OK if the operation was successful, or E_NOT_OK if an error occurred.
 */
Std_ReturnType LED_On(u8 Copy_PortId, u8 Copy_PinId);

/**
 * @brief Disable The LED.
 *
 * This function used to disable one LED.
 * 
 * @param[in] Copy_PortId The ID of the GPIO port (e.g., GPIO_PORTA, GPIO_PORTB, etc.).
 * @param[in] Copy_PinId The ID of the GPIO pin (e.g., GPIO_PIN0, GPIO_PIN1, etc.).
 * 
 * @note You Need First To use [LED_SetMode] function.
 * 
 * @return Std_ReturnType Returns E_OK if the operation was successful, or E_NOT_OK if an error occurred.
 */
Std_ReturnType LED_Off(u8 Copy_PortId, u8 Copy_PinId);

/**
 * @brief Bounce LED for the specified number of millisecond.
 *
 * This function enables and disables specific LED for the specified number of millisecond using the SysTick timer.
 * 
 * @param[in] Copy_PortId The ID of the GPIO port (e.g., GPIO_PORTA, GPIO_PORTB, etc.).
 * @param[in] Copy_PinId The ID of the GPIO pin (e.g., GPIO_PIN0, GPIO_PIN1, etc.).
 * @param[in] Copy_MillisecondDelay The number of millisecond to wait. This value should be less than or equal to 16777215 (0x00FFFFFF).
 *
 * @note You Need First To use [LED_SetMode] function.
 * @note The maximum delay achievable with this function, when the SysTick timer clock is 1 MHz, is approximately 16 seconds.
 * 
 * @return E_OK if the delay was successful, E_NOT_OK if an error occurred.
 */
Std_ReturnType LED_Bounced(u8 Copy_PortId, u8 Copy_PinId, u32 Copy_MillisecondDelay);

#endif /**< SCB_INTERFACE_H */
