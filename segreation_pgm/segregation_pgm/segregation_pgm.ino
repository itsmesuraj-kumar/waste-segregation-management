#include <Servo.h>

//Intializing Variables and Values
Servo wetDetectGate;
Servo metalDetectGate;
int wetSensorVal; 
int metalSensorVal;
float moisturePercentage;
int wetGatePos = 0;
int metalGatePos = 0;

void setup() {
  wetDetectGate.attach(11); //attaching wet sensor pin
  metalDetectGate.attach(10); //attaching metal sensor pin 
  pinMode(9, INPUT);
  pinMode(A0, INPUT);
  Serial.begin(9600);
}

void loop() {
  //Reading Sensor Values
  wetSensorVal = analogRead(A0);
  metalSensorVal = digitalRead(9);

  //Calculating moisture percentage based on wet sensor value
  moisturePercentage = ( 100 - ( ( wetSensorVal / 1023.00 ) * 100 ) );
  
  Serial.println(moisturePercentage);
  Serial.println(metalSensorVal);
  delay(1);

  //Operating servo motors based on sensor values  
  if(moisturePercentage > 10.00)
  {
    for (wetGatePos = 0; wetGatePos <= 60; wetGatePos += 1) 
    { 
      wetDetectGate.write(wetGatePos);              
      delay(15);                       
    }
    delay(5000);
    for (wetGatePos = 60; wetGatePos >= 0; wetGatePos -= 1) 
    { 
      wetDetectGate.write(wetGatePos);              
      delay(15);
    }
  }
  if(metalSensorVal == 0)
  {
    for (metalGatePos = 0; metalGatePos <= 60; metalGatePos += 1) 
    { 
      metalDetectGate.write(metalGatePos);              
      delay(15);                       
    }
    delay(7000);
    for (metalGatePos = 60; metalGatePos >= 0; metalGatePos -= 1) 
    { 
      metalDetectGate.write(metalGatePos);              
      delay(15);
    }
  }
  delay(10);
}
