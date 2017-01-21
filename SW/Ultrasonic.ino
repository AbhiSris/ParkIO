/*
 * Ultrasonic.cpp - Library for receiving ultrasonic sensor values
 * Created by Abhi Srikantharajah Oct 4 2016
 */

#include "Arduino.h"
#define tl 3
#define el 2
#define tc 5
#define ec 4
#define tr 7
#define er 6

//Sonar 1
int echoPin1 =2;
int initPin1 =3;
int distance1 =0;

//Sonar 2
int echoPin2 =4;
int initPin2 =5;
int distance2 =0;

//Sonar 3
int echoPin3 =6;
int initPin3 =7;
int distance3 =0;

void setup() {
  Serial.begin (9600);
  pinMode(initPin1, OUTPUT);
  pinMode(echoPin1, INPUT);
  pinMode(initPin2, OUTPUT);
  pinMode(echoPin2, INPUT);
  pinMode(initPin3, OUTPUT);
  pinMode(echoPin3, INPUT);
}

void loop() {
Serial.print("L: ");
  distance1 = getDistance(initPin1, echoPin1);
  printDistance(distance1);
  delay(150);
    
  Serial.print("C: ");  
  distance2 = getDistance(initPin2, echoPin2);
  printDistance(distance2);
  delay(150);
  
   Serial.print("R: ");  
  distance3 = getDistance(initPin3, echoPin3);
  printDistance(distance3);
  delay(150);

  Serial.println(" ");
}

int getDistance (int initPin, int echoPin){

  digitalWrite(initPin, HIGH);
  delayMicroseconds(10); 
  digitalWrite(initPin, LOW); 
  unsigned long pulseTime = pulseIn(echoPin, HIGH); 
  int distance = (pulseTime/2) / 29.1;
  return distance;

}

void printDistance(int dist){
  if (dist >= 200 || dist <= 0 ){
    Serial.println(" Out of range");
  }
  else{
    Serial.print(dist);
    Serial.println(" cm");
  }
}
