#include <Servo.h>
#define S0 2
#define S1 3
#define S2 4
#define S3 5
#define sensorOut 6
//AUTHORS: RAMKARTIKEYA,AMRUTH,MITHILA,VINUTHNA
Servo topServo;
Servo bottomServo;
int frequency = 0;
int color=0;
void setup() {
  pinMode(S0, OUTPUT);
  pinMode(S1, OUTPUT);
  pinMode(S2, OUTPUT);
  pinMode(S3, OUTPUT);
  pinMode(sensorOut, INPUT);

  digitalWrite(S0, HIGH);
  digitalWrite(S1, LOW);
  topServo.attach(7);
  bottomServo.attach(8);
  Serial.begin(9600);
}
void loop() {

  topServo.write(124);
  
  delay(4000);
  
  for(int i = 124; i > 74; i--) {
    topServo.write(i);
    delay(2);
  }
  delay(1500);
   
  color = readColor();
  delay(10);  
  switch (color) {
    case 1:
    bottomServo.write(50);//pink
    break;
    case 2:
    bottomServo.write(75);//yellow
    break;
    case 3:
    bottomServo.write(100);
    break;
    case 4:
    bottomServo.write(100);//green
    break;
    case 5:
    bottomServo.write(150);
    break;
    case 6:
    bottomServo.write(125);//blue
    break;
    
    case 0:
    Serial.print(" NO COLOUR");
    break;
  }
  delay(300);
  
  for(int i = 74; i > 31; i--) {
    topServo.write(i);
    delay(2);
  } 
  delay(3000);
  
  for(int i = 31; i < 124; i++) {
    topServo.write(i);
    delay(2);
  }
  color=0;
}
int readColor() {
  // Setting red filtered photodiodes to be read
  digitalWrite(S2, LOW);
  digitalWrite(S3, LOW);
  
  frequency = pulseIn(sensorOut, LOW);
  int R = frequency;
  
  Serial.print("R= ");//printing name
  Serial.print(frequency);//printing RED color frequency
  Serial.print("  ");
  delay(50);
  // Setting Green filtered photodiodes to be read
  digitalWrite(S2, HIGH);
  digitalWrite(S3, HIGH);
  // Reading the output frequency
  frequency = pulseIn(sensorOut, LOW);
  int G = frequency;
  // Printing the value on the serial monitor
  Serial.print("G= ");//printing name
  Serial.print(frequency);//printing RED color frequency
  Serial.print("  ");
  delay(50);
  // Setting Blue filtered photodiodes to be read
  digitalWrite(S2, LOW);
  digitalWrite(S3, HIGH);
  // Reading the output frequency
  frequency = pulseIn(sensorOut, LOW);
  int B = frequency;
  // Printing the value on the serial monitor
  Serial.print("B= ");//printing name
  Serial.print(frequency);//printing RED color frequency
  Serial.println("  ");
  delay(50);
/*  if(R<45 & R>32 & G<65 & G>55){
    color = 1; // Red
  }
  if(G<590 & G>43 & B<47 &B>35){
    color = 2; // Orange
  }
 else if(R<900 & R>870 & G<560 & G>430){
    color = 3; // Green
  }
  if(R<730 & R>530 & G<540 & G>400){
    Serial.print("YELLOW");
    bottomServo.write(110);
    return 4; // Yellow
    Serial.print("YELLOW");
  }
  else if(R<56 & R>46 & G<65 & G>55){
    color = 5; // Brown
  }
  else if (G<58 & G>45 & B<40 &B>26){
    color = 6; 
  }// Blue bottomServo.write(75);*/
    if(R<45 & R>32 & G<65 & G>55){
    color = 1;    Serial.print("RED"); // Red
  }
 /* if(G<55 & G>43 & B<47 &B>35){
    color = 2;    Serial.print("ORANGE"); // Orange
  }*/
  else if(R<43 & R>40 & G<46 & G>43){
    color = 0;     Serial.print(" NO COLOUR");        // Green
  }
  else if(R<38 & R>24 & G<44 & G>30){
    color = 4; // Yellow
    
   
    if(R<33)
    {
      color =1;
      if(G>35){
        if(B>29)
        {
          color=5;
          Serial.print("ORANGE ");
          return 5;
        }
      Serial.print("PINK ");

      return 1; //pink
      }
      else 
      {
        color=2;
        Serial.print("YELLOW ");
        return 2;
      }
    }
     Serial.print("GREEN");
   // YELLOW 1ST
  }
  else if(R<56 & R>46 & G<65 & G>55){
    color = 5;
        Serial.print("BROWN");// Brown
  }
  else if (G<45 & G>35 & B<33 &B>23){
    color = 6; 
   
        Serial.print("BLUE ");// Blue
  }
  return color; 
 
}
