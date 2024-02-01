#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>
 
#define CE_PIN 9
#define CSN_PIN 10

byte direccion[5] ={1,1,1,1,1}; 

RF24 radio(CE_PIN, CSN_PIN);

int datos[1];

void setup()
{
  radio.begin();
  Serial.begin(9600); 
  pinMode(8,OUTPUT);
  radio.setDataRate(RF24_250KBPS); 
  radio.openReadingPipe(1, direccion);
  radio.startListening();
}
 
void loop() {
     
     if ( radio.available() ) {
     radio.read(datos,sizeof(datos));
     Serial.println(datos[0]);
     if (datos[0] == 1) {
        digitalWrite(8,LOW);
     } else {
        digitalWrite(8,HIGH);
     }
     }
    delay(25);
}