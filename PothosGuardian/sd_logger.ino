// sd_logger.ino
// MicroSD logging module for Pothos Guardian (ESP8266)

#include <SPI.h>
#include <SD.h>

// === Pin Configuration ===
#define SD_CS_PIN D0  // ← Change from D8 to D0

// === Internal State ===
static bool sd_ready = false;

// === Public Functions ===

void initSD() {
  Serial.println("=== SD Card Test ===");
  Serial.print("CS Pin: ");
  Serial.println(SD_CS_PIN);

  pinMode(SD_CS_PIN, OUTPUT);
  digitalWrite(SD_CS_PIN, HIGH); // Ensure CS starts HIGH

  if (!SD.begin(SD_CS_PIN)) {
    Serial.println("❌ SD.begin() failed");
    // Try common troubleshooting steps
    Serial.println("→ Check wiring, power, and formatting");
    sd_ready = false;
    return;
  }

  if (!SD.exists("/")) {
    Serial.println("❌ Root directory not found");
    sd_ready = false;
    return;
  }

  Serial.println("✅ SD card initialized!");
  sd_ready = true;
}


bool isSDReady() {
  return sd_ready;
}

void logMessage(const char* message) {
  if (!sd_ready) {
    return;
  }

  File logFile = SD.open("/logs/plant.log", FILE_WRITE);
  if (!logFile) {
    Serial.println("SD: Failed to open log file");
    return;
  }

  // Log format: "Uptime 123s: Soil: 42%"
  unsigned long seconds = millis() / 1000;
  logFile.print("Uptime ");
  logFile.print(seconds);
  logFile.print("s: ");
  logFile.println(message);

  logFile.close();
}