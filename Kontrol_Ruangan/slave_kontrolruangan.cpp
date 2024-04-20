#include<LiquidCrystal.h>
byte ac1 = 9;
byte ac2 = 8;
byte ex1 = 10;
byte ex2 = 13;
byte enac = 11;
byte enex = 12;
int data1, data2, output;
LiquidCrystal lcd (2, 3, 4, 5, 6, 7);

void setup() {
  pinMode(ac1, OUTPUT);
  pinMode(ac2, OUTPUT);
  pinMode(ex1, OUTPUT);
  pinMode(ex2, OUTPUT);
  pinMode(enex, OUTPUT);
  pinMode(enac, OUTPUT);
  lcd.begin(16, 2);
  Serial.begin(9600);}

void loop() {
  if ( Serial.available() > 0 ) {
    data1 = Serial.read();
    data2 = Serial.read();
    delay(100);}

  if (data1 == 1) {
    digitalWrite(ac1, LOW);
    digitalWrite(ac2, LOW);
    digitalWrite(ex1, LOW);
    digitalWrite(ex2, LOW);
    digitalWrite(enac, LOW);
    digitalWrite(enex, LOW);

    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("API TERDETEKSI");
    lcd.setCursor(0, 1);
    lcd.print("SUHU : ");
    lcd.print(data2);
    delay(100);}

  else if (data1 == 2) {
    output = map(data2, 0, 100, 0, 255);
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("ASAP TERDETEKSI");
    lcd.setCursor(0, 1);
    lcd.print("SUHU : ");
    lcd.print(data2);
    
    if (data2 >= 32) {
      digitalWrite(ac1, LOW);
      digitalWrite(ac2, HIGH);
      digitalWrite(enac, HIGH);
      digitalWrite(ex1, HIGH);
      digitalWrite(ex2, LOW);
      digitalWrite(enex, HIGH);}
    else {
      digitalWrite(ac1, LOW);
      digitalWrite(ac2, LOW);
      digitalWrite(enac, LOW);
      digitalWrite(ex1, HIGH);
      digitalWrite(ex2, LOW);
      digitalWrite(enex, HIGH);}
    delay(100);}
  else {
    output = map(data2, 20, 100, 100, 255);
    digitalWrite(ex1, LOW);
    digitalWrite(ex2, LOW);
    digitalWrite(enex, LOW);
    
    if (data2 >= 32) {
      digitalWrite(ac1, LOW);
      digitalWrite(ac2, LOW);
      digitalWrite(enac, HIGH);}
    else {
      digitalWrite(ac1, LOW);
      digitalWrite(ac2, HIGH);
      digitalWrite(enac, LOW);}

    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("DILARANG MEROKOK");
    lcd.setCursor(0, 1);
    lcd.print("SUHU : ");
    lcd.print(data2);
    delay(100) ;}}
