// PothosGuardian.ino

#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>

// === Wi-Fi Settings ===
const char* ssid = "NETGEAR88";        // ← CHANGE THIS
const char* password = "Fios-u350k-G5"; // ← CHANGE THIS


// Declare sensor function (defined in sensors.ino)
int readSoilMoisture();

void setup() {
  Serial.begin(115200);
  delay(1000);
  Serial.println("\n=== Starting Web Server ===");

  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("\nConnected! IP: " + WiFi.localIP().toString());

  initWebServer(); // ← from web_server.ino
}

void loop() {
  handleWebServer(); // ← from web_server.ino
}

