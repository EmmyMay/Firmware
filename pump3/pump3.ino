// Emmy Leke
// Using an ultrasonic sensor as a switch to power an AC pump

int led = A1;
int buzzer = A0;
int echoPin = 7;
int trigger = 8;
long duration, cm;
int initialWaterLevel = 0;
int pump = 11;
unsigned long pM = 0;
unsigned long testpm = 0;
unsigned long test; // all test vars are for serial printing and will be cancelled after test is done
unsigned long cur;
const long interval = 600000;
const long interval2 = 5000;
unsigned long pM2 = 0;
unsigned long cM2;
const long inter = 2000;
int pumpState = 0;




void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(led, OUTPUT);
  pinMode(buzzer, OUTPUT);
  //  system ON indicator
  digitalWrite(buzzer, HIGH);
  delay(500);
  digitalWrite(buzzer, LOW);







}

void loop() {
  // put your main code here, to run repeatedly:
  //  asynchronous working
//  cur = millis();
//  test = millis();
//  cM2 = millis();
  
  //using the ultrasonic sensor
  digitalWrite(trigger, LOW);
  delayMicroseconds(5);
  digitalWrite(trigger, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigger, LOW);


  pinMode(echoPin, INPUT);
  duration = pulseIn(echoPin, HIGH);

  cm = (duration * 0.034) / 2;

//  if ( (cM2 - pM2 >= 3000) and (initialWaterLevel <= 1) ) {
//    pM2 =  cM2;
//    initialWaterLevel = cm;
//
//  }

  //for tests
//  if ( test - testpm >= 1000 ) {
//    testpm =  test;
//    Serial.println(cm);
//    Serial.println("Initial Water Level is ");
//    Serial.println(initialWaterLevel);
//
//  }





  if ( cm >= 30) {
     
    digitalWrite(pump, HIGH);
    digitalWrite(led,LOW);
    pumpState = 1;
    //    delay for 1 minute, creating a ten minute pump cycle
    //    delay(60000)

    //    It might make sense to add a delay here because of the ripples on the surface of the water while pumping water
    //    and the sound of water hitting the tank might also cause interferences too

  } else {
    
    digitalWrite(pump, LOW);
    digitalWrite(led, HIGH);
    pumpState =0;
  }


//  if (cur - pM >= interval ) {
//
////    if ( pumpState == 1 ){
////      
////      
////      }
//    //for tests
////    Serial.println("Buzzer ON");
////    Serial.println("InitialWL = ");
////    Serial.println(initialWaterLevel);
//    //for tests
//
////   In case water level does not increase ** abandoned because it is impossible to account for a situation where water is being pumped and used simultaneously
////      if( cm >= initialWaterLevel ){
////
////        if(pumpState == 1){
////        digitalWrite(pump, LOW);
////        pumpState = 0;
////        beep();
////        delay();
////        pM = cur;
////          
////          
////          }
////        
//        
//        }
//    
    



  

  // determine the time the system will run for
  // test values for now but the expected time should be 30 minutes
  // This puts the device in a deep sleep state where nothing is done by the system for
  // about an hour. It gets into deep sleep if the pump has been on for up to 30 minutes






}
