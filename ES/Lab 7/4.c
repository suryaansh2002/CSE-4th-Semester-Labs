#include <LPC17XX.h>
#define FIRSTSEG 0 << 23;
#define SECONDSEG 1 << 23;
#define THIRDSEG 2 << 23;
#define FOURTHSEG 3 << 23;
unsigned int dig_1 = 0x00;
unsigned int dig_2 = 0x00;
unsigned int dig_3 = 0x00;
unsigned int dig_4 = 0x00;
unsigned int i, dig_count = 0, temp1 = 0x00, one_sec_flag = 0x00;
unsigned int array_dec[16] = {0x3F, 0x06, 0x5B, 0x4F, 0x66, 0x6D,
                              0x7D, 0x07, 0x7F, 0x6F, 0x77, 0x7C, 0x39, 0x5E, 0x79, 0x71};
unsigned long int temp2 = 0x0;

void initTimer0(void)
{
  /*Assuming that PLL0 has been setup with CCLK = 100Mhz and PCLK =
  25Mhz.*/
  LPC_SC->PCONP |= (1 << 1); // Power up TIM0. By default TIM0 and TIM1 are
  LPC_SC->PCLKSEL0 |= 0x3;   // Set PCLK for timer = CCLK/4 = 100/4
  LPC_TIM0->CTCR = 0x0;
  LPC_TIM0->PR = PRESCALE; // Increment LPC_TIM0->TC at every 24999+1 clock
  // 25000 clock cycles @25Mhz = 1 mS
  LPC_TIM0->TCR = 0x02; // Reset Timer
}

void delayMS(unsigned int seconds) // Using Timer0
{
  LPC_TIM0->TCR = 0x02; // Reset Timer
  LPC_TIM0->TCR = 0x01; // Enable timer
  while (LPC_TIM0->TC < seconds)
    ;                   // wait until timer counter reaches
  LPC_TIM0->TCR = 0x00; // Disable timer
}


void display(void)
{
    if (dig_count == 0x01)
    {
        temp1 = dig_1;
        LPC_GPIO1->FIOPIN = FIRSTSEG;
    }
    if (dig_count == 0x02)
    {
        temp1 = dig_2;
        LPC_GPIO1->FIOPIN = SECONDSEG;
    }
    if (dig_count == 0x03)
    {
        temp1 = dig_3;
        LPC_GPIO1->FIOPIN = THIRDSEG;
    }
    if (dig_count == 0x04)
    {
        temp1 = dig_4;
        LPC_GPIO1->FIOPIN = FOURTHSEG;
    }
    temp1 &= 0x0F;
    temp2 = array_dec[temp1];
    temp2 <<= 4;
    LPC_GPIO0->FIOPIN = temp2;
    for (i = 0; i < 1000; i++);
    LPC_GPIO0->FIOCLR = 0x00000FF0;
}

int main()
{
    LPC_GPIO0->FIODIR |= 0xFF << 4;
    LPC_GPIO1->FIODIR |= 15 << 23;
    while (1)
    {
        delayMS();
        dig_count += 1;
        if (dig_count == 0x05)
        {
            dig_count = 0x01;
            one_sec_flag = 0xFF;
        }
        if ((LPC_GPIO2->FIOPIN & 1))
        {
            if (one_sec_flag == 0xFF)
            {
                one_sec_flag = 0x00;
                dig_1 += 1;
                if (dig_1 > 0xF)
                {
                    dig_1 = 0;
                    dig_2 += 1;
                    if (dig_2 > 0xF)
                    {
                        dig_2 = 0;
                        dig_3 += 1;
                        if (dig_3 > 0xF)
                        {
                            dig_3 = 0;
                            dig_4 += 1;
                            if (dig_4 > 0xF)
                            {
                                dig_4 = 0;
                            }
                        }
                    }
                }
            }
        }
        else if (!(LPC_GPIO2->FIOPIN & 1))
        {
            if (one_sec_flag == 0xFF)
            {
                one_sec_flag = 0x00;
                dig_1 -= 1;
                if (dig_1 == 0x0)
                {
                    dig_1 = 0xF;
                    dig_2 -= 1;
                    if (dig_2 == 0x0)
                    {
                        dig_2 = 0xF;
                        dig_3 -= 1;
                        if (dig_3 == 0x0)
                        {
                            dig_3 = 0xF;
                            dig_4 -= 1;
                            if (dig_4 == 0x0)
                            {
                                dig_4 = 0xF;
                            }
                        }
                    }
                }
            }
        }
        display();
    }
}
