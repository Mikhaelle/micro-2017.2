#include<msp430g2553.h>

volatile unsigned long i;

#define StartTimer()    TACTL |= MC_1; //START TIMER IN UP MODE
#define StopTimer()        TACTL |= MC_0;
#define LDR1 BIT1   // LDR1
#define LDR2 BIT2   // LDR2
#define LDR3 BIT3   // LDR3
#define MOTOR1 BIT4
#define MOTOR2 BIT5


void main(void)
{
    // Turn offf WDT
    WDTCTL = WDTPW + WDTHOLD;
    // Select DCO@1MHz as clock sources
    DCOCTL = CALDCO_1MHZ;
    BCSCTL1 = CALBC1_1MHZ;

    // Initialise Timer_A for PWM output
      TACTL = TASSEL_2 ;                         // clock = SMCLK 

      TACCTL1 = CM_0 | OUTMOD_7    ;               // CM_0: Compare mode (no capture mode)
                                                // OUTMOD_7 set/rest mode PWm
      TACCR0 = 120;                             // 8-bit counter from 00h to FFh
    //sri Notes: Usually this goes as PWM period
    // Set P1.2 as output for PWM signals

      P1DIR |= BIT2;                            // Pin4-P1.2/TA0.1 is output
      P1SEL |= BIT2;                          // Pin4-P1.2/TA0.1 is TA1 output WITH PWM functionality
    //sri Notes: P1.1 cannot be used for PWM output

      TACCR1 = 60;

    //Sri Notes:This combination gives a PWM signal of 8.2 with 50% duty cycle.
      StartTimer();

  
  
  // PRETO = 0
    //LUZ = 1
    //MOTOR1 - ESQUERDA
    //MOTOR2 - DIREITA
    
const int MOTOR1 = P1_1;
const int MOTOR2 = P1_2;

void setup() {                
  pinMode(MOTOR1, OUTPUT); 
  pinMode(MOTOR2, OUTPUT);
}
    
void controle_motor(void){
        
    if  (LDR1= 1 && LDR2 =0 && LDR3= 1 ){ 
      
        digitalWrite(MOTOR1, HIGH); 
        digitalWrite(MOTOR2, HIGH);  
        
      }else if(LDR1=0  && LDR2 =1 && LDR3= 1){
      
        digitalWrite(MOTOR1, LOW); 
        digitalWrite(MOTOR2, HIGH);
        
      }else if(LDR1=0  && LDR2 =0 && LDR3= 1){
      
        digitalWrite(MOTOR1, LOW); 
        digitalWrite(MOTOR2, HIGH);
     
      }else if(LDR1=1  && LDR2 =1 && LDR3= 0){
        
        digitalWrite(MOTOR1, HIGH); 
        digitalWrite(MOTOR2, LOW);
        
      }else if(LDR1=1  && LDR2 =0 && LDR3= 0){
        
        digitalWrite(MOTOR1, HIGH); 
        digitalWrite(MOTOR2, LOW);
    
     }else {
      digitalWrite(MOTOR1, LOW); 
      digitalWrite(MOTOR2, LOW);
      }
            
  return (MOTOR1, MOTOR2);
}
