const int MOTOR1 = P1_0;
const int MOTOR2 = P1_1;

void setup() {                
  pinMode(MOTOR1, OUTPUT); 
  pinMode(MOTOR2, OUTPUT);
}

void loop() {
        
		//if  (LDR1= 1 && LDR2 =0 && LDR3= 1 ){ 
				digitalWrite(MOTOR1, HIGH); 
				digitalWrite(MOTOR2, HIGH);  
				delay(2000);
			//}else if(LDR1=0  && LDR2 =1 && LDR3= 1){
			
				digitalWrite(MOTOR1, LOW); 
				digitalWrite(MOTOR2, HIGH);
				delay(2000);
				
			//}else if(LDR1=0  && LDR2 =0 && LDR3= 1){
			
				digitalWrite(MOTOR1, LOW); 
				digitalWrite(MOTOR2, HIGH);
			delay(2000);
			//}else if(LDR1=1  && LDR2 =1 && LDR3= 0){
			  
				digitalWrite(MOTOR1, HIGH); 
				digitalWrite(MOTOR2, LOW);
				delay(2000);
			//}else if(LDR1=1  && LDR2 =0 && LDR3= 0){
			  
				digitalWrite(MOTOR1, HIGH); 
				digitalWrite(MOTOR2, LOW);
			delay(2000);
		 //}else {
			digitalWrite(MOTOR1, LOW); 
			digitalWrite(MOTOR2, LOW);
			delay(2000);
		  }
            
 // return (MOTOR1, MOTOR2);
//}