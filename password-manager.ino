#include "DigiKeyboard.h"

bool unlocked = false;
int password[] = {1,0,2,0,2};
int passwordlength = 5;
int lockstage = 0;

void setup() {
  pinMode(0, INPUT);
  pinMode(1, INPUT);
  pinMode(2, INPUT);
  pinMode(5, INPUT);
}

void loop() {

if(unlocked) {
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
    DigiKeyboard.delay(1000);
  }
} else {
  //password codes
  if (digitalRead(password[lockstage])==HIGH){
    delay(250);
    lockstage++;
    if(lockstage==passwordlength) unlocked = true;
  } else if(digitalRead(0)==HIGH || digitalRead(1)==HIGH || digitalRead(2)==HIGH) lockstage=0;
}
  DigiKeyboard.delay(100);

}
