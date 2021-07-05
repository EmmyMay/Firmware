// This piece of software was written by Emmy Leke for the purpose of controlling an AVR
#include <LiquidCrystal.h>
LiquidCrystal lcd(8, 9, 10, 11, 12, 13);
float m = 0.0; // initialise variable m
float dcValue = 0.0; //initialise variable dcValue
int battPin = A5;
int rl4 = 6;
int rl2 = 7;
int rl3 = 5;
int rl1 = 4;
int dc = 0;
float r1 = 100000.0;
float r2 = 10000.0;
float ac;



void setup()
{
  pinMode(battPin, INPUT); // set pin a0 as input pin
  Serial.begin(9600);// begin serial communication between arduino and pc
  pinMode(rl1, OUTPUT);
  pinMode(rl2, OUTPUT);
  pinMode(rl3, OUTPUT);
  pinMode(rl4, OUTPUT);
  lcd.begin(16, 2);
  lcd.print("Mustech LAB.");
  delay(500);

}





void loop()
{

  dc = analogRead(battPin);
  m = (dc * 5.0) / 1023.0;
  dcValue = m / (r2 / (r1 + r2));
  ac = dcValue * 0.34177;
  if (dcValue < 0.09) {
    dcValue = 0.0;

  };
  lcd.setCursor(0, 0);
  lcd.print("dc volt ");
  lcd.print(dcValue);
  lcd.setCursor(1, 1);
  lcd.print("ac volt ");
  lcd.print(ac);

  delay(1000);


  if ( dcValue >= 11 && dcValue < 12) {
      digitalWrite(rl3, LOW);
      digitalWrite(rl4, LOW);
      digitalWrite(rl1, LOW);
      digitalWrite(rl2, HIGH);
      delay(60000);
  }



  if ( dcValue > 8.5 && dcValue < 10.58) {
      
      digitalWrite(rl2, LOW);
      digitalWrite(rl4, LOW);
      digitalWrite(rl1, LOW);
      digitalWrite(rl3, HIGH);
      delay(60000);
  }

  if ( dcValue > 13) {
      digitalWrite(rl3, LOW);
      digitalWrite(rl4, LOW);
      digitalWrite(rl2, LOW);
      digitalWrite(rl1, HIGH);
      delay(60000);
  }

  if ( dcValue < 7.5) {
      digitalWrite(rl3, LOW);
      digitalWrite(rl2, LOW);
      digitalWrite(rl1, LOW);
      digitalWrite(rl4, HIGH);
      delay(60000);

  }





  }
