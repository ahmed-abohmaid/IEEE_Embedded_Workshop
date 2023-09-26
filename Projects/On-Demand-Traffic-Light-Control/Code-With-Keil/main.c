#include "STD_TYPES.h"
#include "BIT_MATH.h"
/**< MCAL */
#include "RCC_interface.h"
#include "GPIO_interface.h"
#include "STK_interface.h"
#include "EXTI_interface.h"
#include "NVIC_interface.h"
#include "AFIO_interface.h"
#include "SCB_interface.h"
/**< HAL */
#include "LED_interface.h"
#include "BUTTON_interface.h"

/**< APP */

#define ROAD_GREEN_LED 									GPIO_PIN1
#define SHARED_YELLOW_LED 							GPIO_PIN2
#define ROAD_RED_LED 										GPIO_PIN3
#define PEDESTRAINS_RED_LED 						GPIO_PIN6
#define PEDESTRAINS_GREEN_LED 					GPIO_PIN5
#define PEDESTRAINS 										0
#define ROAD 														1

/**< The main logic of the traffic light control system. */
void StartTrafficToggling(u8);

/**< Enable the green Led on the road side */
void StartRoad(void);

/**< Enable the green Led on the PEDESTRAINS side */
void StartPedestrains(void);

/**< Blink the yellow Led on both sides */
void BlinkYellow(void);

/** @defgroup
 * @brief These Functions called inside the interrupt handler.
 * They have the same previous implementations except the delay which implemented by for loop because STK delay makes some issues to the interrupt handler.
 * @{
 */
void Interrupt_BlinkYellow(void);
void Interrupt_StartRoad(void);
void Interrupt_StartPedestrains(void);
/** @} */

/**< Turn off all leds on both sides */
void DisableAllLeds(void);

/**
 * < Handle the button press from Pedestrains side.
 * This Button allow Pedestrains to make request to cross the road.
 */
void HandleBtnPress(void);

/**< Global Variable to check for yellow blinking. */
u8 isYellowBlink = 0;
/**< Global Variable to check if there is short press after long one. */
u8 isDoublePress = 0;

int main(void)
{
	/**< Init RCC */
	Mcal_Rcc_InitSysClock();

	/**< Enable GPIO Peripheral */
	Mcal_Rcc_EnablePeripheral(RCC_APB2, RCC_APB2ENR_IOPAEN);

	/**< Set LED Pins as output push pull */
	HAL_LED_Init(GPIO_PORTA, ROAD_RED_LED);
	HAL_LED_Init(GPIO_PORTA, ROAD_GREEN_LED);
	HAL_LED_Init(GPIO_PORTA, PEDESTRAINS_GREEN_LED);
	HAL_LED_Init(GPIO_PORTA, PEDESTRAINS_RED_LED);
	HAL_LED_Init(GPIO_PORTA, SHARED_YELLOW_LED);

	/**< Set push button pin as input pull down */
	HAL_PushButton_Init(GPIO_PORTA, GPIO_PIN4, ACTIVE_HIGH);

	/**< Init EXTI Configurations */
	EXTI_vInit();
	EXTI_SetCallBack(HandleBtnPress);
	MCAL_NVIC_EnableIRQ(10); // For Line 4

	while (1)
	{
		StartTrafficToggling(ROAD);
	}
}

void HandleBtnPress(void)
{

	for (int i = 40000; i > 0; i--)
		;

	u8 isLongPress;
	MCAL_GPIO_GetPinValue(GPIO_PORTA, GPIO_PIN4, &isLongPress);
	if (isLongPress == 1)
	{
		/*****************< User Story 5 - Double Press 										*****************/
		isDoublePress = 1;
	}
	
	/*****************< User Story 2 - Long Press 												*****************/
	/*****************< User Story 4 - Yellow Is Blinking 								*****************/
	if (isLongPress == 1 || isDoublePress == 1 || isYellowBlink == 1)
	{
		/**< Long press detected */

		EXTI_DisablePendingBit(4);
		MCAL_NVIC_ClearPendingIRQ(10);
	}
	else
	{
		/*****************< User Story 3 - Pedestrains Green Led Is On  		*****************/
		u8 isPedestrainsOn;
		MCAL_GPIO_GetPinValue(GPIO_PORTA, PEDESTRAINS_GREEN_LED, &isPedestrainsOn);
		if (isPedestrainsOn == 1)
		{
			EXTI_DisablePendingBit(4);
		  MCAL_NVIC_ClearPendingIRQ(10);
		}
		else
		{
			/*****************< User Story 1 - Short press detected			 			*****************/		

			DisableAllLeds();

			Interrupt_BlinkYellow();

			Interrupt_StartPedestrains();

			Interrupt_BlinkYellow();

			Interrupt_StartRoad();

			EXTI_DisablePendingBit(4);
			MCAL_NVIC_ClearPendingIRQ(10);
		}
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

		StartPedestrains();

		BlinkYellow();
	}
	else
	{

		HAL_LED_Off(GPIO_PORTA, SHARED_YELLOW_LED);

		StartPedestrains();

		BlinkYellow();

		HAL_LED_Off(GPIO_PORTA, SHARED_YELLOW_LED);

		StartRoad();

		BlinkYellow();
	}
}

