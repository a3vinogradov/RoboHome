#include <WiFi.h>
#include <WebServer.h>

const char* ssid = "BelkoNet";
const char* password = "liskabelko";

WebServer server(80);

void handleRoot() {
  server.send(200, "text/html", "<html><body><h1>ESP32 CSV API</h1><p><a href='/GetLog.csv'>Download CSV</a></p></body></html>");
}

void handleCSV() {
  // Генерируем CSV с заголовком
  String csv = "millis;ext_temp;int_temp;heater\n";
  
  // Добавляем текущие данные
  csv += String(millis()) + ";";
  csv += String(9.84, 1) + ";";
  csv += String(9.23, 1) + ";";
  csv += "on\n";

  // Устанавливаем заголовки для скачивания файла
  server.sendHeader("Content-Type", "text/csv");
  server.sendHeader("Content-Disposition", "attachment; filename=log.csv");
  server.send(200, "text/csv", csv);
}

void setup() {
  Serial.begin(115200);
  
  WiFi.begin(ssid, password);
  Serial.print("Connecting to WiFi");
  
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  
  Serial.println("\nConnected! IP address: " + WiFi.localIP().toString());
  
  // Маршруты
  server.on("/", handleRoot);
  server.on("/GetLog.csv", handleCSV);

  server.begin();
  Serial.println("HTTP server started");
  Serial.println("CSV API available at: http://" + WiFi.localIP().toString() + "/GetLog.csv");
}

void loop() {
  server.handleClient();
}