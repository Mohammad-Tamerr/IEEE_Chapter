#include <stdint.h>
#include "stm32f103x6.h"
#include "Stm32_F103C6_GPIO.h"
#include "lcd.h"

void clock_init()
{
	RCC_GPIOA_CLK_EN();
	RCC_GPIOB_CLK_EN();
}

void wait_ms(uint32_t time){
	uint32_t i,j;
	for(i=0;i<time;i++)
		for(j=0;j<255;j++);
}

int main(void)
{
	clock_init();
	lcd_init();
	while(1)
	{
		lcd_set_position(0, 0);
		lcd_send_string("Lcd test->");
		wait_ms(2000);

		lcd_clear();

		lcd_set_position(0, 0);
		lcd_send_string("Say hello to my");
		lcd_set_position(1, 0);
		lcd_send_string("little friend");
		wait_ms(4000);

		lcd_clear();
	}
}
