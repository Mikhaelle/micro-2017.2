#include <msp430g2553.h>

#define MOTOR_R BIT1
#define MOTOR_L BIT2
#define LED1 BIT0
#define LED2 BIT6



int main(void)
{
  WDTCTL = WDTPW + WDTHOLD; // Stop WDT
  
  DCOCTL  = 0;             // Select lowest DCOx and MODx settings
  BCSCTL1 = CALBC1_1MHZ;    //MCLK e SMCLK @ 1MHz
  DCOCTL = CALDCO_1MHZ;   //MCLK e SMCLK @ 1MHz
  P1OUT &= ~LED1;
  P1DIR |= LED1;
  P1OUT &= ~LED2;
  P1DIR |= LED2;
  P1OUT &= ~MOTOR_R;
  P1DIR |= MOTOR_R;
  P1OUT &= ~MOTOR_L;
  P1DIR |= MOTOR_L;
  TACTL |= MC_0;
  TA0CCR0 = 62500-1; //10000-1;
  TA0CTL = TASSEL_2 + ID_3 + MC_1 + TAIE;
  while(1)
  {
    while((TA0CTL & TAIFG)==0);
   // motor(2000);
   P1OUT ^= MOTOR_R;
    P1OUT ^= MOTOR_L;
    P1OUT ^= LED1;
    P1OUT ^= LED2;
  TA0CTL &= ~TAIFG;
     
  }
  return 0;
}
