//define portas de saida de solenoides conectadas
  #define horta 8
  #define frente 9
  #define fundo 10

//define portas de saida dos botões
  #define btn_escolhe 3
  #define btn_teste 4
  #define btn_irriga 2

//leds
  #define led_horta 5
  #define led_frente 6
  #define led_fundo 7

//variáveis
  int tempo_irrigacao = 90000;
  int tempo_teste = 10000;
  boolean status_horta = false;
  boolean status_frente = false;
  boolean status_fundo = false;

void setup() {
  //inicia a porta monitor serial
  Serial.begin(9600);
  
  //Configura pinos I/O
    pinMode(horta, OUTPUT);
    pinMode(frente, OUTPUT);
    pinMode(fundo, OUTPUT);
    pinMode(led_horta, OUTPUT);
    pinMode(led_frente, OUTPUT);
    pinMode(led_fundo, OUTPUT);
    pinMode(btn_escolhe, INPUT);
    pinMode(btn_teste, INPUT);
    pinMode(btn_irriga, INPUT);
  
  //config de iniciação

    digitalWrite(horta, HIGH);
    digitalWrite(frente, HIGH);
    digitalWrite(fundo, HIGH);
    digitalWrite(led_horta, LOW);
    digitalWrite(led_frente, LOW);
    digitalWrite(led_fundo, LOW);

}

void loop() {
  
 if (digitalRead(btn_escolhe) == HIGH)
 {
  Serial.begin("btn_escolhe");
  ascender_led();
 }
 if (digitalRead(btn_irriga) == HIGH)
 {
  Serial.begin("btn_irriga");
  irrigar();
 }
 if (digitalRead(btn_teste) == HIGH)
 {
  Serial.begin("btn_teste");
  irrigar_tudo(tempo_teste);
 }
  
  
}

void ascender_led(){
  if (digitalRead(led_horta) == LOW && 
  digitalRead(led_frente) == LOW && 
  digitalRead(led_fundo) == LOW)
  {
    digitalWrite(led_horta, HIGH);
  }
  if (digitalRead(led_horta) == HIGH && 
  digitalRead(led_frente) == LOW && 
  digitalRead(led_fundo) == LOW)
  {
    digitalWrite(led_frente, HIGH);
  }
  if (digitalRead(led_horta) == HIGH && 
  digitalRead(led_frente) == HIGH && 
  digitalRead(led_fundo) == LOW)
  {
    digitalWrite(led_fundo, HIGH);
  }
  
}

void status_led(){
  if (digitalRead(led_horta) == HIGH)
  {
    status_horta = true;
  }else
  {
    status_horta = false;
  }
  
  if (digitalRead(led_frente) == HIGH)
  {
    status_frente = true;
  }else
  {
    status_frente = false;
  }
  
  if (digitalRead(led_fundo) == HIGH)
  {
    status_fundo = true;
  }else
  {
    status_fundo = false;
  }
}

void apaga_leds(){
  digitalWrite(led_horta, LOW);
  digitalWrite(led_frente, LOW);
  digitalWrite(led_fundo, LOW);
  status_horta = false;
  status_frente = false;
  status_fundo = false;
}

void pisca_leds(){
  apaga_leds();
  digitalWrite(led_horta, HIGH);
  digitalWrite(led_frente, HIGH);
  digitalWrite(led_fundo, HIGH);
  delay(100);
  digitalWrite(led_horta, LOW);
  digitalWrite(led_frente, LOW);
  digitalWrite(led_fundo, LOW);
  delay(100);
}

void pisca_setor(short setor){
  digitalWrite(setor, LOW);
  delay(100);
  digitalWrite(setor, HIGH);
  delay(100);
}

void irrigar(){
  status_led();
  if (status_horta == false && 
   status_frente == false && 
   status_fundo == false)
  {
    irrigar_tudo(tempo_irrigacao);
  }
  if (status_horta == true &&
   status_frente == false &&
   status_fundo == false)
  {
    irrigar_setor(horta, tempo_irrigacao);
  }
  if (status_horta == false &&
   status_frente == true &&
    status_fundo == false)
  {
    irrigar_setor(frente, tempo_irrigacao);
  }
  if (status_horta == false &&
   status_frente == false &&
    status_fundo == true)
  {
    irrigar_setor(fundo, tempo_irrigacao);
  }
}

void irrigar_tudo(int tempo){
  pisca_leds();
  digitalWrite(horta, LOW);
  delay(tempo);
  digitalWrite(horta, HIGH);
  digitalWrite(frente, LOW);
  delay(tempo);
  digitalWrite(frente, HIGH);
  digitalWrite(fundo, LOW);
  delay(tempo);
  digitalWrite(fundo, HIGH);
  digitalWrite(horta, LOW);
  delay(tempo);
  digitalWrite(horta, HIGH);
  digitalWrite(frente, LOW);
  delay(tempo);
  digitalWrite(frente, HIGH);
  digitalWrite(fundo, LOW);
  delay(tempo);
  digitalWrite(fundo, HIGH);
  digitalWrite(horta, LOW);
  delay(tempo);
  digitalWrite(horta, HIGH);
  digitalWrite(frente, LOW);
  delay(tempo);
  digitalWrite(frente, HIGH);
  digitalWrite(fundo, LOW);
  delay(tempo);
  digitalWrite(fundo, HIGH);
  apaga_leds();
}

void irrigar_setor(short setor, int tempo){
  digitalWrite(setor, LOW);
  delay(tempo);
  digitalWrite(setor, HIGH);
  delay(tempo);
  digitalWrite(setor, LOW);
  delay(tempo);
  digitalWrite(setor, HIGH);
  delay(tempo);
  digitalWrite(setor, LOW);
  delay(tempo);
  digitalWrite(setor, HIGH);
  delay(tempo);
  apaga_leds();
}
    