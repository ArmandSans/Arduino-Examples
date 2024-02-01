#include <Servo.h>
Servo servo1;
Servo servo2;

int pinservo1 = A0;   
int pinservo2 = A1;   
int pulsomin = 500;  
int pulsomax = 2400;
int potenciometro = 0;
unsigned long tiempoactual = 0;
unsigned long tiempoanterior = 0;
int espacio = 1000;
int var = 1;

void setup() {
  Serial.begin(9600);
  pinMode(7,INPUT_PULLUP);
  servo1.attach(pinservo1,pulsomin,pulsomax);
  servo2.attach(pinservo2,pulsomin,pulsomax);
}

void loop() {
    tiempoactual = millis();  //Seleccionar servo con un solo botón manteniendo pulsado
    if (tiempoactual - tiempoanterior >= espacio) {
      tiempoanterior = tiempoactual;
      if (digitalRead(7) == 0) {
        var += 1;
        if (var == 3){
          var = 1;
        }
        Serial.println(var);
      }
    }
    if (var == 1) {   //Controlar servomotor 1
      potenciometro = analogRead(A2);
      map(potenciometro, 0, 1023, 0, 180);
      servo1.write(potenciometro);

    }

    if (var == 2) {   //Controlar servomotor 2
      potenciometro = analogRead(A2);
      map(potenciometro, 0, 1023, 0, 180);
      servo2.write(potenciometro);

    }
}     
 
