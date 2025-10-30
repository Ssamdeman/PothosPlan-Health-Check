// led_controller.ino - Visual soil moisture status

#define LED_RED    D1   // GPIO5
#define LED_BLUE   D2   // GPIO4
#define LED_GREEN  D3   // GPIO0

void setupLEDs() {
  pinMode(LED_RED, OUTPUT);
  pinMode(LED_BLUE, OUTPUT);
  pinMode(LED_GREEN, OUTPUT);
  turnOffAllLEDs();
}

void turnOffAllLEDs() {
  digitalWrite(LED_RED, LOW);
  digitalWrite(LED_BLUE, LOW);
  digitalWrite(LED_GREEN, LOW);
}

void updateLEDs(int moisturePercent) {
  turnOffAllLEDs();
  
  if (moisturePercent < 30) {
    // Dry → RED
    digitalWrite(LED_RED, HIGH);
  } else if (moisturePercent > 70) {
    // Wet → GREEN
    digitalWrite(LED_GREEN, HIGH);
  } else {
    // Healthy → BLUE
    digitalWrite(LED_BLUE, HIGH);
  }
}