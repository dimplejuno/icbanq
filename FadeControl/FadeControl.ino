
int led = 3;

void setup() {
  Serial.begin(9600);
  pinMode(led, OUTPUT);
}

void loop() {
 int sensorValue = analogRead(A0);

 sensorValue = map(sensorValue, 0, 1023, 0, 255);
 analogWrite(led, sensorValue);
 // analogWrite(led, sensorValue/4);

 Serial.print("SensorValue = ");
 Serial.println(sensorValue);

  delay(30);
  
}
