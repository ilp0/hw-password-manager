#include "DigiKeyboard.h"
#define PASS_ARR_SIZE 4

bool unlocked = false;
uint8_t password[] = {0,0,0,1,1,0};
int passwordlength = sizeof(password);
int lockstage = 0;
int currentPage = 0;
String passwords[PASS_ARR_SIZE] = {"p1","p2","p3","p4"};

void setup() {

  pinMode(0, INPUT);
  pinMode(1, INPUT);
  pinMode(2, OUTPUT);
  //show user when out of bootloader
  digitalWrite(2, HIGH);
  delay(100);
  digitalWrite(2,LOW);
}

//show page via blinking
void blinkAnim(){
  for(int i = 0; i < currentPage+1;i++){
    digitalWrite(2,HIGH);
    delay(50);
    digitalWrite(2,LOW);
    delay(150);
  }
}

void loop() {

  if(unlocked) {
    if(digitalRead(1)==HIGH){
      //Change page
      currentPage++;
      if(currentPage > PASS_ARR_SIZE-1) currentPage = 0;
      blinkAnim();
    } else if(digitalRead(0)==HIGH) {
       DigiKeyboard.print(passwords[currentPage]);
       DigiKeyboard.sendKeyStroke(KEY_ENTER);
       DigiKeyboard.delay(300);
    }
  } else {
    //password codes
    if (digitalRead(password[lockstage])==HIGH){
      digitalWrite(2,HIGH);
      delay(100);
      digitalWrite(2,LOW);
      lockstage++;
      if(lockstage==passwordlength){
        unlocked = true;
      }
    } else if(digitalRead(0)==HIGH || digitalRead(1)==HIGH) {
      lockstage=0;
    }
  }
    DigiKeyboard.delay(100);

}
