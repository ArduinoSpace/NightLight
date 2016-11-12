#include "RgbLed.h"

// RGB
#define PIN_LED_RED 9
#define PIN_LED_GREEN 10
#define PIN_LED_BLUE 11

RgbLed rgbLed(PIN_LED_RED, PIN_LED_GREEN, PIN_LED_BLUE);
RgbLed::Color colors[] = {{255, 0, 0}, 
                          {255, 127, 0}, 
                          {255, 255, 0},
                          {0, 255, 0},
                          {0, 0, 255},
                          {123, 0, 130},
                          {143, 0, 255}};
int itemColor;

void setup() {
  itemColor = 0;
  rgbLed.setEnabled(true);
  rgbLed.setColor(colors[itemColor]);
}

void loop() {
  rgbLed.resume();

  if (rgbLed.getColor() == colors[itemColor]) {
    itemColor++;
    if (itemColor >= (sizeof(colors)/sizeof(RgbLed::Color))) {
      itemColor = 0;
    }
    rgbLed.setColor(colors[itemColor]);
  }
 
}
