#include "STD_TYPES.h"
#include "BIT_MATH.h"
/**< MCAL */
#include "RCC_interface.h"
#include "GPIO_interface.h"
#include "STK_interface.h"
/**< APP */

int main(void)
{
	/**< Init RCC */
	Mcal_Rcc_InitSysClock();

	/**< Enable GPIO Peripheral */
	Mcal_Rcc_EnablePeripheral(RCC_APB2, RCC_APB2ENR_IOPAEN);

	/**< Set Pin 4 as output push pull */
	MCAL_GPIO_SetPinMode(GPIO_PORTA, GPIO_PIN7, GPIO_OUTPUT_PUSH_PULL_2MHZ);

	while (1)
	{
		MCAL_GPIO_SetPinValue(GPIO_PORTA, GPIO_PIN7, GPIO_HIGH);
		STK_SetDelay_ms(500);
		MCAL_GPIO_SetPinValue(GPIO_PORTA, GPIO_PIN7, GPIO_LOW);
		STK_SetDelay_ms(500);
	}
}
