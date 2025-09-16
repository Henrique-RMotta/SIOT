#include <Servo.h>

Servo motta;
#define pot A0
int valor;
void setup() {
  motta.attach(3);
  Serial.begin(9600);
}
void loop(){
  valor = map(analogRead(pot),0,1023,0,180);
  Serial.print("Posicao: ");
  Serial.print(valor);
  Serial.println("graus");
  motta.write(valor);
  delay(500);
}