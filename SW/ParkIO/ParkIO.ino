#include <Ultrasonic.h>
#include "Arduino.h"
#define tl 3
#define el 2
#define tc 5
#define ec 4
#define tr 7
#define er 6


Ultrasonic s[5] = {Ultrasonic(0,0), Ultrasonic(0,0), Ultrasonic(0,0), Ultrasonic(0,0), Ultrasonic(0,0)};
 

////Sonar 1
//int echoPin1 = 2;
//int initPin1 = 3;
//int distance1 = 0;
//
////Sonar 2
//int echoPin2 = 4;
//int initPin2 = 5;
//int distance2 = 0;

int numTotalSpots = 10; // Get from database.

void setup() {
  Serial.begin (9600);
  for (int i = 0; i < 5; i++){
    s[i] = Ultrasonic(i*2, i*2+1);    
    s[i].initPinModes();
  }

}
bool is_car_parked(int dist){
  if (dist <= 10){
    return true;
  }
  return false;  
}
void loop() {
  //  Serial.print("L: ");
  //  distance1 = getDistance(initPin1, echoPin1);
  //  printDistance(distance1);
  //  delay(150);
  //
  //  Serial.print("C: ");
  //  distance2 = getDistance();
  //  printDistance(distance2);
  //  delay(150);
  for (int i = 0; i < 5; i++){
    bool currCarParked = is_car_parked(s[i].get_distance());
    if (currCarParked == true){
      //send msg to database
      Serial.print("Spot #: ");
      Serial.print(i);
      Serial.println(" Taken");
    }
  }
  Serial.println();
  
//  Serial.print("L: ");
//  distance1 = s1.get_distance();
//  s1.print_distance();
//  delay(150);
//
//  Serial.print("R: ");
//  distance2 = s2.get_distance();
//  s2.print_distance();
//  delay(150);
//  Serial.println(" ");
}



//int getDistance (int initPin, int echoPin) {
//
//  digitalWrite(initPin, HIGH);
//  delayMicroseconds(10);
//  digitalWrite(initPin, LOW);
//  unsigned long pulseTime = pulseIn(echoPin, HIGH);
//  int distance = (pulseTime / 2) / 29.1;
//  return distance;
//
//}
//
//void printDistance(int dist) {
//  if (dist >= 200 || dist <= 0 ) {
//    Serial.println(" Out of range");
//  }
//  else {
//    Serial.print(dist);
//    Serial.println(" cm");
//  }
//}
