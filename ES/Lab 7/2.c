#include <LPC17xx.h>
#include <stdio.h>
#define PRESCALE (25000000 - 1) // 25000 PCLK clock cycles to increment TC by 1

unsigned int seg_select[4] = {0 << 23, 1 << 23, 2 << 23, 3 << 23};

int dig1 = 0x09, dig2 = 0x09, dig3 = 0x09, dig4 = 0x09;

unsigned int seg_count = 0x00, temp1 = 0x00;

unsigned char arr_dec[10] = {0x3F, 0x06, 0x5B, 0x4F, 0x66, 0x6D, 0x7D, 0x07, 0x7F, 0x6F};

unsigned long int i = 0;
void delay(void);
void display(void);

void initTimer0(void)
{
	/*Assuming that PLL0 has been setup with CCLK = 100Mhz and PCLK =
	25Mhz.*/
	LPC_SC->PCONP |= (1 << 1); // Power up TIM0. By default TIM0 and TIM1 are
	// LPC_SC->PCLKSEL0 &= ~(0x0<<3); //Set PCLK for timer = CCLK/4 = 100/4
	LPC_TIM0->CTCR = 0x0;
	LPC_TIM0->PR = PRESCALE; // Increment LPC_TIM0->TC at every 24999+1 clock
	// 25000 clock cycles @25Mhz = 1 mS
	LPC_TIM0->TCR = 0x02; // Reset Timer
}

void delayMS(unsigned int milliseconds) // Using Timer0
{
	LPC_TIM0->TCR = 0x02; // Reset Timer
	LPC_TIM0->TCR = 0x01; // Enable timer
	while (LPC_TIM0->TC < milliseconds);				  // wait until timer counter reaches
	LPC_TIM0->TCR = 0x00; // Disable timer
}

int main(void)
{
	SystemInit();
	SystemCoreClockUpdate();
	initTimer0();

	LPC_PINCON->PINSEL0 &= 0xFF0000FF;
	LPC_PINCON->PINSEL3 &= 0xFFC03FFF;

	LPC_GPIO0->FIODIR |= 0x00000FF0;
	LPC_GPIO1->FIODIR |= 0x07800000;

	while (1)
	{
		delayMS(1000);
		display();
		seg_count += 1;
		if (seg_count == 0x04)
		{
			seg_count = 0x00;
			dig1 -= 1;
			if (dig1 < 0)
			{
				dig1 = 0x09;
				dig2 -= 1;
				if (dig2 < 0)
				{
					dig2 = 0x09;
					dig3 -= 1;
					if (dig3 < 0)
					{
						dig3 = 0x09;
						dig4 -= 1;
						if (dig4 < 0)
						{
							dig4 = 0x09;
						} // eod4
					}	  // eod3
				}		  // eod2
			}			  // eod1
		}				  // eosegcount
	}					  // eowhile
} // eomain

void display(void)
{
	LPC_GPIO1->FIOPIN = seg_select[seg_count];
	if (seg_count == 0x00)
	{
		temp1 = dig1;
	}
	else if (seg_count == 0x01)
	{
		temp1 = dig2;
	}
	else if (seg_count == 0x02)
	{
		temp1 = dig3;
	}
	else if (seg_count == 0x03)
	{
		temp1 = dig4;
	}

	LPC_GPIO0->FIOPIN = arr_dec[temp1] << 4;
}
