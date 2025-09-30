int leds[5] = {13,12,11,10,9};
void setup() {
  for (int i = 0;i<5; i++){
    pinMode(leds[i],OUTPUT);}}
void loop() {
  for(int i =0; i< 5; i++){
    digitalWrite(leds[i],LOW);
  }for (int i = 0; i< 5; i++){
    digitalWrite(leds[i],HIGH);
    delay(1000);}}
