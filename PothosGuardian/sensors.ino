// sensors.ino - Pothos Guardian Soil Sensor (Calibrated from YOUR data)

#define SOIL_PIN A0

// Calibrated from real test (Oct 28, 2025):
const int DRY_VALUE  = 970;   // Sensor in dry air (stable high)
const int WET_VALUE  = 410;   // Sensor fully submerged (stable low)

int readSoilMoisture() {
  int raw = analogRead(SOIL_PIN);
  
  // Map raw sensor value to 0–100% moisture:
  // - Dry (970) → 0%
  // - Wet (410) → 100%
  int percent = map(raw, DRY_VALUE, WET_VALUE, 0, 100);
  
  // Clamp to valid range (in case of outliers)
  return constrain(percent, 0, 100);
}