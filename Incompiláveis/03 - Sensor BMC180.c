#include <Adafruit_BMP085.h>
#include <Wire.h>  // Biblioteca para usar I2C

Adafruit_BMP085 bmp; //Cria uma inst�ncia do objeto bmp para interagir com o sensor 

void setup() {
Serial.begin(115200);

  if (!bmp.begin()) {  // Inicializa a comunica��o com o sensor BMP085.
  Serial.println("Sensor BMP085 n�o encontrado!");
  while (1) {} // Entra em um loop infinito, efetivamente parando o programa se o sensor n�o 
//for encontrado
  }
}

void loop(){

Serial.println("");
Serial.print("Temp: ");
Serial.print(bmp.readTemperature()); // L� a temperatura atual do sensor BMP085 e imprime 
// na porta serial
Serial.println(" C");

Serial.print("Pres: ");
Serial.print(bmp.readPressure());
Serial.println(" Pa");

Serial.print("Alt: ");
Serial.print(bmp.readAltitude(102300)); // Calcula a altitude baseada na press�o atmosf�rica 
//medida em compara��o com a press�o ao n�vel do mar especificada como par�metro 
//(102300 Pa neste exemplo)
Serial.println(" metros");

delay(2000);
}
