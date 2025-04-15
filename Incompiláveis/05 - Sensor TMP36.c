// Define o pino onde o sinal anal�gico � lido
int sensorPin = A0;
 
void setup() {
  // Inicia a comunica��o serial
  Serial.begin(9600);
}
 
void loop() {
  // L� o valor do pino anal�gico
  int reading = analogRead(sensorPin);
 
  // Converte o valor lido (0 a 1023) em tens�o (0V a 5V)
  float voltage = reading * 5.0 / 1023.0;
 
  // Converte a tens�o em temperatura (cada 10mV equivale a 1�C)
  float temperatureC = (voltage - 0.5) * 100.0;  // Subtrai 0.5V e multiplica por 100 para converter a tens�o em temperatura. A subtra��o de 0.5V � necess�ria porque o TMP36 tem uma sa�da de 0.5V a 0�C. Cada aumento de 0.01V(10mV) na sa�da representa um aumento de 1�C na temperatura, e assim � necess�rio multiplicar por 100.
 
  // Exibe a temperatura na serial
  Serial.print("Temperatura: ");
  Serial.print(temperatureC);
  Serial.println(" C");
 
  // Aguarda um segundo antes da pr�xima leitura
  delay(1000);
}
