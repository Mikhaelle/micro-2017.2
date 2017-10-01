#include <msp430g2553.h>
#define LDR1 BIT1
#define LDR2 BIT3
#define LED1 BIT0
#define LED2 BIT6


int main()
{
  float i=1; // i = luminosidade natural do local
  float j=1.9;
  float Valorlido_LDR1, Valorlido_LDR2;
  WDTCTL = WDTPW | WDTHOLD;
  P1OUT |= LED1;
  P1DIR |= LED1;
  P1OUT |= LED2;
  P1DIR |= LED2;
  
  while (1){
     
    Valorlido_LDR1=P1IN&LDR1; // vai receber o valor lido do ldr1
    Valorlido_LDR2=P1IN&LDR2;// vai receber o valor lido do ldr2
    //Valorlido_LDR3=P1IN&LDR3; // vai receber o valor lido do ldr3
    
    if (Valorlido_LDR1<=j && Valorlido_LDR2<=i)
      {
        P1OUT ^= LED1;
        P1OUT ^= LED2;
      }
    else if (Valorlido_LDR1>j && Valorlido_LDR2>i)
      {
        P1OUT &= ~LED1;
        P1OUT &= ~LED2;
      }
     else if (Valorlido_LDR1<=j &&Valorlido_LDR2>i)
     {
       P1OUT ^= LED1;
       P1OUT &= ~LED2;
     }

     else if (Valorlido_LDR1>j &&Valorlido_LDR2<=i)
     {
       P1OUT ^= LED2;
       P1OUT &= ~LED1;
     }
     
  }
  return 0;
}
