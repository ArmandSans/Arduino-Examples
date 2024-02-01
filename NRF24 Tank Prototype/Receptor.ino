
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
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  Serial.begin(9600);
  radio.begin();
  radio.openReadingPipe(1,direccion);
  radio.startListening();
  radio.setPALevel(RF24_PA_MAX); 
  radio.setDataRate(RF24_250KBPS); 		 

}

void loop() {
 if (radio.available()){
    radio.read(datos,sizeof(datos));
    if (datos[0] == 1){
      digitalWrite(5,HIGH);
    } else {
       digitalWrite(5,LOW);
    }
    if (datos[1] == 1){
       digitalWrite(6,HIGH);
    } else {
       digitalWrite(6,LOW);
    }
  
  delay(50);

}
}
