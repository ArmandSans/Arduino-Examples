#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>

#define CE_PIN 9
#define CSN_PIN 10
 
byte direccion[5] ={1,1,1,1,1};
RF24 radio(CE_PIN, CSN_PIN);
int datos[1];
int boton;

void setup()
{
  radio.begin();
  Serial.begin(9600); 
  radio.setDataRate(RF24_250KBPS); 
  radio.setPALevel(RF24_PA_MAX); 
  radio.openWritingPipe(direccion);
  pinMode(8,INPUT_PULLUP);
}
 
void loop()
{ 
 boton = digitalRead(8);
 datos[0] = boton;
 Serial.println(datos[0]);
 radio.write(datos, sizeof(datos));
 delay(25);
}
 