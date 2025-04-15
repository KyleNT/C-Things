// Inclui a biblioteca b�sica do Arduino
#include <Arduino.h>

void setup() {
  // Inicia a comunica��o serial com 9600 bits por segundo
  Serial.begin(115200);
}

void loop() {
  // Envia a mensagem "Ola Mundo" pela porta serial
  Serial.println("Ola Mundo");

  // Aguarda um segundo antes de enviar novamente
  delay(1000);
}

