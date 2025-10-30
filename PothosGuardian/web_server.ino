// web_server.ino - Mobile-optimized Pothos Guardian Dashboard

#include <ESP8266WebServer.h>
extern int readSoilMoisture(); // Declare function from sensors.ino

ESP8266WebServer server(8423);

String getMoistureHTML() {
  int moisture = readSoilMoisture();
  String alert = "";
  
  if (moisture < 30) {
    alert = "<div style='background:#ff4444;color:white;padding:8px;margin:10px 0;border-radius:6px;font-weight:bold;'>💧 NEEDS WATER!</div>";
  }

  String html = R"rawliteral(
<!DOCTYPE html>
<html>

<head>
  <meta charset="utf-8">
  <meta http-equiv="refresh" content="50">
  <meta name="viewport" content="width=device-width, initial-scale=1">
  <title>Pothos Guardian</title>
  <style>
    body {
      background: #0f0f0f;
      color: #e0e0e0;
      font-family: 'Segoe UI', Tahoma, Geneva, Verdana, sans-serif;
      margin: 0;
      padding: 0;
      display: flex;
      justify-content: center;
      align-items: center;
      min-height: 100vh;
    }
    .card {
      width: 85%;
      max-width: 300px;
      background: #1a1a1a;
      border-radius: 16px;
      padding: 24px;
      box-shadow: 0 4px 12px rgba(0,0,0,0.3);
      text-align: center;
      margin-bottom: 1rem;
    }
    h1 {
      font-size: 1.4rem;
      margin: 0 0 20px;
      color: #4caf50;
    }
    .moisture-value {
      font-size: 3.2rem;
      font-weight: bold;
      margin: 16px 0;
      color: white;
    }
    .label {
      font-size: 0.95rem;
      color: #aaa;
      margin-bottom: 20px;
    }
  </style>
</head>
<body>
  <div class="card">
    <h1>🌱 Pothos Guardian</h1>
    <div class="label">Soil Moisture</div>
    <div class="moisture-value">)rawliteral";

  html += String(moisture) + "%</div>";
  html += alert;
  html += R"rawliteral(
    <div style="font-size:0.8rem;color:#666;margin-top:20px;">
      Local • Offline • Live
    </div>
  </div>
</body>
</html>
)rawliteral";

  return html;
}

void handleRoot() {
  server.send(200, "text/html", getMoistureHTML());
}

void initWebServer() {
  server.on("/", handleRoot);
  server.begin();
  Serial.println("HTTP server started on port 8423");
}

void handleWebServer() {
  server.handleClient();
}