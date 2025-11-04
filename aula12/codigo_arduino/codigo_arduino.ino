// Inclusão das bibliotecas 
#include <Servo.h>
#include <DHT.h>
#include <DHT_U.h>
#include <LiquidCrystal.h>

// Criando o objeto "servo" um servo motor
Servo servo;

//Definindoo o pino e o tipo do sensor DHT 
#define DHTPIN 8
#define DHTTYPE DHT11
DHT dht(DHTPIN, DHTTYPE);

//Definindo os pinos do display lcd 
const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

// Definindo os pinos do ldr e o pino da lâmpada a ser controlada pelo ldr
int pinoLDR = A0; 
int LAMP = 9;


void setup() {
  // definindo o pino do servo
  servo.attach(10);

  // Colocando uma mensagem inicial no lcd 
  lcd.begin(16,2);
  lcd.setCursor(0,0);
  lcd.print("Código Iniciando...");
  delay(2000);
  lcd.clear();
  
  // Iniciando a comunicação serial
  Serial.begin(9600);

  // Inciando o sensor
  dht.begin();
}

void loop() {
 if (Serial.available() > 0) {
    // pegando o comando enviado do site
    char command = Serial.read();

    // puxa os valores de humidade, luminosidade e temperatura
    float h = dht.readHumidity();
    float t = dht.readTemperature();
    int LDR = sensorLum();

    escreverDisplay(t,h,LDR);

    // selecionando o que o arduino deve fazer a partir do comando enviado
    switch (command) {
      case 'A':
        // (Abre a válvula) gira o servo em 90 graus
        servo.write(90);
        break;
      case 'a':
        // (fecha a válvula) volta ao normal
        servo.write(0);
        break;
      case 'T':
        // Verifica se tem algum valor nulo
        if (isnan(t) || isnan(h) || isnan(LDR)) {
          Serial.println("ERRO");
        } else {
          // Envia os dados de volta para o Python no formato "temp;umid;lum"
          Serial.print(t);
          Serial.print(";");
          Serial.print(h);
          Serial.print(";");
          Serial.println(LDR);
        }
        if (h < 45) {
          // abrirValvula();
        }
        break;
    } 
  // Variando a intensidade da luz da lâmpada de acordo com a luminosidade
  int valorLamp = map(LDR, 0 ,100, 255 ,0 );
  analogWrite(LAMP, valorLamp);

  
  }
}
// função para mapear o valor do LDR
int sensorLum (){
  int valorLDR = analogRead(pinoLDR);
  int lum = map(valorLDR, 0 , 1023, 0, 100);
  return lum; 
}

void escreverDisplay (float t, float h, int lum) {
  lcd.clear();

  //Temperatura
  lcd.setCursor(0,0);
  lcd.print("Temp:");
  lcd.setCursor(5,0);
  lcd.print(t);
  lcd.setCursor(10,0);
  lcd.print("C");

   // Luminosidade
  lcd.setCursor(12,0);
  lcd.print("L:");
  lcd.print(lum);
  lcd.print("%");

  // Humidade
  lcd.setCursor(0,1);
  lcd.print("Humidade:");
  lcd.setCursor(9,1);
  lcd.print(h, 0); // sem casa decimal
  lcd.print("%");
}

void abrirValvula() {
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Irrigando");
  servo.write(90);
  delay(10000);
  servo.write(0);
  lcd.clear();
}