void StartRoad(void)
{
	isYellowBlink = 0;
	isDoublePress = 0;
	
	DisableAllLeds();
	HAL_LED_On(GPIO_PORTA, ROAD_GREEN_LED);
	HAL_LED_On(GPIO_PORTA, PEDESTRAINS_RED_LED);
	STK_SetDelay_ms(5000);

	HAL_LED_Off(GPIO_PORTA, ROAD_GREEN_LED);
	HAL_LED_Off(GPIO_PORTA, PEDESTRAINS_RED_LED);
}

void StartPedestrains(void)
{
	isYellowBlink = 0;
	isDoublePress = 0;
	
	DisableAllLeds();
	HAL_LED_On(GPIO_PORTA, PEDESTRAINS_GREEN_LED);
	HAL_LED_On(GPIO_PORTA, ROAD_RED_LED);
	STK_SetDelay_ms(5000);

	HAL_LED_Off(GPIO_PORTA, PEDESTRAINS_GREEN_LED);
	HAL_LED_Off(GPIO_PORTA, ROAD_RED_LED);
}

void BlinkYellow(void)
{
	isYellowBlink = 1;
	isDoublePress = 0;
	
	DisableAllLeds();
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

void Interrupt_StartRoad(void)
{
	DisableAllLeds();
	HAL_LED_On(GPIO_PORTA, ROAD_GREEN_LED);
	HAL_LED_On(GPIO_PORTA, PEDESTRAINS_RED_LED);
	for (u32 i = 0; i < 166000; i++)
		;

	HAL_LED_Off(GPIO_PORTA, ROAD_GREEN_LED);
	HAL_LED_Off(GPIO_PORTA, PEDESTRAINS_RED_LED);
}

void Interrupt_StartPedestrains(void)
{
	DisableAllLeds();
	HAL_LED_On(GPIO_PORTA, PEDESTRAINS_GREEN_LED);
	HAL_LED_On(GPIO_PORTA, ROAD_RED_LED);
	for (u32 i = 0; i < 166000; i++)
		;

	HAL_LED_Off(GPIO_PORTA, PEDESTRAINS_GREEN_LED);
	HAL_LED_Off(GPIO_PORTA, ROAD_RED_LED);
}

void Interrupt_BlinkYellow(void)
{
	/*< Defining a variable to use it in the implementation*/
	volatile u32 YellowLedCounter = 0;
	u32 BlinkDelay = 0; /*< For the delay loop*/

	while (YellowLedCounter < 166000) // Blink For 5 Seconds
	{

		HAL_LED_On(GPIO_PORTA, SHARED_YELLOW_LED);
		for (BlinkDelay = 0; BlinkDelay < 20000; BlinkDelay++)
			;
		YellowLedCounter += 20000;

		HAL_LED_Off(GPIO_PORTA, SHARED_YELLOW_LED);
		for (BlinkDelay = 0; BlinkDelay < 20000; BlinkDelay++)
			;
		YellowLedCounter += 20000;
	}
}

void DisableAllLeds(void)
{
	HAL_LED_Off(GPIO_PORTA, ROAD_RED_LED);
	HAL_LED_Off(GPIO_PORTA, ROAD_GREEN_LED);
	HAL_LED_Off(GPIO_PORTA, PEDESTRAINS_GREEN_LED);
	HAL_LED_Off(GPIO_PORTA, PEDESTRAINS_RED_LED);
}
