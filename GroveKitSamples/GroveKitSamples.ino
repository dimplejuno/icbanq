int pushButton = 2;
int led = 6;

int rotary = A0;

void setup() {
  Serial.begin(9600);
  pinMode(pushButton, INPUT);
  pinMode(led, OUTPUT);
}

void loop() {
   int buttonState = digitalRead(pushButton);
   int sensorValue = analogRead(A0);
   Serial.println(sensorValue);
   
  Serial.println(buttonState);
   if(buttonState == HIGH) {
      digitalWrite(led, HIGH); 
      Serial.println("on");
    } else {
     digitalWrite(led, LOW); 
      Serial.println("off");
    }
  delay(1);   

}
