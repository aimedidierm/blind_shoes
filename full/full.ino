#include <Wire.h>
#include <Adafruit_MLX90614.h>
Adafruit_MLX90614 mlx = Adafruit_MLX90614();
//Sonar 1
int echoPin1 = 3;
int initPin1 = 2;
int distance1 =0;

//Sonar 2
int echoPin2 = 9;
int initPin2 = 7;
int distance2 =0;

int piezoPin = 8;
int vibrator = 4;

int isDisSensor = 0;
int isDisSensor2 = 0;
int tempp = 0;
void setup() {
  mlx.begin(); 
  pinMode(initPin1, OUTPUT);
  pinMode(echoPin1, INPUT);
  pinMode(initPin2, OUTPUT);
  pinMode(echoPin2, INPUT);
  pinMode(vibrator, OUTPUT);
}

void loop() {
  digitalWrite(vibrator,LOW);
  tempp = mlx.readObjectTempC();
  distance1 = getDistance(initPin1, echoPin1);
  distance2 = getDistance(initPin2, echoPin2);
  if (tempp >= 50){
    son1();
  }
  if (distance1 <= 30){
    son4();
  }
  if (distance1 <= 20){
    son5();
  }
  if (distance2 <= 30){
    son2();
  }
  if (distance2 <= 20){
    son3();
  }
}
int getDistance (int initPin, int echoPin){
 digitalWrite(initPin, HIGH);
 delayMicroseconds(10); 
 digitalWrite(initPin, LOW); 
 
 unsigned long pulseTime = pulseIn(echoPin, HIGH); 
 int distance = pulseTime/58;
 return distance;
 
}
void son1(){
  //Fire detected
  tone(piezoPin, 1000, 500);
  delay(1000);
  digitalWrite(vibrator,HIGH);
  delay(500);
  }
void son2(){
  //UP high distance
  tone(piezoPin, 1000, 500);
  delay(700);
  digitalWrite(vibrator,HIGH);
  delay(100);
  digitalWrite(vibrator,LOW);
  delay(100);
  digitalWrite(vibrator,LOW);
  delay(100);
  }
void son3(){
  //UP low distance
  tone(piezoPin, 1000, 500);
  delay(500);
  digitalWrite(vibrator,HIGH);
  delay(300);
  digitalWrite(vibrator,LOW);
  delay(300);
  digitalWrite(vibrator,LOW);
  delay(300);
  }
void son4(){
  //Down high distance
  tone(piezoPin, 1000, 500);
  delay(1500);
  digitalWrite(vibrator,HIGH);
  digitalWrite(vibrator,HIGH);
  delay(700);
  digitalWrite(vibrator,LOW);
  delay(700);
  digitalWrite(vibrator,LOW);
  delay(700);
  }
void son5(){
  //Down low distance
  tone(piezoPin, 1000, 500);
  delay(1300);
  digitalWrite(vibrator,HIGH);
  delay(1000);
  digitalWrite(vibrator,LOW);
  delay(1000);
  digitalWrite(vibrator,LOW);
  delay(1000);
  }