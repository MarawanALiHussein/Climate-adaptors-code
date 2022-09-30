#include "DHT.h"
 int irsensor=6;
 int buz=7;
 #define fan 8
 int led=13;
 int IN3=2;
 int IN4=3;
 #define pumpspeed 5
 #include <DHT.h>
 #define DHTPIN 4
 #define DHTTYPE DHT11
 DHT dht (DHTPIN,DHT11);
 float temp;
 float hum;
 int moisturePin = A0; 
 int sensorValue;  
 int limit = 500; 
 int reading=0;
 int limit_1 = 400;
 int limit_2 = 30;
 int temp_read;
 int hum_read;

void setup() {
 pinMode(13,OUTPUT);
 pinMode(8,OUTPUT);
 dht.begin();
 pinMode(IN3,OUTPUT);
 pinMode(IN4,OUTPUT);
 pinMode(5,OUTPUT);
 pinMode(2,OUTPUT);
 pinMode(led,OUTPUT);
 pinMode(6, INPUT);
 pinMode(buz,OUTPUT);
 Serial.begin(9600);
 Serial.println("Temperature and Humidity");
}

void loop() {
 sensorValue = analogRead(moisturePin);
 Serial.print("Soil Moisture Value is: ");
 Serial.println(sensorValue);
 
 if (sensorValue<limit_1)
 {
 digitalWrite(IN3,HIGH); 
 digitalWrite(IN4,LOW);
 }
 else {
 digitalWrite(IN3,LOW);
 digitalWrite(IN4,LOW);
 }
  
 temp_read= dht.readTemperature();
 hum_read= dht.readHumidity();
 Serial.print("Temperature Value Is: ");
 Serial.print(temp_read);
 Serial.println(" C");
 Serial.println("*");
 Serial.print("Humidity Value Is: ");
 Serial.print(hum_read);
 Serial.println(" %");
 if( temp_read<25 )
 {
   digitalWrite(13,HIGH);
 }
  else{
    digitalWrite(13,LOW);
  }
 
 if(temp_read>=25)
 {
 digitalWrite(fan,HIGH);
 }
 else
 {
  digitalWrite(fan,LOW);
 }
      
 int reading=digitalRead(irsensor);
 Serial.print("The IR Reading Is ");
 Serial.println(reading);
 if(reading==LOW)
  digitalWrite(buz,HIGH);
 
 else if(reading==HIGH)
  digitalWrite(buz,LOW);


}
