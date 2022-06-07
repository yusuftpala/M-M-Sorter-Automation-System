
const int motorin=11;
const  int motorout=10;

const int bottomsolenoidin=6;     // 1. solenoid
const int bottomsolenoidout=7;    


const int midleftin=5;    //2rd Solenoid                                         
const int midleftout=4;   

const int midrightin=2;    // 3th Solenid
const int midrightout=3;  
int pwm=255;                         // PWM value to rotate Dc motor. Digital pins are 8 bit so the value is between 0-255 range
char data=0;                     // A letter will be entered from Serial Port screen

/*   w for white;
     y for yellow;
     g for green;
     r for red;
     n for navy blue;
     p for purple;
 
 */

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(motorin,OUTPUT);             
  pinMode(motorout,OUTPUT);
  pinMode(bottomsolenoidin,OUTPUT);
  pinMode(bottomsolenoidout,OUTPUT);
  pinMode(midleftin,OUTPUT);
  pinMode(midleftout,OUTPUT);
  pinMode(midrightin,OUTPUT);
  pinMode(midrightout,OUTPUT);

}

void loop() {
  // put your main code here, to run repeatedly:

 
  analogWrite(motorin,pwm);
  digitalWrite(motorout,LOW);

    
  
  if(Serial.available()>0){
    data=Serial.read();

                    switch (data) {

                      case 'w' :
                      
                      digitalWrite(5,HIGH);
                      digitalWrite(4,LOW);   //Solenoids works
                      digitalWrite(6,HIGH);
                      digitalWrite(7,LOW);
                      Serial.println("M&M is in white box");
                      delay(2000);

                      digitalWrite(5,LOW);    //Solenoids come back old position
                      digitalWrite(4,LOW);
                      digitalWrite(6,LOW);
                      digitalWrite(7,LOW);

                      delay(500);

                      
                      break;
                      
                      case 'y' :
                      digitalWrite(5,HIGH);    //Solenoids works
                      digitalWrite(4,LOW);
                      Serial.println("M&M is in the yellow box");
                       delay(2000);
                       digitalWrite(5,LOW);  //Solenoids come back old position
                       digitalWrite(4,LOW);
                       delay(500);
                       
                      break;
                      case 'g' :
                      digitalWrite(6,HIGH);    //Solenoids works
                      digitalWrite(7,LOW);

                      Serial.println("M&M is in the green box");
                      delay(2000);

                      digitalWrite(6,LOW);    //Solenoids come back old position
                      digitalWrite(7,LOW);
                      break;
                      
                      case 'r' :
                     Serial.println("M&M is in the red box");  //Solenoids come back old position
                     delay(2000);
                     break;

                     case 'n' :

                     digitalWrite(2,HIGH);   //Solenoids works
                     digitalWrite(3,LOW);
                     digitalWrite(6,HIGH);
                     digitalWrite(7,LOW);

                     Serial.println("M&M is in the navy blue box");

                     delay(2000);

                     digitalWrite(2,LOW);      //Solenoids come back old position
                     digitalWrite(3,LOW);
                     digitalWrite(6,LOW);
                     digitalWrite(7,LOW);
                       delay(500);

                     break;

                     case 'p' :
                     digitalWrite(2,HIGH);    //Solenoids works
                     digitalWrite(3,LOW);
                      
                      
                       Serial.println("M&M is in the purple box");
                       
                       delay(2000);

                     

                      digitalWrite(2,LOW);  //Solenoids come back old position
                      digitalWrite(3,LOW); 
                      delay(500);
                      
                      
                      
                      break; 
                      
                      }

    
    

    
    
    
  }
    

  

}
