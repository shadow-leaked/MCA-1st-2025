#include <WiFi.h>
const char* ssid = "Your_SSID";
const char* password = "Your_Password";
void setup() {
Serial.begin(115200);
delay(1000);
Serial.println("...");
Serial.print("Connecting to "); Serial.println(ssid);
WiFi.mode(WIFI_STA);
WiFi.begin(ssid, password);
int tries=0;
while (WiFi.status() != WL_CONNECTED && tries < 30) {
delay(500);
Serial.print(".");
tries++;
}
if (WiFi.status() == WL_CONNECTED) {
Serial.println();
Serial.print("Connected. IP: ");
Serial.println(WiFi.localIP());
} else {
Serial.println();
Serial.println("Failed to connect.");
}
}
void loop() {
// nothing
}