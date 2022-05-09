#include <lpc17xx.h>
#include <time.h>
#include "lcdconfig.h"

int main(void) {
  
		int dice;
		int i=0;

    SystemInit();
    SystemCoreClockUpdate();
    lcd_init();
    lcd_comdata(0x80, 0);
    delay_lcd(800);
		
		while(1){
		srand(i);
		dice = (int) (1+rand()%6);
			if(!(LPC_GPIO2->FIOPIN & 1<<12))
			{
			lcd_comdata(dice+48, 1);
			delay_lcd(1200000);
			clear_ports();
			}
			delay_lcd(1200);
			lcd_comdata(0x01, 0);  // display clear 
			i++;
		}
}
