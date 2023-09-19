#include "STD_TYPES.h"
#include "BIT_MATH.h"
/**< MCAL */
#include "RCC_interface.h"
#include "GPIO_interface.h"
#include "STK_interface.h"
/**< HAL */
#include "LED_interface.h"
/**< APP */

#define GREEN_LED GPIO_PIN1
#define YELLOW_LED GPIO_PIN2
#define RED_LED GPIO_PIN3

int main(void)
{
	/**< Init RCC */
	Mcal_Rcc_InitSysClock();

	/**< Enable GPIO Peripheral */
	Mcal_Rcc_EnablePeripheral(RCC_APB2, RCC_APB2ENR_IOPAEN);

	/**< Set Pin 4 as output push pull */
	LED_SetMode(GPIO_PORTA, RED_LED);
	LED_SetMode(GPIO_PORTA, YELLOW_LED);
	LED_SetMode(GPIO_PORTA, GREEN_LED);

	while (1)
	{
		LED_On(GPIO_PORTA, RED_LED);
		STK_SetDelay_ms(3000);
		LED_Off(GPIO_PORTA, RED_LED);
		
		LED_Bounced(GPIO_PORTA, YELLOW_LED, 3000);
		
		LED_On(GPIO_PORTA, GREEN_LED);
		STK_SetDelay_ms(3000);
		LED_Off(GPIO_PORTA, GREEN_LED);

		LED_Bounced(GPIO_PORTA, YELLOW_LED, 3000);
	}
}
