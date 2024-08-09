#include <Arduino.h>
#define buttonPin 35
#define ledPin 19

bool ledState = false;     
bool buttonState = false;  
bool lastButtonState = false; 

void setup() {
  pinMode(buttonPin, INPUT_PULLUP);   
  pinMode(ledPin, OUTPUT);           
  digitalWrite(ledPin, ledState);   
}

void loop() {
  buttonState = !digitalRead(buttonPin); 

  if (buttonState && !lastButtonState) {
    ledState = !ledState;            
    digitalWrite(ledPin, ledState);  
  }

  lastButtonState = buttonState;  

  delay(50);  
}
