#include <Servo.h>

#define led1 2
#define led2 3
#define btn 4
#define SERVO 6

Servo s; //Variável do servo
int pos = 0; //variável da posição

void ctrlLed();
void servo();

void setup() {

  Serial.begin(9600);

  s.attach(SERVO);

  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(btn, INPUT);

  s.write(0); //inicia o motor na posição 0

}

void loop() {

  ctrlLed();
  servo();

}

void ctrlLed() {
  static unsigned long espera;

  if ( (millis() - espera) < 500){
    digitalWrite(led1, HIGH);
    digitalWrite(led2, LOW);
    }else{
    digitalWrite(led1, LOW);
    digitalWrite(led2, HIGH);
  }
  if ((millis() - espera) >= 1000){
    espera = millis();
  }
}

void servo() {
  static unsigned long espera;

  if ( (millis() - espera) < 1000){
     pos = 90;
     s.write(pos);
    }else{
    pos = 0;
    s.write(pos);
  }
  if ((millis() - espera) >= 3000){
    espera = millis();
  }
}

