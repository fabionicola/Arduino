#define led 2
#define btn 3

bool estadoled = 0;

void setup( ){
    Serial.begin(9600);
    pinMode(led, OUTPUT);
    pinMode(btn, INPUT);

}

void loop( ){


    if (digitalRead(btn) == HIGH)
    {
        Serial.println("btn acionado");
        digitalWrite(led, HIGH);
        delay(2000);
        digitalWrite(led, LOW);
        delay(2000);
    }
    

    
    
}