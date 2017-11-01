// Canal 0 do TIMER A terá interrupção a cada 100 cycles
// Periodo de contagem da Interrupção: 100 / 1.000.000 = 0.1 ms
TACCTL0 = CCIE;                           // CCR0 habilitar interrupção
TACCR0 = 99;
TACTL = TASSEL_2 + MC_1;                  // Start Timer, SMCLK, Up Mode

// Função Interrupção
__interrupt void Timer_A (void)
{
  // Periodo do Pwm: 101 x 0.1 ms = 10.1 ms
  pwm_count++;
  if (pwm_count >= MAX_COUNT) {
    pwm_count=0;
    P1OUT |= LEFT_MOTOR;      // Ligar Left Motor
    P1OUT |= RIGHT_MOTOR;     // Ligar Right Motor
  }
  if (pwm_count == pwm_m1) {
    P1OUT &= ~LEFT_MOTOR;     // Desligar Left Motor
  }    

  if (pwm_count == pwm_m2) {
    P1OUT &= ~RIGHT_MOTOR;    // Desligar Right Motor
  }
}