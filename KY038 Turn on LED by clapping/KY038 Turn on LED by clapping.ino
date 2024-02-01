int var = 1;

void setup () {
  Serial.begin(9600);
  pinMode (13, OUTPUT);
}
 
void loop () {
  int soundDetected = analogRead(A0);
  if (soundDetected > 580) {
    Serial.println(soundDetected);
    var += 1;
    if (var > 2) {
      var = 1;
    }
    delay(100);
  }
  if (var == 1) {
    digitalWrite(13,HIGH);
  } else {
    digitalWrite(13,LOW);
  }
}