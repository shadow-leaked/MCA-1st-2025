#include <WiFi.h>
#include <WiFiUdp.h>
const char* ssid = "Your_SSID";
const char* password = "Your_PASSWORD";
WiFiUDP udp;
unsigned int localUdpPort = 5555;
char incomingPacket[255];
char replyPacket[] = "Hello from ESP32 UDP Server";
void setup() {
 Serial.begin(115200);
 Serial.println();
 Serial.println("Connecting to WiFi...");
 WiFi.begin(ssid, password);
 while (WiFi.status() != WL_CONNECTED) {
 delay(1000);
 Serial.print(".");
 }
 Serial.println("\nWiFi connected!");
 Serial.print("ESP32 IP Address: ");
 Serial.println(WiFi.localIP());
 udp.begin(localUdpPort);
 Serial.printf("UDP server started on port %d\n", localUdpPort);
}
void loop() {
 int packetSize = udp.parsePacket();
 if (packetSize) {
 // Receive UDP packet
 int len = udp.read(incomingPacket, sizeof(incomingPacket) - 1);
 if (len > 0) incomingPacket[len] = 0;
 Serial.printf("Received %d bytes from %s, port %d\n",
 packetSize,
udp.remoteIP().toString().c_str(),
udp.remotePort());
 Serial.printf("UDP packet contents: %s\n", incomingPacket);
 // Send back reply
 udp.beginPacket(udp.remoteIP(), udp.remotePort());
 udp.write((const uint8_t*)replyPacket, strlen(replyPacket));
 udp.endPacket();
 Serial.println("Sent reply to client.");
 }
}