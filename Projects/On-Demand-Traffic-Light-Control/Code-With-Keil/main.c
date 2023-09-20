#include "STD_TYPES.h"
#include "BIT_MATH.h"
/**< MCAL */
#include "RCC_interface.h"
#include "GPIO_interface.h"
#include "STK_interface.h"
#include "EXTI_interface.h"
#include "NVIC_interface.h"
/**< HAL */
#include "LED_interface.h"
#include "BUTTON_interface.h"

/**< APP */

#define ROAD_GREEN_LED 				GPIO_PIN1
#define SHARED_YELLOW_LED 		GPIO_PIN2
#define ROAD_RED_LED 					GPIO_PIN3
#define PEOPLE_RED_LED 				GPIO_PIN6
#define PEOPLE_GREEN_LED 			GPIO_PIN5

void StartTrafficToggling(u8, u8, u8, u8);

int main(void)
{
	/**< Init RCC */
	Mcal_Rcc_InitSysClock();

	/**< Enable GPIO Peripheral */
	Mcal_Rcc_EnablePeripheral(RCC_APB2, RCC_APB2ENR_IOPAEN);

	/**< Set LED Pins as output push pull */
	HAL_LED_Init(GPIO_PORTA, ROAD_RED_LED);
	HAL_LED_Init(GPIO_PORTA, SHARED_YELLOW_LED);
	HAL_LED_Init(GPIO_PORTA, ROAD_GREEN_LED);
	HAL_LED_Init(GPIO_PORTA, PEOPLE_GREEN_LED);
	HAL_LED_Init(GPIO_PORTA, PEOPLE_RED_LED);

	/**< Set push button pin as inpuy pull down */
	HAL_PushButton_Init(GPIO_PORTA, GPIO_PIN4, ACTIVE_HIGH);
	MCAL_NVIC_EnableIRQ(10);
	EXTI_vInit();

	while (1)
	{
		StartTrafficToggling(ROAD_GREEN_LED, ROAD_RED_LED, PEOPLE_RED_LED, PEOPLE_GREEN_LED);
	}
}

void EXTI4_IRQHandler(void)
{

	EXTI_EnableLine(4);
	HAL_LED_Off(GPIO_PORTA, ROAD_RED_LED);
	HAL_LED_Off(GPIO_PORTA, ROAD_GREEN_LED);
	HAL_LED_Off(GPIO_PORTA, PEOPLE_GREEN_LED);
	HAL_LED_Off(GPIO_PORTA, PEOPLE_RED_LED);

	STK_Reset();
	u32 yellowBlinkStartTime = STK_GetElapsedCounts();

	// Continuously blink yellow LED for 5 seconds
	while (STK_GetElapsedCounts() - yellowBlinkStartTime < (5000 * (1000000 / 1000)))
	{
		HAL_LED_Blink(GPIO_PORTA, SHARED_YELLOW_LED, 500); // Blink yellow every 500ms
		STK_SetDelay_ms(500);

		// Update the start time on each iteration
		yellowBlinkStartTime -= (STK_GetElapsedCounts() + (500 * (1000000 / 1000)));
	}

	StartTrafficToggling(ROAD_RED_LED, ROAD_GREEN_LED, PEOPLE_GREEN_LED, PEOPLE_RED_LED);
	
	EXTI_DisableLine(4);
}

void StartTrafficToggling(u8 FirstRoadLedOn, u8 LastRoadLedOn, u8 FirstPeopleLedOn, u8 LastPeopleLedOn)
{
	HAL_LED_On(GPIO_PORTA, FirstRoadLedOn);
	HAL_LED_On(GPIO_PORTA, FirstPeopleLedOn);
	STK_SetDelay_ms(5000);

	HAL_LED_Off(GPIO_PORTA, FirstRoadLedOn);
	HAL_LED_Off(GPIO_PORTA, FirstPeopleLedOn);

	STK_Reset();
	u32 yellowBlinkStartTime = STK_GetElapsedCounts();

	// Continuously blink yellow LED for 5 seconds
	while (STK_GetElapsedCounts() - yellowBlinkStartTime < (5000 * (1000000 / 1000)))
	{
		HAL_LED_Blink(GPIO_PORTA, SHARED_YELLOW_LED, 500); // Blink yellow every 500ms
		STK_SetDelay_ms(500);

		// Update the start time on each iteration
		yellowBlinkStartTime -= (STK_GetElapsedCounts() + (500 * (1000000 / 1000)));
	}

	// Turn off yellow LED
	HAL_LED_Off(GPIO_PORTA, SHARED_YELLOW_LED);

	HAL_LED_On(GPIO_PORTA, LastRoadLedOn);
	HAL_LED_On(GPIO_PORTA, LastPeopleLedOn);
	STK_SetDelay_ms(5000);

	HAL_LED_Off(GPIO_PORTA, LastRoadLedOn);
	HAL_LED_Off(GPIO_PORTA, LastPeopleLedOn);

	STK_Reset();
	yellowBlinkStartTime = STK_GetElapsedCounts();

	// Continuously blink yellow LED for 5 seconds
	while (STK_GetElapsedCounts() - yellowBlinkStartTime < (5000 * (1000000 / 1000)))
	{
		HAL_LED_Blink(GPIO_PORTA, SHARED_YELLOW_LED, 500); // Blink yellow every 500ms
		STK_SetDelay_ms(500);

		// Update the start time on each iteration
		yellowBlinkStartTime -= (STK_GetElapsedCounts() + (500 * (1000000 / 1000)));
	}
}
