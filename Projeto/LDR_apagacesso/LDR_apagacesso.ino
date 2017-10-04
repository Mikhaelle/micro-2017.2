#include <msp430g2553.h>
#define LDR BIT1
#define LED BIT0


int main()
{
  float i=1.9; // i = luminosidade natural do local
  float Valorlido;
  WDTCTL = WDTPW | WDTHOLD;
  P1OUT|= LED;
  P1DIR |= LED;
  
  while (1){
    Valorlido=P1IN&LDR; //Valor lido vai receber o valor lido do ldr
    if (Valorlido<=i){
      P1OUT ^= LED;
    }
    else {
      P1OUT &= ~LED;
    }
  }
  return 0;
}
