#include <LedControl.h>
#include <Servo.h>

//blue wire = vcc
//orange wire =trig
//long white = echo
//short white = gnd
int side = 0;
int stat = 0; //0 is +, 1 is -
const int trigPin = 13; // Trigger Pin of Ultrasonic Sensor
const int echoPin = 12; // Echo Pin of Ultrasonic Sensor
const int servoPin = 3;

const int DIN = 7;
const int CS = 6;
const int CLK = 5;

byte middleface[8] = {B00111100,B01000010,B10110101,B10100001,B10100001,B10110101,B01000010,B00111100};
byte rightface1[8] = {B00111100,B01000010,B10000001,B10110101,B10100001,B10100001,B01110110,B00111100};
byte rightface2[8] = {B00111100,B01000010,B10000001,B10000001,B10110101,B10100001,B01100010,B00111100};
byte leftface1[8] = {B00111100,B01110110,B10100001,B10100001,B10110101,B10000001,B01000010,B00111100};
byte leftface2[8] = {B00111100,B01100010,B10100001,B10110101,B10000001,B10000001,B01000010,B00111100};

LedControl lc = LedControl(DIN, CLK, CS, 1);
Servo servo;

void setup() {
   Serial.begin(9600); // Starting Serial Terminal
   lc.shutdown(0,false);       //The MAX72XX is in power-saving mode on startup
   lc.setIntensity(0,15);      // Set the brightness to maximum value
   lc.clearDisplay(0);   
   servo.attach(servoPin);  
   servo.write(side); //Starting angle
    
}

void loop() {
   
   long duration, inches;
   pinMode(trigPin, OUTPUT);
   digitalWrite(trigPin, LOW);
   
   delayMicroseconds(2);
   digitalWrite(trigPin, HIGH);
   delayMicroseconds(10);
   digitalWrite(trigPin, LOW);
   pinMode(echoPin, INPUT);
   duration = pulseIn(echoPin, HIGH);
   inches = microsecondsToInches(duration);  
   
   Serial.print(inches);
   Serial.print("in, ");
   Serial.println();
   Serial.println(side);
   if(side <= 18){
      for(int j = 0; j<8; j++){
          lc.setRow(0, j, leftface2[j]);
      }
    }else if(side > 18 && side <= 36){
      for(int j = 0; j<8; j++){
          lc.setRow(0, j, leftface1[j]);
      }
    }else if(side > 36 && side <= 54){
      for(int j = 0; j<8; j++){
          lc.setRow(0, j, middleface[j]);
      }
    }else if(side > 54 && side <= 72){
      for(int j = 0; j<8; j++){
          lc.setRow(0, j, rightface1[j]);
      }
    }else if(side > 72 && side <= 90){
      for(int j = 0; j<8; j++){
          lc.setRow(0, j, rightface2[j]);
      }
   }
   if(inches<=8){
    Serial.print("In range");
   }else{
    servo.write(side);
    if(stat == 0){
      side = side + 5;
    }else if(stat == 1){
      side = side - 5;
    }

   }
   if(side == 0){
    stat = 0;
   }else if(side == 90){
    stat = 1;
   }
   delay(50);
}

long microsecondsToInches(long microseconds) {
   return microseconds / 74 / 2;
}
