#include <msp430g2553.h>
#define LDR1 BIT1 // entradas P1
#define LDR2 BIT2

#define EN_R BIT0  //Entrada P2
#define EN_L BIT1
#define MOTOR_R BIT2 //saidas P2
#define MOTOR_L BIT3

#define LED1 BIT3 // saídas P2
#define LED2 BIT4
#define LEDS (LED1|LED2)

void main (void)
{
    float i=1; // i = luminosidade natural do local, varia de tipos de LDR
    float j=1.9;
  
    WDTCTL = WDTPW | WDTHOLD; // stop the WDT

    //------------------- Configure the Clocks -------------------//
    // Set DCO Clock = 8MHz                                       //
    if (CALBC1_8MHZ==0xFF)   // If calibration constant erased
    { 
      while(1);            // do not load, trap CPU!!
    } 
    DCOCTL  = 0;             // Select lowest DCOx and MODx settings
    BCSCTL1 = CALBC1_8MHZ;   // Set range
    DCOCTL  = CALDCO_8MHZ;   // Set DCO step + modulation 

    // Timer 0 Configurtion
    TACTL |= MC_0;                   // Stop Timer0_A3 
    TACTL  = TASSEL_2 + TAIE;        // TAR Clock = 1MHz,1MHz/8 = 125KHz,Enable Timer Interrupt
    CCTL1  = CCIE;                   // Enable interrupt for CCR1 
    CCR1   = 6150;                  // Load value 
    TACTL |= MC_2;                   // Start Timer0 in Continous Mode
    
   //----leds sempre acessos---
   P1OUT |= LEDS; // led é saida
   P1DIR |= LEDS; // 

   //configuração das portas
   P2SEL  &= ~EN_R;                
   P2SEL2 &= ~EN_R;                
   P2SEL  &= ~EN_L;               
   P2SEL2 &= ~EN_L;               
   //Motor direito
    P2DIR |=  MOTOR_R + EN_R;   // P2.0,P2.1 all output
    P2OUT &= ~MOTOR_R + EN_R;   // Clear P2.0,P2.1
   //Motor esquerdo
    P2DIR |=  MOTOR_L + EN_L;   // P2.2,P2.1 all output
    P2OUT &= ~MOTOR_L + EN_L;   // Clear P2.2,P2.1 
  
    while(1)
    {
          Valorlido_LDR1=P1IN&LDR1; // vai receber o valor lido do ldr1
          Valorlido_LDR2=P1IN&LDR2;// vai receber o valor lido do ldr2
          P1OUT ^=LEDS;  //leds sempre acesso

    if (Valorlido_LDR1<=j && Valorlido_LDR2<=i){ // os dois na linha preta -- motores param
        P2OUT &= ~EN_R;// desliga motor direito
        P2OUT &= ~EN_L; // desliga motor esquerdo
       
      }
    else if (Valorlido_LDR1>j && Valorlido_LDR2>i){ // os dois fora da linha preta -- motores ligam
        P2OUT |= EN_R;
        P2OUT |= EN_L;
      }
     else if (Valorlido_LDR1<=j &&Valorlido_LDR2>i){ // motor esquerdo liga, motor direito desliga
      P2OUT |= EN_R;
      P2OUT &= ~EN_L;
     }

     else if (Valorlido_LDR1>j &&Valorlido_LDR2<=i){ // motor esquerdo desliga, motor direito liga
      P2OUT &= ~EN_R;
      P2OUT |= EN_L
     }
     
  }
  return 0;
   
}

