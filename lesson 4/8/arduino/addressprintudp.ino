#include <ArduinoJson.h>
#include <SPI.h>
#include <WiFiNINA.h>
#include <WiFiUdp.h>
#include <arduino_secrets.h>
void printWifiStatus(void);
void connectToWifi(void);

int status = WL_IDLE_STATUS;

char ssid[] = SECRET_SSID;
char pass[] = SECRET_PASS;
int keyIndex = 0;

unsigned int localPort = 2390;
char packetBuffer[512];
char ReplyBuffer[512];

WiFiUDP Udp;

void setup() {
  Serial.begin(9600);

  while (!Serial) {
    ;
  }

  connectToWifi();
  Serial.println("\nStarting connection to server...");
  Udp.begin(localPort);
}

void loop() {
  int packetSize = Udp.parsePacket();

  if (packetSize) {
    Serial.print("Received packet of size ");
    Serial.println(packetSize);
    Serial.print("From ");
    IPAddress remoteIp = Udp.remoteIP();
    Serial.print(remoteIp);
    Serial.print(", port ");
    Serial.println(Udp.remotePort());

    int len = Udp.read(packetBuffer, 255);

    if (len > 0) {
      packetBuffer[len] = 0;
    }

    Serial.println("Contents:");
    Serial.println(packetBuffer);
    DynamicJsonDocument docRx(512);
    DeserializationError error = deserializeJson(docRx, packetBuffer);

    if (error) {
      Serial.print(F("deserializeJson() failed: "));
      Serial.println(error.f_str());
      return;
    }

    String namestr = docRx["Name"];
    String staddrstr = docRx["Street Address"];
    String provstr = docRx["Province"];
    String poststr = docRx["Postal Code"];
    String countrystr = docRx["Country"];
    String quotestr = docRx["Quote"]; //quote shit

    Serial.print("Name: "); 
    Serial.println(namestr);
    Serial.print("Street Address: "); 
    Serial.println(staddrstr);
    Serial.print("Province: "); 
    Serial.println(provstr);
    Serial.print("Postal Code: "); 
    Serial.println(poststr);
    Serial.print("Country: "); 
    Serial.println(countrystr);
    Serial.print("Quote: "); 
    Serial.println(quotestr); // PRINT QUOTE STUFF

    docRx["Acknowledged"] = "OK";
    serializeJson(docRx, ReplyBuffer);
    serializeJson(docRx, Serial);

    Udp.beginPacket(Udp.remoteIP(), 8877);
    Udp.write(ReplyBuffer);
    Udp.endPacket();
    delay(1000);
  }
}

void connectToWifi(void) {
    if (WiFi.status() == WL_NO_MODULE) {
      Serial.println("Communication with WiFi module failed!");
      while (true);
    }

    String fv = WiFi.firmwareVersion();
    if (fv < WIFI_FIRMWARE_LATEST_VERSION) {
      Serial.println("Please upgrade the firmware");
    }

    while (status != WL_CONNECTED) {
      Serial.print("Attempting to connect to SSID: ");
      Serial.println(ssid);
      status = WiFi.begin(ssid, pass);
      delay(10000);
    }
    Serial.println("Connected to WiFi");
    printWifiStatus();
}

void printWifiStatus() {
    Serial.print("SSID: ");
    Serial.println(WiFi.SSID());
    IPAddress ip = WiFi.localIP();
    Serial.print("IP Address: ");
    Serial.println(ip);
    long rssi = WiFi.RSSI();
    Serial.print("Signal Strength (RSSI):");
    Serial.print(rssi);
    Serial.println(" dBm");
}
