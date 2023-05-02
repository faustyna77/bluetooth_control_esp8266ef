#include <Arduino.h>
#include <Motors.h>
#include <SoftwareSerial.h>
#include <ESP8266WiFi.h>
#define Pin3up 3

int Pin1=D3;
int Pin2=D4;
int Pin3=D1;
int Pin4=D2;
int Pin5=D5;
int Pin6=D6;

int Pin0=D0;

Motors lewyshieldM1A(Pin1);
Motors lewyshieldM1B(Pin2);
Motors lewyshieldM1AM1B(Pin1,Pin2);
Motors lewyshieldM2A(Pin3);
Motors lewyshieldM2B(Pin4);
Motors lewyshieldM2AM2B(Pin3,Pin4);
Motors prawyshieldM1A(Pin5);
Motors prawyshieldM1B(Pin6);
Motors prawyshieldM1AM1B(Pin5,Pin6);
Motors prawyshieldM2A(Pin0);
Motors prawyshieldM2B(Pin3up);
Motors prawyshieldM2AM2B(Pin0,Pin3up);




/*
const char* ssid = "----";
const char* password = "------";
SoftwareSerial bluetooth(D7, D8); // RX, TX
int ledPin = D6;

void setup() {
  pinMode(ledPin, OUTPUT);
  Serial.begin(9600);
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Connecting to WiFi...");
  }
  Serial.println("Connected to WiFi");
  bluetooth.begin(9600);
}

void loop() {
  if (bluetooth.available() > 0) {
    char receivedChar = bluetooth.read();
    int receiver=bluetooth.read();
    if (receivedChar == '2') {
      analogWrite(ledPin,receiver);
    }
    if(receivedChar=='3')
    {
      digitalWrite(ledPin,LOW);
    }
  }
}
*/
const char* ssid = "TAB";
const char* password = "faustyna";
SoftwareSerial bluetooth(D7, D8); // RX, TX
void setup()
{
  pinMode(Pin1,OUTPUT);
  pinMode(Pin2,OUTPUT);
  pinMode(Pin3,OUTPUT);
  pinMode(Pin4,OUTPUT);
  pinMode(Pin5,OUTPUT);
  pinMode(Pin6,OUTPUT);
  pinMode(Pin0,OUTPUT);
  pinMode(Pin3up,OUTPUT);
   Serial.begin(9600);
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Connecting to WiFi...");
  }
  Serial.println("Connected to WiFi");
  bluetooth.begin(9600);
}

void forward(int v1,int v2)
{
  lewyshieldM1AM1B.go(v1,v2);
      lewyshieldM2AM2B.go(v1,v2);
      prawyshieldM1AM1B.go(v1,v2);
      prawyshieldM2AM2B.go(v1,v2);

}
void backward(int v1,int v2)
{
  lewyshieldM1AM1B.go(v1,v2);
      lewyshieldM2AM2B.go(v1,v2);
      prawyshieldM1AM1B.go(v1,v2);
      prawyshieldM2AM2B.go(v1,v2);
}
void left(int v1,int v2)
{
      lewyshieldM1AM1B.go(v1,0);
      lewyshieldM2AM2B.go(v1,0);
      prawyshieldM1AM1B.go(v2,0);
      prawyshieldM2AM2B.go(v2,0);
}
void right(int v1,int v2)
{
   lewyshieldM1AM1B.go(v1,0);
      lewyshieldM2AM2B.go(v1,0);
      prawyshieldM1AM1B.go(v2,0);
      prawyshieldM2AM2B.go(v2,0);
}
void stop()
{
      lewyshieldM1AM1B.go(0,0);
      lewyshieldM2AM2B.go(0,0);
      prawyshieldM1AM1B.go(0,0);
      prawyshieldM2AM2B.go(0,0);
}



void loop()
{
  
    //analogWrite(ledPin1,150);
    ///analogWrite(ledPin2,100);
    //prosto pierwsza strona 
    
     
      //analogWrite(ledPin5,150);
       if (bluetooth.available() > 0) {
    char receivedChar = bluetooth.read();
    switch (receivedChar)
    {
    case '1':
      
 forward(255, 0);
      
      break;
    case '2':
    backward(0,255);
   



    
    
      break;
      case '3':
      left(0,255);
      break;

      case '4':
     right(255,0);
       
      break;
      case '5':
      lewyshieldM1AM1B.go(0,255);
      lewyshieldM2AM2B.go(255,0);
      prawyshieldM1AM1B.go(0,255);
      prawyshieldM2AM2B.go(255,0);
      break;
      case '6':
      lewyshieldM1AM1B.go(0,180);
      lewyshieldM2AM2B.go(180,0);
      prawyshieldM1AM1B.go(0,180);
      prawyshieldM2AM2B.go(180,0);
      break;
      case '7':
      lewyshieldM1AM1B.go(200,20);
      lewyshieldM2AM2B.go(20,200);
      prawyshieldM1AM1B.go(200,20);
      prawyshieldM2AM2B.go(20,200);
      break;
      case '8':
      lewyshieldM1AM1B.go(0,0);
      lewyshieldM2AM2B.go(0,0);
      prawyshieldM1AM1B.go(0,0);
      prawyshieldM2AM2B.go(0,0);
      break;
      case '9':
      lewyshieldM1AM1B.go(180,0);
      lewyshieldM2AM2B.go(180,0);
      prawyshieldM1AM1B.go(255,0);
      prawyshieldM2AM2B.go(255,0);
      break;
      default:

      stop();
      break;





      


    }
    
  }
      
  
}