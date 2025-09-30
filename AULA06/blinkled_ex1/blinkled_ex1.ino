int leds[3] = {13,12,11};
void setup() {
  for (int i = 0;i<3; i++){
    pinMode(leds[i],OUTPUT);}}
void loop() {
  for(int i =0; i< 3; i++){
    digitalWrite(leds[i],LOW);
  }for (int i = 0; i< 3; i++){
    digitalWrite(leds[i],HIGH);
    digitalWrite(leds[i-1],LOW);
    delay(1000);}}
