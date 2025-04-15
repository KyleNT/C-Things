void setup() {
  pinMode(2, INPUT); //Pino 2 como Entrada
  pinMode(13, OUTPUT); //PINO 3 como saída
}

void loop() {

  if (digitalRead(2) == HIGH) // Verifica se sensor PIR está acionado
  {
  digitalWrite(13, HIGH);   // Liga o LED da placa
  delay(100);                       // espera 100 milisecondos
  digitalWrite(13, LOW);   //DesLiga o LED da placa
  delay(100);                       // espera 100 milisecondos
  }
}

