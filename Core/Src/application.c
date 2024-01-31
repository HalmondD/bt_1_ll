#include "application.h"
#define UINT32_T_MAX 4294967295

volatile uint32_t ms_ticks = 0;

HAL_IncTick()
{
    ms_ticks++;
}

void delay_ms(uint32_t delay_time_ms)
{
	uint32_t expected_ticks = ms_ticks + delay_time_ms;

    if (expected_ticks >= UINT32_T_MAX)
    {
        ms_ticks = 0;
        expected_ticks = delay_time_ms;
    }

	while (ms_ticks < expected_ticks)
	{
		__asm("nop");
	}
}

void app_main(void)
{
    LL_GPIO_InitTypeDef my_GPIO_InitStruct = {0};

    // GPIO Ports Clock Enable
    LL_APB2_GRP1_EnableClock(LL_APB2_GRP1_PERIPH_GPIOC);

    // Set GPIOC output
    LL_GPIO_ResetOutputPin(GPIOC, LL_GPIO_PIN_13);

    // Set GPIOC output type
    my_GPIO_InitStruct.Pin = LL_GPIO_PIN_13;
    my_GPIO_InitStruct.Mode = LL_GPIO_MODE_OUTPUT;
    my_GPIO_InitStruct.Speed = LL_GPIO_SPEED_FREQ_LOW;
    my_GPIO_InitStruct.OutputType = LL_GPIO_OUTPUT_PUSHPULL;
    my_GPIO_InitStruct.Pull = LL_GPIO_PULL_UP;
    LL_GPIO_Init(GPIOC, &my_GPIO_InitStruct);

    // Set the Systick clock to not div by 8
    //LL_SYSTICK_SetClkSource(LL_SYSTICK_CLKSOURCE_HCLK_DIV8);

    // Enable Systick int
    LL_SYSTICK_EnableIT();

    // Set the Load value and enable Systick
    //LL_InitTick(8000000, 1000);
    LL_Init1msTick(8000000);

    while(1)
    {
        delay_ms(1000);
        LL_GPIO_TogglePin(GPIOC, LL_GPIO_PIN_13);
    }
}