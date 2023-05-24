// Criado por Guilherme G. Evangelista

int Temp_Pin = A0;
 int Vent_Pin = 3;
 int Led_Pin = 4;
 int Alarme_Pin = 5;

void setup()
{
  Serial.begin(9600);
  pinMode(Temp_Pin, INPUT);
  pinMode(Vent_Pin, OUTPUT);
  pinMode(Led_Pin, OUTPUT);
  pinMode(Alarme_Pin, OUTPUT);
}

void loop()
{
   
  float temperatura = getTemperature();
  
  Serial.print("Temperatura: ");
  Serial.print(temperatura);
  Serial.println(" °C");
  
  if (temperatura >= 30) {
    digitalWrite(Vent_Pin, HIGH);
  } else 
  {
    digitalWrite(Vent_Pin, LOW);
  }
  
  if (temperatura > 50) {
    digitalWrite(Led_Pin, HIGH);
    digitalWrite(Alarme_Pin, HIGH);
  } else 
  {
    digitalWrite(Led_Pin, LOW);
    digitalWrite(Alarme_Pin, LOW);
  }
  
  delay(1000);
}

  float getTemperature() {
  int sensorValue = analogRead(Temp_Pin);
  float voltage = (sensorValue / 1023.0) * 5.0;
  float temperatura = (voltage - 0.5) * 100.0;
  return temperatura;
  }
