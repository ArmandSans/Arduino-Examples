
#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>

//Declaremos los pines CE y el CSN
#define CE_PIN 9
#define CSN_PIN 10

RF24 radio(CE_PIN, CSN_PIN);

byte direccion[4] = {1,2,3,4};
int datos[2];


void setup() {
  pinMode(2, INPUT_PULLUP);
  pinMode(3, INPUT_PULLUP);
  Serial.begin(9600);

  radio.begin();
  radio.openWritingPipe(direccion);
  radio.setDataRate(RF24_250KBPS); 	
  radio.setPALevel(RF24_PA_MAX);
}

void loop() {
 if (digitalRead(2) == 0){
    datos[0] = 1;
 } else {
    datos[0] = 0;
 }
 if (digitalRead(3) == 0) {
    datos[1] = 1;
 } else {
  datos[1] = 0;
 }
 radio.write(datos, sizeof(datos));

 delay(50);
}
