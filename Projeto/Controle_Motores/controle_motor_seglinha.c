        // PRETO = 0
		//LUZ = 1
		//MOTOR1 - ESQUERDA
		//MOTOR2 - DIREITA
		
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

    