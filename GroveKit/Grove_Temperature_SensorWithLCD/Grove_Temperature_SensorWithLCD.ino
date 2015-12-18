#include <Wire.h>
#include "rgb_lcd.h"
const int pinTemp = A1;
const int B = 3975;
rgb_lcd lcd;
char dtaUart[15];char dtaLen = 0;int state = 0; boolean incomingSerial = false;
void setup()
{
    Serial.begin(9600);lcd.begin(16, 2);lcd.print("temp = ");
}
void loop()
{
   if(dtaLen == 1)
    {
        int r = (dtaUart[0]-'0')*100 + (dtaUart[1] - '0')*10 + (dtaUart[2] - '0');          // get r
        int g = (dtaUart[4]-'0')*100 + (dtaUart[5] - '0')*10 + (dtaUart[6] - '0');
        int b = (dtaUart[8]-'0')*100 + (dtaUart[9] - '0')*10 + (dtaUart[10] - '0');
        dtaLen = 0;
        lcd.setRGB(r, g, b);
        if(dtaUart[0] == '2') {
          Serial.println("set color blue");
          state = 2;
        } else if(dtaUart[0] == '3') {
          state = 3;
        }
        Serial.println(r);Serial.println(g);Serial.println(b);Serial.println();
    }
    int val = analogRead(pinTemp);
    float resistance = (float)(1023-val)*10000/val;
    float temperature = 1/(log(resistance/10000)/B+1/298.15)-273.15;
    lcd.setCursor(0, 1);lcd.print(temperature);

    if(incomingSerial == false) {
      if(temperature > 26) {
        state = 1;
      }  else {
        state = 0;
      }
    } else {

      if(state == 3) {
        incomingSerial = false;
      }
    }

    if(state == 0) {
      lcd.setRGB(0, 255, 0);
    } else if(state == 1) {
      lcd.setRGB(255, 0, 0);
    } else if(state == 2) {

      lcd.setRGB(0,0,255);
    }
    
    delay(1);
}

void serialEvent()
{
    while(Serial.available())
    {
        incomingSerial = true;
          dtaUart[dtaLen++] = Serial.read();
    }
}

