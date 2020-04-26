#include<Arduino.h>
#include<SoftwareSerial.h>

//Initialization of variables and pin Values
int count = 0;
const int trigPin1 = 7;
const int echoPin1 = 6;
const int trigPin2 = 8;
const int echoPin2 = 11;
const int trigPin3 = 12;
const int echoPin3 = 13;
long duration1, duration2, duration3;
int distance1, distance2, distance3;

SoftwareSerial gsm(9, 10); //Defining RX, TX pins

void setup() 
{
  pinMode(trigPin1, OUTPUT);
  pinMode(echoPin1, INPUT);
  pinMode(trigPin2, OUTPUT);
  pinMode(echoPin2, INPUT);
  pinMode(trigPin3, OUTPUT);
  pinMode(echoPin3, INPUT);
  Serial.begin(9600);
  gsm.begin(9600);
}

void loop() 
{
  //Calculating distances based on Ultrasonic Sensor value
  digitalWrite(trigPin1, LOW); 
  delayMicroseconds(2);
  digitalWrite(trigPin1, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin1, LOW);
  duration1 = pulseIn(echoPin1, HIGH);
  distance1 = duration1*0.034/2;
  delay(100);
  
  digitalWrite(trigPin2, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin2, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin2, LOW);
  duration2 = pulseIn(echoPin2, HIGH);
  distance2 = duration2*0.034/2;
  delay(100);
  
  digitalWrite(trigPin3, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin3, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin3, LOW);
  duration3 = pulseIn(echoPin3, HIGH);
  distance3 = duration3*0.034/2;
  delay(100);

  Serial.println((String)distance1 + "," + distance2 + "," + distance3 + "*");
  delay(1000);

  
  if(distance1 < 9 || distance2 < 9 || distance3 < 9)
  {
    count = 1;
  }
  if(count == 1)
  {
    SendMessage();
  }
  count=0;
}

//defining function to send Message through GSM Module 
void SendMessage()
{
  gsm.println("AT");
  delay(1000);
  gsm.println("AT+CMGF=1");    //Sets the GSM Module in Text Mode
  delay(1000);  // Delay of 1000 milli seconds or 1 second
  gsm.println("AT+CMGS=\"+919438864526\"\r"); // Replace x with mobile number
  delay(1000);
  gsm.print("Dustbin Full!!!");// The SMS text you want to send
  delay(1000);
  gsm.println("\x1A");// ASCII code of CTRL+Z
  delay(1000);
}
