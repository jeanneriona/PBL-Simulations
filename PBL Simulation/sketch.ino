#include <ESP32Servo.h>
#define Led 13

Servo Baseservo;
Servo Joint1servo;
Servo Joint2servo;
Servo Endservo;

int control1 = 15;
int control2 = 2;
int control3 = 4;
int control4 = 32;
const int trig = 12;
const int echo = 14;

int Base =0;
int joint1 = 0;
int joint2 = 0;
int End = 0;
int duration = 0;
int distance = 0;

void setup() {
  Serial.begin(115200);
  pinMode(Led, OUTPUT);
  pinMode(trig, OUTPUT);
  pinMode(echo, INPUT);
  Baseservo.attach(26);
  Joint1servo.attach(25);
  Joint2servo.attach(33);
  Endservo.attach(27);
}

void loop() {
  Base = analogRead(control1);
  joint1 = analogRead(control2);
  joint2 = analogRead(control3);
  End = analogRead(control4);
  Base = map(Base, 0, 4079, 0, 180);
  joint1 = map(joint1, 0, 4079, 0, 180);
  joint2 = map(joint2, 0, 4079, 0, 180);
  End = map(End, 0, 4079, 0, 180);
  digitalWrite(trig, LOW);
  delayMicroseconds(0);
  digitalWrite(trig, HIGH);
  delayMicroseconds(0);
  digitalWrite(trig, LOW);
  duration = pulseIn(echo, HIGH);
  distance = (duration/2)/29.1;
  if (Base >= 1){
  Baseservo.write(Base);
  delay(500);
  }
  if (joint1 >= 1){
  Joint1servo.write(joint1);
  delay(500);
  }
  if (joint2 >= 1){
  Joint2servo.write(joint2);
  delay(500);
  }
  else{
    Baseservo.write(0);
    Joint1servo.write(0);
    Joint2servo.write(0);
  }
  if (distance <= 200){
    digitalWrite(Led, HIGH);
    Endservo.write(End);
  }
else{
  digitalWrite(Led, LOW);
  Endservo.write(0);
} 
}
