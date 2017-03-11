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
  base.setCurrentPosition(0);
  printf("lul");
}

void loop(){
  //base.moveTo(2000);
  buttonState = digitalRead(buttonPin);
  
  if(buttonState == HIGH){    
    if(prevState == 0){
      if (ledState == 1){//Inverting the current LEDsignal
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
  
  if (ledState == 1) {//Interacts with the stepper motor.
    // turn LED on:
     digitalWrite(LED_BUILTIN, HIGH);
     base.setSpeed(500);
     base.runSpeed();
  } else {
    // turn LED off:
    base.setSpeed(-500);
    base.runSpeed();
    digitalWrite(LED_BUILTIN, LOW);
  }
}
