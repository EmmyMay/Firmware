// Drawing a sine wave to an LCD
// include the library code:
#include <LiquidCrystal.h>

// initialize the library with the numbers of the interface pins
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

//----------------- store the custom characters in arrays ---------------------//
byte positive_cycle0[8] =
{

  0b00100,
  0b01010,
  0b10001,
  0b10001,
  0b10001,
  0b10001,
  0b10001,
  0b10001
};
byte positive_cycle[8] =
{

  0b10001,
  0b10001,
  0b10001,
  0b10001,
  0b10001,
  0b10001,
  0b10001,
  0b10001
};

byte negative_cycle[8] =
{
  0b10001,
  0b10001,
  0b10001,
  0b10001,
  0b10001,
  0b10001,
  0b01010,
  0b00100
};



void setup()
{
  //---- create custom characters ----//



  // set up the lcd's number of columns and rows:
  lcd.begin(16, 2);
  lcd.setCursor(0, 0);
  lcd.print("Hello");
  delay(3000);
  lcd.createChar(1, positive_cycle0);
  lcd.createChar(2, positive_cycle);
  lcd.createChar(3, negative_cycle);
  lcd.clear();



}

void loop()
{

  for ( int i = 0; i <= 15; i+=2) {
    lcd.setCursor(i, 0);
    lcd.write(1);
    lcd.setCursor(i+1, 1);
    
    lcd.write(3);
    
    delay(500);
    
  }
  lcd.clear();



}
