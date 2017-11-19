//leds e LDRS testados e funcionando
#include <msp430g2553.h>

#define LED1 BIT1
#define LED2 BIT2
#define LDR1 BIT3
#define LDR2 BIT4
#define MOTOR_R BIT5
#define MOTOR_L BIT7
#define LEDS (LED1|LED2)

#define LED_TESTE1 BIT0 // led para testes
#define LED_TESTE2 BIT6 // led para testes
#define LED_TESTES (LED_TESTE1|LEDS_TESTE2)

int main ()
{
    float i=1.9; // i e j = luminosidade natural do local, varia de tipos de LDR, consultar datasheet
    float j=1.9;
    int Valorlido_LDR1;
    int Valorlido_LDR2;
  
   WDTCTL = WDTPW + WDTHOLD; // Para WDT

// ----------CONFIGURAÇÃO DO TIMERA - PWM ----------
  DCOCTL  = 0;             // Select lowest DCOx and MODx settings
  BCSCTL1 = CALBC1_8MHZ;    //MCLK e SMCLK pode ser de 1 ou 8 MHZ
  DCOCTL = CALDCO_8MHZ;   //MCLK e SMCLK pode ser de 1 ou 8MHZ
  TACTL |= MC_0;
  TA0CCR0 = 62500-1; //10000-1;
  TA0CTL = TASSEL_2 + ID_3 + MC_3 + TAIE; 

 // ------ LEDS PARA TESTE ------
  P1OUT &= ~LED1;  
  P1DIR |= LED1;
  P1OUT &= ~LED2;
  P1DIR |= LED2;
  
 // ------ MOTOR----------------
  P1OUT &= ~MOTOR_R; // MOTOR DIREITO
  P1DIR |= MOTOR_R;
  P1OUT &= ~MOTOR_L; // MOTOR ESQUERDO
  P1DIR |= MOTOR_L;
  
 //-------LEDS GIADORES-----
  P1OUT |= LEDS;
  P1DIR |= LEDS;
  
  
    while(1)
    {
          Valorlido_LDR1=P1IN&LDR1; // vai receber o valor lido do ldr1
          Valorlido_LDR2=P1IN&LDR2;// vai receber o valor lido do ldr2
          P1OUT ^=LEDS;  //leds sempre acesso

          
          while((TA0CTL & TAIFG)==0); // COMEÇA PWM

          
              if (Valorlido_LDR1<=j && Valorlido_LDR2<=i) { // os dois na linha preta -- motores param
                P1OUT &= ~MOTOR_R;// desliga motor direito
                P1OUT &= ~MOTOR_L; // desliga motor esquerdo
                P1OUT &= ~LED_TESTES;
              }
              
            else if (Valorlido_LDR1>j && Valorlido_LDR2>i){ // os dois fora da linha preta -- motores ligam
                P1OUT ^= MOTOR_R;
                P1OUT ^= MOTOR_L;
                P1OUT ^= LED_TESTES;
              }
              
           else if (Valorlido_LDR1<=j &&Valorlido_LDR2>i){ // motor esquerdo liga, motor direito desliga
               P1OUT ^= MOTOR_R;
               P1OUT &= ~MOTOR_L;
               P1OUT ^= LED_TESTE1;
               P1OUT &= ~LED_TESTE2;
              }

          else if (Valorlido_LDR1>j &&Valorlido_LDR2<=i){ // motor esquerdo desliga, motor direito liga
              P1OUT &= ~MOTOR_R;
              P1OUT ^= MOTOR_L;
              P1OUT &= LED_TESTE1;
              P1OUTR ^= LED_TESTE2;
              }
            
          TA0CTL &= ~TAIFG;
            }
  return 0;
   
}

