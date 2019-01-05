#include "DigiKeyboard.h"

void setup() {
  pinMode(0, INPUT);
  pinMode(1, INPUT);
  pinMode(2, INPUT);
}

void loop() {


  if(digitalRead(0)==HIGH){
    
    if(digitalRead(1)==HIGH) {
      if(digitalRead(2)==HIGH){
        //3
            DigiKeyboard.print("Password3");

      } else {
        //1
            DigiKeyboard.print("Password1");

      }
    } else if (digitalRead(2)==HIGH){
        //2
            DigiKeyboard.print("Password2");

    } else {
        //0
            DigiKeyboard.print("Password0");
    }
    DigiKeyboard.delay(2000);
  }

  DigiKeyboard.delay(100);

}

