//define portas de saida de solenoides conectadas
#define sol_horta 22

//define portas de saida dos botões
#define btn 2

//variáveis
//estado do botao
int est_btn = 0;

void setup() {
//inicia a porta monitor serial
Serial.begin(9600);
  
pinMode(sol_horta, OUTPUT);
pinMode(btn, INPUT);

//config de iniciação

digitalWrite(sol_horta, LOW);

}

void loop() {

  est_btn = digitalRead(btn);

  if (est_btn == HIGH){
    irrigar01();
  }else{
    est_btn == LOW;
    digitalWrite(sol_horta, LOW);
  }

}

void irrigar01(){
  //primeira etapa
  digitalWrite(sol_horta, HIGH);
  delay(180000);
  digitalWrite(sol_horta, LOW);
  delay(60000);
 //segunda etapa
  digitalWrite(sol_horta, HIGH);
  delay(120000);
  digitalWrite(sol_horta, LOW);
  delay(60000);
 //terceira etapa
  digitalWrite(sol_horta, HIGH);
  delay(60000);
  digitalWrite(sol_horta, LOW);
  est_btn = LOW;
}
