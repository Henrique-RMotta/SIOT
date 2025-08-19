int leds[4] = {13,12,11,10}; 

void setup() {
  for (int i = 0; i<4; i++){
    pinMode(leds[i], OUTPUT);
  }
}

void loop() {
for (int i = 0; i < 16; i++){
switch (i) {
  case 1:
    digitalWrite(leds[0],HIGH);
    digitalWrite(leds[1],LOW);
    digitalWrite(leds[2],LOW);
    digitalWrite(leds[3],LOW);
    break;
  case 2:
    digitalWrite(leds[0],LOW);
    digitalWrite(leds[1],HIGH);
    digitalWrite(leds[2],LOW);
    digitalWrite(leds[3],LOW);
    break;
  case 3:
    digitalWrite(leds[0],HIGH);
    digitalWrite(leds[1],HIGH);
    digitalWrite(leds[2],LOW);
    digitalWrite(leds[3],LOW);
    break;
  case 4:
    digitalWrite(leds[0],LOW);
    digitalWrite(leds[1],LOW);
    digitalWrite(leds[2],HIGH);
    digitalWrite(leds[3],LOW);
    break;
  case 5:
    digitalWrite(leds[0],HIGH);
    digitalWrite(leds[1],LOW);
    digitalWrite(leds[2],HIGH);
    digitalWrite(leds[3],LOW);
    break;
  case 6:
    digitalWrite(leds[0],LOW);
    digitalWrite(leds[1],HIGH);
    digitalWrite(leds[2],HIGH);
    digitalWrite(leds[3],LOW);
    break;
  case 7:
    digitalWrite(leds[0],HIGH);
    digitalWrite(leds[1],HIGH);
    digitalWrite(leds[2],HIGH);
    digitalWrite(leds[3],LOW);
    break;
  case 8:
    digitalWrite(leds[0],LOW);
    digitalWrite(leds[1],LOW);
    digitalWrite(leds[2],LOW);
    digitalWrite(leds[3],HIGH);
    break;
  case 9:
    digitalWrite(leds[0],HIGH);
    digitalWrite(leds[1],LOW);
    digitalWrite(leds[2],LOW);
    digitalWrite(leds[3],HIGH);
    break;
  case 10:
    digitalWrite(leds[0],LOW);
    digitalWrite(leds[1],HIGH);
    digitalWrite(leds[2],LOW);
    digitalWrite(leds[3],HIGH);
    break;
  case 11:
    digitalWrite(leds[0],HIGH);
    digitalWrite(leds[1],HIGH);
    digitalWrite(leds[2], LOW);
    digitalWrite(leds[3],HIGH);
    break;
  case 12:
    digitalWrite(leds[0],LOW);
    digitalWrite(leds[1],LOW);
    digitalWrite(leds[2],HIGH);
    digitalWrite(leds[3],HIGH);
    break;
  case 13:
    digitalWrite(leds[0],HIGH);
    digitalWrite(leds[1],LOW);
    digitalWrite(leds[2],HIGH);
    digitalWrite(leds[3],HIGH);
    break;
  case 14:
    digitalWrite(leds[0],LOW);
    digitalWrite(leds[1],HIGH);
    digitalWrite(leds[2],HIGH);
    digitalWrite(leds[3],HIGH);
    break;
  case 15:
    digitalWrite(leds[0],HIGH);
    digitalWrite(leds[1],HIGH);
    digitalWrite(leds[2],HIGH);
    digitalWrite(leds[3],HIGH);
    break;
  default:
    digitalWrite(leds[0],LOW);
    digitalWrite(leds[1],LOW);
    digitalWrite(leds[2],LOW);
    digitalWrite(leds[3],LOW);
    break;
}
delay(500);
}
}
