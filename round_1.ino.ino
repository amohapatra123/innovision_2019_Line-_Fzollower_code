/*
 * This is a very basic code for a line follower robot 
 */

#define black 1
#define white 0

//sensor pins
const int IRL = A0;
const int IRR = A1;
const int IRM = A2;


//Motor control pins-
const int pwmA = 5;
const int MOT0 = 6;
const int MOT1 = 7;
const int MOT2 = 8;
const int MOT3 = 9;
const int pwmB = 10;
void setup() {
  pinMode(MOT0, OUTPUT);
  pinMode(MOT1, OUTPUT);
  pinMode(MOT2, OUTPUT);
  pinMode(MOT3, OUTPUT);
  pinMode(IRL, INPUT);
  pinMode(IRR, INPUT);
  analogWrite(pwmA, 60);
  analogWrite(pwmB, 60);
}
void loop() {

  int S1 = digitalRead(IRL);
  int S2 = digitalRead(IRR);
  int S3 = digitalRead(IRM);
  // print the sensor values:

  //Conditions to drive line folower appropriately
  if ((S1 == black &&  S2 == white) ||(S1 == black &&  S2 == black && S3==white)) {
    //forward
    digitalWrite(MOT0, LOW);
    digitalWrite(MOT1, HIGH);
    digitalWrite(MOT2, LOW); 
    digitalWrite(MOT3, HIGH);
  } 
  else if ((S1== black && S2== white && S3==black) || (S1== black && S2==white && S3==white)) {
    //right
    digitalWrite(MOT0, LOW);
    digitalWrite(MOT1, HIGH);
    digitalWrite(MOT2, LOW);
    digitalWrite(MOT3, LOW);
  } 
   else if (S1==white && S2==black && S3==white) {   
    //left  
    digitalWrite(MOT0, LOW);   
    digitalWrite(MOT1, LOW);    
    digitalWrite(MOT2, LOW);    
    digitalWrite(MOT3, HIGH);
   }
 

}
