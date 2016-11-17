#ifndef RgbLed_h
#define RgbLed_h

#include "Arduino.h"

class RgbLed {

  public:

    struct Color { 
      int red; 
      int green; 
      int blue;

      bool operator!=(const Color& object) {
        return object.red != red 
            || object.green != green
            || object.blue != blue;
      }

      bool operator==(const Color& object) {
        return object.red == red 
            && object.green == green
            && object.blue == blue;
      }
    };
  
    RgbLed(int pinRed, int pinGreen, int pinBlue);
    
    void resume();
    boolean getEnabled();
    void setEnabled(boolean flag);
    void setColor(Color color);
    Color getColor();
    long getDelay();
    void setDelay(long number);
    
  private:
  // Pin's
    int _pinRed;
    int _pinGreen;
    int _pinBlue;

  // State's
    boolean _enabled;
    Color _currentColor;
    Color _newColor;
    long _delay;
    unsigned long _timestampLastChange;

    void showRgb(Color color);
};

#endif

