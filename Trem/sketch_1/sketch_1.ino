#include <Servo.h>

#define led1 2
#define led2 3
#define btn 4
#define SERVO 6

Servo s; //Variável do servo
int pos = 0; //variável da posição

void ctrlLed1();
void ctrlLed2();
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

  ctrlLed1();
  ctrlLed1();
  servo();

}

void ctrlLed1() {
  static unsigned long espera;

  if ( (millis() - espera) < 500){
    digitalWrite(led1, HIGH);
    }else{
    digitalWrite(led1, LOW);
  }
  if ((millis() - espera) >= 1000){
    espera = millis();
  }
}

void ctrlLed2() {
  static unsigned long espera;

  if ( (millis() - espera) < 1000){
    digitalWrite(led1, HIGH);
    }else{
    digitalWrite(led1, LOW);
  }
  if ((millis() - espera) >= 1500){
    espera = millis();
  }
}

void servo(){
  pos = 90;
  s.write(pos);
  delay(1000);
  pos = 0;
  s.write(pos);
  delay(1000);
}
