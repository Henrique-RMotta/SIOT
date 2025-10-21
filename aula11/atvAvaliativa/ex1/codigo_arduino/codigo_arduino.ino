const int leds [3] = { 13,12,11};

void setup() {
  Serial.begin(9600);
  for (int i = 0; i < 3; i++) {
    pinMode(leds[i],OUTPUT);
  }
}

void loop() {
  if (Serial.available() > 0) {
    char command = Serial.read();

    switch(command) {
      case 'A':
        digitalWrite(leds[0],HIGH);
        break;
      case 'a':
        digitalWrite(leds[0], LOW);
        break;
      case 'B':
        digitalWrite(leds[1], HIGH);
        break;
      case 'b':
        digitalWrite(leds[1], LOW);
        break;
      case 'C':
        digitalWrite(leds[2], HIGH);
        break;
      case 'c':
        digitalWrite(leds[2], LOW);
        break;
    }

  }
}