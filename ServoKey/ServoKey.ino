#include <Servo.h>
#include <Boards.h>
#include <Firmata.h>

Servo servo;

int pos = 0;
int faceZeroValue;
int reset = 155;
boolean faceZero = true;
//int key;

void setup(){
  pinMode(13, OUTPUT);
 servo.attach(9);
  Serial.begin(19200);
  servo.write(reset);

}

void loop(){
  if (Serial.available()){

    int  key = Serial.read();
    
    if (key > 1){
      if (faceZero){
        faceZeroValue = key;
        faceZero = false;
      }
    
    int x = key;
    
    servo.write(map(x, faceZeroValue, faceZeroValue + 8, reset, 0));
    }

    if (key == 1){
      digitalWrite(13, HIGH); 
    }
    
    if (key < 1){
     digitalWrite(13, LOW); 
     servo.write(reset);
     faceZero = true;
    }
  }


}




