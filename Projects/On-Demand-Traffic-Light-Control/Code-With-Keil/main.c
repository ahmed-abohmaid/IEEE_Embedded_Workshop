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

#define ROAD_GREEN_LED 							GPIO_PIN1
#define SHARED_YELLOW_LED 					GPIO_PIN2
#define ROAD_RED_LED 								GPIO_PIN3
#define PEOPLE_RED_LED 							GPIO_PIN6
#define PEOPLE_GREEN_LED 						GPIO_PIN5
#define PEOPLE 											0
#define ROAD 												1

/**< Flag to indicate long press */
volatile u8 longPressDetected = 1;

/**< The main logic of the traffic light control system. */
void StartTrafficToggling(u8);

/**< Enable the green Led on the road side */
void StartRoad(void);

/**< Enable the green Led on the people side */
void StartPeople(void);

/**< Blink the yellow Led on both sides */
void BlinkYellow(void);

/**< Turn off all leds on both sides */
void DisableAllLeds(void);

/**
 * < Handle the button press from people side.
 * This Button allow people to make request to cross the road.
 */
void HandleBtnPress(void);

int main(void)
{
	/**< Init RCC */
	Mcal_Rcc_InitSysClock();

	/**< Enable GPIO Peripheral */
	Mcal_Rcc_EnablePeripheral(RCC_APB2, RCC_APB2ENR_IOPAEN);

	/**< Set LED Pins as output push pull */
	HAL_LED_Init(GPIO_PORTA, ROAD_RED_LED);
	HAL_LED_Init(GPIO_PORTA, ROAD_GREEN_LED);
	HAL_LED_Init(GPIO_PORTA, PEOPLE_GREEN_LED);
	HAL_LED_Init(GPIO_PORTA, PEOPLE_RED_LED);
	HAL_LED_Init(GPIO_PORTA, SHARED_YELLOW_LED);

	/**< Init EXTI Configurations */
	EXTI_vInit();
	MCAL_NVIC_EnableIRQ(10); // For Line 4
	EXTI_SetCallBack(HandleBtnPress);

	/**< Set push button pin as input pull down */
	HAL_PushButton_Init(GPIO_PORTA, GPIO_PIN4, ACTIVE_HIGH);

	while (1)
	{
		StartTrafficToggling(ROAD);
	}
}

void HandleBtnPress(void)
{
	STK_Reset();

	/**< Make Delay before getting button value to check for long press. */
	STK_SetDelay_ms(250);

	u8 currButtonState;
	MCAL_GPIO_GetPinValue(GPIO_PORTA, GPIO_PIN4, &currButtonState);

	if (currButtonState == 1)
	{
		/**< Long press detected */

		EXTI_DisablePendingBit(4);
		MCAL_NVIC_ClearPendingIRQ(10);
		
		Reset_Handler();
	}
	else
	{
		/**< Short press detected */

		EXTI_DisablePendingBit(4);
		MCAL_NVIC_ClearPendingIRQ(10);

		DisableAllLeds();

		BlinkYellow();
		StartPeople();
		BlinkYellow();
		
		Reset_Handler();
	}
}

void StartTrafficToggling(u8 starter)
{
	if (starter == ROAD)
	{

		HAL_LED_Off(GPIO_PORTA, SHARED_YELLOW_LED);

		StartRoad();

		BlinkYellow();

		HAL_LED_Off(GPIO_PORTA, SHARED_YELLOW_LED);

		StartPeople();

		BlinkYellow();
	}
	else
	{

		HAL_LED_Off(GPIO_PORTA, SHARED_YELLOW_LED);

		StartPeople();

		BlinkYellow();

		HAL_LED_Off(GPIO_PORTA, SHARED_YELLOW_LED);

		StartRoad();

		BlinkYellow();
	}
}

void StartRoad(void)
{
	HAL_LED_On(GPIO_PORTA, ROAD_GREEN_LED);
	HAL_LED_On(GPIO_PORTA, PEOPLE_RED_LED);
	STK_SetDelay_ms(5000);

	HAL_LED_Off(GPIO_PORTA, ROAD_GREEN_LED);
	HAL_LED_Off(GPIO_PORTA, PEOPLE_RED_LED);
}

void StartPeople(void)
{
	HAL_LED_On(GPIO_PORTA, PEOPLE_GREEN_LED);
	HAL_LED_On(GPIO_PORTA, ROAD_RED_LED);
	STK_SetDelay_ms(5000);

	HAL_LED_Off(GPIO_PORTA, PEOPLE_GREEN_LED);
	HAL_LED_Off(GPIO_PORTA, ROAD_RED_LED);
}

void BlinkYellow(void)
{
	STK_Reset();
	u32 yellowBlinkStartTime = STK_GetElapsedCounts();

	// Continuously blink yellow LED for 5 seconds
	while (STK_GetElapsedCounts() - yellowBlinkStartTime < (5000 * (1000000 / 1000)))
	{
		HAL_LED_Blink(GPIO_PORTA, SHARED_YELLOW_LED, 500); // Blink yellow every 500ms
		STK_SetDelay_ms(500);

		// Update the start time on each iteration
		yellowBlinkStartTime -= (STK_GetElapsedCounts() + (1000 * (1000000 / 1000)));
	}
}

void DisableAllLeds(void)
{
	HAL_LED_Off(GPIO_PORTA, ROAD_RED_LED);
	HAL_LED_Off(GPIO_PORTA, ROAD_GREEN_LED);
	HAL_LED_Off(GPIO_PORTA, PEOPLE_GREEN_LED);
	HAL_LED_Off(GPIO_PORTA, PEOPLE_RED_LED);
}
