#include <WiFi.h>
const char* ssid = "Your_SSID";
const char* password = "Your_PASSWORD";
WiFiServer server(3333); // TCP port
void setup() {
 Serial.begin(115200);
 WiFi.begin(ssid, password);
 Serial.println("Connecting to WiFi...");
 while (WiFi.status() != WL_CONNECTED) delay(1000);
 Serial.println("WiFi connected!");
 Serial.print("ESP32 IP: ");
 Serial.println(WiFi.localIP());

 server.begin();
 Serial.println("TCP server started on port 3333");
}
void loop() {
 WiFiClient client = server.available();
 if (client) {
 Serial.println("Client connected!");
 while (client.connected()) {
 if (client.available()) {
 String msg = client.readStringUntil('\n');
 Serial.print("Received: ");
 Serial.println(msg);
 client.println("Echo: " + msg);
 }
 }
 client.stop();
 Serial.println("Client disconnected.");
 }
}
