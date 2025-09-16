#include <Adafruit_Sensor.h>
#include <Bonezegei_DHT11.h>
#include <DHT_U.h>
int leds[3] = {13,12,11};
//armazena o valor flutuante de temperatura
float temperatura;
//porta usada e o tipo de sensor
DHT dht(3, DHT11);


void setup() {
Serial.begin(9600);// inicializando o monitor serial
dht.begin();// Inicializando o sensor
}

void loop() {
delay(2000);// Aguarda dois segundos entre as leituras
temperatura = dht.readTemperature();//Lê o valor da temperatura em C°

//Verificando se existe erro na leitura da temperatura
if (isnan(temperatura)) { Serial.println("ERRO NO SENSOR!");}
//Se tudo funcionar envia a temperatura para a serial
else {Serial.println(temperatura); /*em C°*/}

if (temperatura <= 30 && temperatura > 25) {
  digitalWrite(leds[0],HIGH);
  digitalWrite(leds[1],LOW);
  digitalWrite(leds[2],LOW);
} else if (temperatura <= 25 && temperatura >20){
  digitalWrite(leds[0],LOW);
  digitalWrite(leds[1],HIGH);
  digitalWrite(leds[2],LOW);
} else {
  digitalWrite(leds[2],HIGH);
  digitalWrite(leds[1],LOW);
  digitalWrite(leds[0],LOW);
}
}
/*fim do código :)*/