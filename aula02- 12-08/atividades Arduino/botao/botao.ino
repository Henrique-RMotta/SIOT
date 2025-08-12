int botao = 12;
int led = 13;
void setup(){
  pinMode(led,OUTPUT);
  pinMode(botao,INPUT);
}

void loop (){
  if (digitalRead(botao) == HIGH){
    digitalWrite(led,HIGH);
    delay(2000);
    digitalWrite(led,LOW);
  }
}