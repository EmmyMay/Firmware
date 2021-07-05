// This piece of software is for the prototype of an automatic carpark system

#include <Ultrasonic.h>
#include <Servo.h>
#include <LiquidCrystal.h>

Servo myservoOut;
Servo myservoIn;
const int rs = A0, en = A1, d4 = A2, d5 = A3, d6 = A4, d7 = A5;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);
Ultrasonic entry_sensor(13, 12);  // An ultrasonic sensor HC-04
Ultrasonic exit_sensor(9, 10);    // An ultrasonic sensor PING)))

int total_cars = 0;
int pos = 0;
bool stillPresent = false;

//Auxiliary Functions

void updateDisplay() {
  //Put LCD controlling code here
  //  Serial.println("Number of cars in the park is ");
  Serial.println(total_cars);
  lcd.setCursor(0, 0);
  lcd.print("Total Cars");
  lcd.setCursor(0, 1);
  lcd.print(total_cars);

}
void dec() {
  if (total_cars > 0) {
    if (!stillPresent) {
      total_cars--;
      updateDisplay();
    }

  }
}
void inc() {
  if (!stillPresent) {
    total_cars++;
    updateDisplay();
  }

}

void GateOpen(void (*function)(), Servo servo ) {
  pos = 90;
  servo.write(pos);
  delay(3000);
  (*function)();
  if (!stillPresent) {
    pos = 0;
    servo.write(pos);

  }
}

void GateClose(void (*function)(), Servo servo ) {
  pos = 0;
  servo.write(pos);
  delay(3000);
  (*function)();
  if (!stillPresent) {
    pos = 0;
    servo.write(pos);

  }
}


void setup() {
  Serial.begin(9600);
  lcd.begin(16, 2);
  lcd.setCursor(0, 0);
  lcd.print("Car Park System");
  Serial.print("Car Park System");
  myservoOut.attach(3);
  myservoIn.attach(6);
  myservoOut.write(pos);
  myservoIn.write(pos);
  delay(2000);
  lcd.clear();

}

void loop() {
  if (entry_sensor.read() < 20) {
    GateOpen(inc, myservoIn);
    stillPresent = true;
    


  } else {
    pos = 0;
    myservoIn.write(pos);
    stillPresent = false;
  }


  // Check to see if the Exit Sensor has been passed over to trigger the servo-motor

  if (exit_sensor.read() < 20) {
    GateOpen(dec, myservoOut);
    stillPresent = true;


  } else {
    pos = 0;
    myservoOut.write(pos);
    stillPresent = false;
  }


}
