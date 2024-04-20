#include "DHT.h"
#define DHTPIN 10
#define DHTTYPE DHT11

byte flame = 13;
byte sensorMQ2 =12;
byte alarm = 11;
int nilaiSuhu, api, asap;

DHT dht(10, DHT11);

void setup() {
  pinMode(flame,INPUT);
  pinMode(sensorMQ2,INPUT);
  pinMode(alarm, OUTPUT);
  Serial.begin(9600);
  dht.begin();}

void loop() {
  api=digitalRead(flame);
  asap=digitalRead(sensorMQ2);
  nilaiSuhu = dht.readTemperature();
  
 if (api>0){
   digitalWrite(alarm, HIGH);
   Serial.write(1);
   Serial.write(nilaiSuhu);  
   delay(100);}
 else if (asap>0){
  digitalWrite(alarm, LOW);
  Serial.write(2);
  Serial.write(nilaiSuhu);  
  delay(100);}
 else {
   digitalWrite(alarm, LOW);
   Serial.write(0);
   Serial.write(nilaiSuhu);  
   delay(100);}} 
