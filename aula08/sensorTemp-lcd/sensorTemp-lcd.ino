#include <Wire.h>
#include <LiquidCrystal.h> // Adiciona a biblioteca "LiquidCrystal" ao projeto

LiquidCrystal lcd(12, 11, 7, 6, 5, 4); // Pinagem do LCD
#include "DHT.h" // Biblioteca para o sensor DHT
// --- CONFIGURAÇÕES ---
// Configura o LCD (endereço 0x27, 16 colunas, 2 linhas)
// Configura o sensor DHT
const int DHT_PIN = 3; // O pino de dados do DHT está no pino digital 3
const int DHT_TYPE = DHT11; // Estamos usando o sensor modelo DHT11
DHT dht(DHT_PIN, DHT_TYPE);
// Variáveis para o controle de tempo
const long intervaloDeLeitura = 2000; // Ler a cada 2000 ms (2segundos)
unsigned long tempoAnterior = 0;
void setup() {
// Inicializa o sensor DHT
dht.begin();
lcd.begin(16, 2);
// Mensagem inicial no LCD
lcd.setCursor(0, 0);
lcd.print("Estacao Climat.");
lcd.setCursor(0, 1);
lcd.print("Iniciando...");
delay(1500); // Um pequeno delay no setup é aceitável
}
void loop() {
// Pega o tempo atual do Arduino
unsigned long tempoAtual = millis();
// É hora de fazer uma nova leitura?
if (tempoAtual - tempoAnterior >= intervaloDeLeitura) {
// Se sim, marca o tempo atual como o da última leitura

tempoAnterior = tempoAtual;
// Lê os dados de temperatura e umidade
float temperatura = dht.readTemperature();
float umidade = dht.readHumidity();
// Verifica se a leitura falhou (retorna 'nan' - Not a Number)
if (isnan(temperatura) || isnan(umidade)) {
lcd.clear();
lcd.setCursor(0, 0);
lcd.print("Falha na leitura");
lcd.setCursor(0, 1);
lcd.print("do sensor!");
return; // Sai e tenta de novo no próximo ciclo
}
// Se a leitura foi bem-sucedida, atualiza o display
lcd.clear(); // Limpa a tela para os novos dados
// Escreve a temperatura na primeira linha
lcd.setCursor(0, 0);
lcd.print("Temp: ");
lcd.print(temperatura, 1); // Imprime o valor com 1 casa decimal
lcd.print((char)223); // Imprime o símbolo de grau (°)
lcd.print("C");
// Escreve a umidade na segunda linha
lcd.setCursor(0, 1);
lcd.print("Umid: ");
lcd.print(umidade, 1); // Imprime o valor com 1 casa decimal
lcd.print(" %");
}
}