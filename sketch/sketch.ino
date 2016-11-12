// RGB
#define PIN_LED_RED 9
#define PIN_LED_GREEN 10
#define PIN_LED_BLUE 11

const long delayLed = 5;
unsigned long timestampLastChangeLed;
int currentPinLed;
int currentBrightLed;
boolean showLed;

void setup() {
  pinMode(PIN_LED_RED, OUTPUT);
  pinMode(PIN_LED_GREEN, OUTPUT);
  pinMode(PIN_LED_BLUE, OUTPUT);

  timestampLastChangeLed = 0;
  currentPinLed = PIN_LED_RED;
  currentBrightLed = 0;
  showLed = true;
}

void loop() {
  if (millis() - timestampLastChangeLed >= delayLed) {
    if (currentBrightLed <= -1 || currentBrightLed >= 256) {
      showLed = !showLed;
      currentBrightLed = showLed ? 0 : 255;
      switch(currentPinLed) {
        case PIN_LED_RED:
          currentPinLed = PIN_LED_BLUE;
          break;
          case PIN_LED_GREEN:
          currentPinLed = PIN_LED_RED;
          break;
          case PIN_LED_BLUE:
          currentPinLed = PIN_LED_GREEN;
          break;
      }
    }
    analogWrite(currentPinLed, currentBrightLed);
    showLed ? currentBrightLed++ : currentBrightLed --;
    timestampLastChangeLed = millis();
  }
  
}
