#include <Wire.h>
#include <WiFi.h>
#include <ThingSpeak.h>

const char *ssid = "Aakash";
const char *password = "20010714";
const char *apiKey = "F2GO41YJLYP98AUM";

const int SW420 = 2;

WiFiClient client;
unsigned long myChannelNumber = 2024607;

void setup() {
  pinMode(SW420, INPUT);
  Serial.begin(115200);
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Connecting to WiFi...");
  }
  Serial.println("Connected to WiFi");
  ThingSpeak.begin(client);
}

void loop() {
  int vibrationValue = digitalRead(SW420);
  Serial.println(vibrationValue);
  ThingSpeak.writeField(myChannelNumber, 1, vibrationValue, apiKey);
  delay(15000);
}
