#include "Arduino.h"
#include "RgbLed.h"

RgbLed::RgbLed(int pinRed, int pinGreen, int pinBlue) {
  _pinRed = pinRed;
  _pinGreen = pinGreen;
  _pinBlue = pinBlue;

  // Setup pin's
  pinMode(_pinRed, OUTPUT);
  pinMode(_pinGreen, OUTPUT);
  pinMode(_pinBlue, OUTPUT);

  // Setup
  setDelay(5L);
  _timestampLastChange = 0;
}

void RgbLed::resume() {
  unsigned long currentTime = millis();
  if (((currentTime - _timestampLastChange) >= _delay) && _enabled && _currentColor != _newColor) {
    
    int red = _currentColor.red;
    int green = _currentColor.green;
    int blue = _currentColor.blue;

    if (red > _newColor.red) {
      red--;
    } else if (red < _newColor.red) {
      red++;
    }
    if (green > _newColor.green) {
      green--;
    } else if (green < _newColor.green) {
      green++;
    }
    if (blue > _newColor.blue) {
      blue--;
    } else if (blue < _newColor.blue) {
      blue++;
    }

    RgbLed::Color color{red, green, blue};
    showRgb(color);
    _currentColor = color;
    
    _timestampLastChange = currentTime;
  }
}

boolean RgbLed::getEnabled() {
  return _enabled;
}

void RgbLed::setEnabled(boolean flag) {
  _enabled = flag;
}

RgbLed::Color RgbLed::getColor() {
  return _currentColor;
}
void RgbLed::setColor(RgbLed::Color color) {
  _newColor = color;
}

long RgbLed::getDelay() {
  return _delay;
}

void RgbLed::setDelay(long number) {
  _delay = number;
}

void RgbLed::showRgb(RgbLed::Color color) {
  analogWrite(_pinRed, color.red);
  analogWrite(_pinGreen, color.green);
  analogWrite(_pinBlue, color.blue);
}

