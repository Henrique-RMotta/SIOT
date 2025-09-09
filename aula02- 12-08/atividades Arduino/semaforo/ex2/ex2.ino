
int leds[3] = {12,11,10};
//leds[0]-verde
//leds[1]-amarelo
//leds[2]-vermelho

void setup() {
  for (int i = 0; i < 3; i++){
    pinMode(leds[i], OUTPUT);
  }
}

void loop(){
  digitalWrite(leds[0],HIGH);
  delay(5000);
  digitalWrite(leds[0],LOW);
  digitalWrite(leds[1],HIGH);
  delay(2000);
  digitalWrite(leds[1],LOW);
  digitalWrite(leds[2],HIGH);
  delay(5000);
  digitalWrite(leds[2],LOW);
}


