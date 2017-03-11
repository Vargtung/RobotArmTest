#include <AccelStepper.h>
#define HALFSTEP 8

//Motorpins for base stepper
#define BasePin1 11
#define BasePin2 10
#define BasePin3 9
#define BasePin4 8

//changing variables
const int buttonPin = 12;     // the number of the pushbutton pin
int ledState = 0;
int buttonState = 1;         // variable for reading the pushbutton status
int prevState = 0;
int pos = 0;
int reverse = 0;

AccelStepper base(HALFSTEP, BasePin1, BasePin3, BasePin2, BasePin4);

void setup(){
  pinMode(buttonPin, INPUT); //Pin wired to breadboard with switch. Currently set to pin 12.
  pinMode(LED_BUILTIN, OUTPUT); //Basic On-board LED
  base.setMaxSpeed(1000.0);
  base.setAcceleration(100.0);
  base.setSpeed(200);
}

void loop(){
  delay(10);
  base.moveTo(2000);
  buttonState = digitalRead(buttonPin);
  
  if(buttonState == HIGH){    
    if(prevState == 0){
      if (ledState == 1){
        ledState = 0;
      }
      else{
        ledState = 1;
      }
    }
    prevState = 1;
  }
  else if(buttonState == LOW){
    prevState = 0;
  }
  
  if (ledState == 1) {
    // turn LED on:
     digitalWrite(LED_BUILTIN, HIGH);
     base.run();
  } else {
    // turn LED off:
    digitalWrite(LED_BUILTIN, LOW);
  }
}
