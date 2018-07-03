
#include <Motor_Shield.h>
/*
* Ammus collision-avoiding Kasha 
*/


int i, j;

DCMotor Amotor(1);
DCMotor Bmotor(2);
DCMotor Cmotor(3);
DCMotor Dmotor(4);


// defines pins numbers
const int trigPin = 3;
const int echoPin = 10;
const int motorSpeed = 200;
const int led = 13;
const int buzzer = 2;
const int delayStep = 30;
int duration = 0;
int distance = 4;

// the setup routine runs once when you press reset:
void setup() {                
  // initialize the digital pin as an output.
  pinMode(led, OUTPUT);
  pinMode(trigPin, OUTPUT); // Sets the trigPin as an Output
  pinMode(echoPin, INPUT); // Sets the echoPin as an Input
  //pinMode(ledRed, OUTPUT); // Lights up on collission detected
  pinMode(buzzer, OUTPUT); // 
  
  
  Serial.begin(9600); 
  
  // random seed generated from A0
  randomSeed(analogRead(0));
}

// the loop routine runs over and over again forever:
void loop() {
  digitalWrite(led, LOW);
  // Ultrasound code goes here 
  // Clears the trigPin
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  // Sets the trigPin on HIGH state for 10 micro seconds
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(20);
  digitalWrite(trigPin, LOW);
  // Reads the echoPin, returns the sound wave travel time in microseconds
  duration = pulseIn(echoPin, HIGH);
  // Calculating the distance
  distance= duration*0.034/2;
  // Prints the distance in on the Serial Monitor
  Serial.println("Distance: ");
  Serial.println(distance);
  delay(10);
  

  // Activate the motor
  Forward(motorSpeed);  // move forward with default speed till
  if(distance < 40) {   // obstacle found within 40 cm
    Stop();
    tone(buzzer, 1000);  
    digitalWrite(led, HIGH);
    delay(delayStep*5);
    int j = (int) random(7);
    for( int i = 0; i<j; i++){
      if (j >3) {       // random right and left turn with a slight +ve bias to right
        digitalWrite(led, LOW);
        Right();
        delay(delayStep*5);
        digitalWrite(led, HIGH);
        delay(delayStep*5);
      }
      else {
        digitalWrite(led, LOW);
        Left();
        delay(delayStep*5);
        digitalWrite(led, HIGH);
        delay(delayStep*5);
      }
      //delay(100);
    }
   noTone(buzzer);
  }
  
}

void Forward(unsigned char Speed)
{
            Amotor.run(FORWARD);
            Bmotor.run(FORWARD);
            Cmotor.run(FORWARD);
            Dmotor.run(FORWARD);
            Amotor.setSpeed(Speed);                             
            Bmotor.setSpeed(Speed);
            Cmotor.setSpeed(Speed);
            Dmotor.setSpeed(Speed);
}

void Backward(unsigned char Speed)  // Robot runs in backward direction  
{
            Amotor.run(BACKWARD);
            Bmotor.run(BACKWARD);
            Cmotor.run(BACKWARD);
            Dmotor.run(BACKWARD);
            Amotor.setSpeed(Speed);                             
            Bmotor.setSpeed(Speed);
            Cmotor.setSpeed(Speed);
            Dmotor.setSpeed(Speed);
}

void Right(void)                      // Skid steer left turn.
{
           Amotor.run(FORWARD);
           Cmotor.run(BACKWARD);
           Bmotor.run(BACKWARD);
           Dmotor.run(FORWARD);
           Amotor.setSpeed(255);                             
           Bmotor.setSpeed(255);
           Cmotor.setSpeed(255);
           Dmotor.setSpeed(255); 
}

void Left(void)                      // Skid steer right turn.
{
           Amotor.run(BACKWARD);
           Cmotor.run(FORWARD);
           Bmotor.run(FORWARD);
           Dmotor.run(BACKWARD); 
           Amotor.setSpeed(255);                             
           Bmotor.setSpeed(255);
           Cmotor.setSpeed(255);
           Dmotor.setSpeed(255);   
}

void Right_Forward()                // Right side motor forward
{
          Amotor.run(FORWARD);
          Dmotor.run(FORWARD);
          Amotor.setSpeed(255);
          Dmotor.setSpeed(255);   
}

void Right_Backward()              // Right side motor backward
{
          Amotor.run(BACKWARD);
          Dmotor.run(BACKWARD);
          Amotor.setSpeed(255);
          Dmotor.setSpeed(255);   
}
  
void Left_Forward()                // Left side motor forward
{
          Bmotor.run(FORWARD);
          Cmotor.run(FORWARD);
          Bmotor.setSpeed(255);
          Cmotor.setSpeed(255);   
}

void Left_Backward()               // Left side motor backward
{
          Bmotor.run(BACKWARD);
          Cmotor.run(BACKWARD);
          Bmotor.setSpeed(255);
          Cmotor.setSpeed(255);   
}
    
 void Stop(void)	            // All motor halt		
{
          Amotor.setSpeed(0);
          Bmotor.setSpeed(0);
          Cmotor.setSpeed(0);
          Dmotor.setSpeed(0);
}
  
