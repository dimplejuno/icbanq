
int led = 3;
int pushButton = 2;
void setup() {
  Serial.begin(9600);
  pinMode(pushButton, INPUT);
  pinMode(led, OUTPUT);
}
void loop() {
    int buttonState = digitalRead(pushButton);
    Serial.print("Button State = ");
    // Serial.println(buttonState);
    if(buttonState == HIGH) {
      digitalWrite(led, HIGH); 
      Serial.println("on");
    } else {
     digitalWrite(led, LOW); 
      Serial.println("off");
    }
    delay(1);
}
