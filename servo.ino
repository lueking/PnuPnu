/************************************************/
#include <Servo.h>
/************************************************/
Servo vacuumServo; //controls the vacuum
Servo valveServo; //the servo on the valve

const int buttonPin = 7;

const int valvePin = 9;
const int vacPin = 10;

const int ledPin = 13;

const int VALVE_CLOSE_POS = 90;
const int VALVE_OPEN_POS = 0;
const int VACUUM_OFF_POS = 0;
const int VACUUM_ON_POS = 0;


bool buttonState = false; //false is not pressed
bool toggleState = false; //for logic
bool vacuumState = false; //false is off
bool valveState = false; //false is closed




/************************************************/
void setup() {
  //servo setup
  valveServo.attach(valvePin);
  valveServo.write(VALVE_CLOSE_POS); //close the valve
  vacuumServo.attach(vacPin);
  vacuumServo.write(VACUUM_OFF_POS); //make sure the vac is off
  
  //button setup
  pinMode(buttonPin, INPUT);
  
  
  pinMode(ledPin,OUTPUT);
}
/*************************************************/
void loop() {
  getButtonState();
  test();
  handleServos();
}  
 
/**************************************************/


void test(){
  if(digitalRead(buttonPin) == HIGH){
    digitalWrite(ledPin, HIGH);//turn on the led
    delay(100);
  }
  else{
    digitalWrite(ledPin,LOW);//turn off the led
    delay(100);
  }
}

void getButtonState(){
  if(digitalRead(buttonPin) == HIGH){
    buttonState = true;
  }else{
    buttonState = false;
  }
}


void handleServos(){
  if(buttonState == true){
    valveState = !valveState;
    vacuumState = !vacuumState;
    
    if(vacuumState){
      vacuumServo.write(VACUUM_ON_POS);
      delay(100);
    }else{  
      vacuumServo.write(VACUUM_OFF_POS);
      delay(100);
    }
    
    if(valveState){
      valveServo.write(VALVE_OPEN_POS);
      delay(1000);
    }else{
      valveServo.write(VALVE_CLOSE_POS);
      delay(1000);
    }
  }
}  
    


















