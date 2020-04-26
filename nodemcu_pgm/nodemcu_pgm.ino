
#include <ESP8266WiFi.h>
#include <FirebaseArduino.h>

//Initialization of IDs and Variables
const char* ssid = "Wifi_ID"; //Enter your Wifi id
const char* password = "Wifi_PWD"; //Enter your Wifi password

#define FIREBASE_HOST "xxxxxxxxxxxxxx.firebaseio.com" //Enter your firebase host name
#define FIREBASE_AUTH "xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx" //Enter your firebase authorisation id 

int index1; 
int index2;
int index3;
String data1;
String data2;
String data3;
String receivedData;

void setup()
{
  Serial.begin(9600);
  WiFi.begin(ssid);
  Serial.println("");
  while (WiFi.status() != WL_CONNECTED) 
  {
    delay(500);
    Serial.print(".");
  }
  Serial.println("");
  Serial.print("Connected to: ");
  Serial.println(ssid, password);
  Firebase.begin(FIREBASE_HOST, FIREBASE_AUTH);
}

void loop() 
{
  if (Serial.available() > 0) 
  {
    char incomingByte = Serial.read();
    if (incomingByte == '*') 
    { 
      index1 = receivedData.indexOf(","); 
      data1 = receivedData.substring(0, index1); //Parsing the incoming data
      index2 = receivedData.indexOf(",", index1+1 );   
      data2 = receivedData.substring(index1+1, index2); //Parsing the incoming data
      index3 = receivedData.indexOf(",", index2+1 );
      data3 = receivedData.substring(index2+1); //Parsing the incoming data

      Firebase.pushString("/Distance/Bin1", data1); //Sending data to firebase database                                  
      Firebase.pushString("/Distance/Bin2", data2); //Sending data to firebase database
      Firebase.pushString("/Distance/Bin3", data3); //Sending data to firebase database

      //Converting to empty strings for reading new values
      receivedData="";
      data1="";
      data2="";
      data3="";
    } 
    else 
    {     
      receivedData += incomingByte;
    }
  }
}
