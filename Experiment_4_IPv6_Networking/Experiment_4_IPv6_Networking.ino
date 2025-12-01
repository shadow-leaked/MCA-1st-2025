#include <WiFi.h>
#include <WiFiUdp.h>
#include "esp_netif.h"
#include "lwip/inet.h" // for ip6addr_ntoa()
const char* ssid = "Your_SSID";
const char* password = "Your_PASSWORD";
WiFiUDP udp;
unsigned int localUdpPort = 5555;
char incomingPacket[255];
char replyPacket[] = "Hello from ESP32 IPv6 UDP Server";
void setup() {
 Serial.begin(115200);
 delay(1000);
 Serial.println("\nESP32 IPv6 UDP Server Starting...");
 WiFi.mode(WIFI_STA);
 WiFi.begin(ssid, password);
 Serial.print("Connecting");
 while (WiFi.status() != WL_CONNECTED) {
 Serial.print(".");
 delay(500);
 }
 Serial.println();
 Serial.print("Connected! IPv4: ");
 Serial.println(WiFi.localIP());
 // --- Enable IPv6 ---
 esp_netif_t *netif = esp_netif_get_handle_from_ifkey("WIFI_STA_DEF");
 if (netif) {
 esp_err_t err = esp_netif_create_ip6_linklocal(netif);
 if (err == ESP_OK) Serial.println("IPv6 link-local address created.");
 else Serial.printf("Failed to create IPv6 address: %d\n", err);
 }
 // --- Wait for IPv6 to be assigned ---
 esp_ip6_addr_t ip6;
 Serial.println("Waiting for IPv6 address...");
 bool ipv6_ready = false;
 for (int i = 0; i < 20; i++) { // wait up to ~10 seconds
 if (esp_netif_get_ip6_linklocal(netif, &ip6) == ESP_OK) {
 ipv6_ready = true;
 break;
 }
 delay(500);
 }
 if (ipv6_ready) {
 char buf[64];
 strcpy(buf, ip6addr_ntoa((ip6_addr_t*)&ip6));
 Serial.printf("IPv6 Address: %s\n", buf);
 } else {
 Serial.println("IPv6 address not ready yet.");
 }
 udp.begin(localUdpPort);
 Serial.printf("UDP server listening on port %d\n", localUdpPort);
}
void loop() {
 int packetSize = udp.parsePacket();
 if (packetSize) {
 int len = udp.read(incomingPacket, sizeof(incomingPacket) - 1);
 if (len > 0) incomingPacket[len] = 0;
 Serial.printf("Received %d bytes from %s port %d\n",
 packetSize,
udp.remoteIP().toString().c_str(),
udp.remotePort());
 Serial.printf("Data: %s\n", incomingPacket);
 udp.beginPacket(udp.remoteIP(), udp.remotePort());
 udp.write((const uint8_t*)replyPacket, strlen(replyPacket));
 udp.endPacket();
 Serial.println("Sent reply.");
 }
}