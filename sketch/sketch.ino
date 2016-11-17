#include "RgbLed.h"

// RGB
#define PIN_LED_RED 9
#define PIN_LED_GREEN 10
#define PIN_LED_BLUE 6

RgbLed rgbLed(PIN_LED_RED, PIN_LED_GREEN, PIN_LED_BLUE);
RgbLed::Color colors[] = {{255, 0, 0}, 
                          {255, 127, 0}, 
                          {255, 255, 0},
                          {0, 255, 0},
                          {0, 0, 255},
                          {123, 0, 130},
                          {143, 0, 255}};
int itemColor;
boolean stoped;
byte inputPackage[4];
int inputByte;

void setup() {
  Serial.begin(9600);
  inputByte = 0;
  
  itemColor = 0;
  stoped = false;
  rgbLed.setEnabled(true);
  rgbLed.setColor(colors[itemColor]);
}

void loop() {
  rgbLed.resume();

  if (!stoped && rgbLed.getColor() == colors[itemColor]) {
    itemColor++;
    if (itemColor >= (sizeof(colors)/sizeof(RgbLed::Color))) {
      itemColor = 0;
    }
    rgbLed.setColor(colors[itemColor]);
  }

  if (Serial.available()) {
    int val = Serial.read();    
    inputPackage[inputByte] = val;
    inputByte++;
    if (inputByte >= 4) {
      if (inputPackage[0] == 0xAA) {
        stoped = true;
        int r = (int) inputPackage[1];
        int g = (int) inputPackage[2];
        int b = (int) inputPackage[3];
        rgbLed.setColor(RgbLed::Color{r, g, b});
      } else if (inputPackage[0] == 0xBB) {
        stoped = false;
        rgbLed.setColor(colors[itemColor]);        
      }
      inputByte = 0;
    }
  } 
}
