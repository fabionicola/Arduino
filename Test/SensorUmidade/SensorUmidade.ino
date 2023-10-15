#define led1 2
#define led2 3
#define bomba 4
#define sensor A0

int umd;

void setup() {
  Serial.begin(9600);
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(sensor, INPUT);
  digitalWrite(bomba, LOW);

}

void loop() {
  umd = analogRead(sensor);

  if (umd > 0 && umd < 800){
    digitalWrite(led1, HIGH);
    digitalWrite(led2, LOW);
    digitalWrite(bomba, LOW);
  }

  if (umd > 800 && umd < 1024){
    digitalWrite(led1, LOW);
    digitalWrite(led2, HIGH);
    digitalWrite(bomba, HIGH);

  }
  delay(100);
}
