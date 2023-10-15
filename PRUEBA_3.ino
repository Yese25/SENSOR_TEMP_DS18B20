/// Skecht para leer datos de temperatura del sensor DS18B20, termocupla sumergible digital
/// Que utiliza protocolo One-wire, resolución configuragle de 9 a 12 bits
#include <DallasTemperature.h>
#include <OneWire.h>
OneWire ourWire(2); //Se establece el pin 2 como bus OneWire
DallasTemperature sensors(&ourWire); //Se declara una variable u objeto para nuestro sensor
int Address=0;
void setup() {
delay(1000);
Serial.begin(9600);
sensors.begin(); //Se inicia el sensor
sensors.setResolution(Address, 12); // resolución de 9 bits
}
void loop() {
sensors.requestTemperatures(); //Se envía el comando para leer la temperatura
float temp= sensors.getTempCByIndex(0); //Se obtiene la temperatura en ºC la posición ceero
Serial.print("Temperatura T1= ");
Serial.print(temp);
Serial.println(" C");
sensors.requestTemperatures(); //Se envía el comando para leer la temperatura

temp= sensors.getTempCByIndex(1); //Se obtiene la temperatura en ºC la posición ceero
Serial.print("Temperatura T2= ");
Serial.print(temp);
Serial.println(" C");
sensors.requestTemperatures(); //Se envía el comando para leer la temperatura

temp= sensors.getTempCByIndex(2); //Se obtiene la temperatura en ºC la posición ceero
Serial.print("Temperatura T3= ");
Serial.print(temp);
Serial.println(" C");
delay(2000); 
}
