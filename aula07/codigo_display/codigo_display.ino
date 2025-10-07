#include <LiquidCrystal.h> // Adiciona a biblioteca "LiquidCrystal" ao projeto

LiquidCrystal lcd(12, 11, 7, 6, 5, 4); // Pinagem do LCD
String prints[3] = {"Vermelho","Amarelo","Azul"};
int leds[3] = {13,12,11};
void setup()
{
  lcd.begin(16, 2); // Inicia o lcd de 16x2
  lcd.setCursor(0,0);
  lcd.print("Ola, Mundo!");
  lcd.setCursor(0,1);
  lcd.print("Oi Motta!");
  delay(2000);
  for (int i = 0; i< 3 ; i++ ) {
    pinMode(leds[i], OUTPUT);
  }
}

void loop()
{
  for(int i =0; i< 3; i++ ){
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print(prints[i]);
  digitalWrite(leds[i],HIGH);
  delay(3000);
  }
  for(int i = 0; i< 3; i++){
    digitalWrite(leds[i],LOW);
     lcd.clear();
    lcd.setCursor(0,0);
    lcd.print(prints[i]);
    delay(3000);
  }  
}