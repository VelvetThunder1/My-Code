#include <ArduinoJson.h>
#include <Arduino.h>
#include "fauxmoESP.h"
#include <RCSwitch.h>
#ifdef ESP32
  #include <WiFi.h>
#else
  #include <ESP8266WiFi.h>
#endif
#define SERIAL_BAUDRATE 115200

RCSwitch mySwitch = RCSwitch();

#define WIFI_SSID "Mani"
#define WIFI_PASS "Welc0me@u"
#define app1 "Outlet 1"
#define app2 "Outlet 2"
#define app3 "Outlet 3"
fauxmoESP fauxmo;

void wifiSetup() {
  // Set WIFI module to STA mode
  WiFi.mode(WIFI_STA);
  Serial.printf("[WIFI] Connecting to %s ", WIFI_SSID);
  WiFi.begin(WIFI_SSID, WIFI_PASS);
  while (WiFi.status() != WL_CONNECTED) {
    Serial.print(".");
    delay(100);
  }
  Serial.println();
  Serial.printf("[WIFI] STATION Mode, SSID: %s, IP address: %s\n", WiFi.SSID().c_str(), WiFi.localIP().toString().c_str());
}

void setup() {
  // Init serial port and clean garbage
  Serial.begin(SERIAL_BAUDRATE);
  Serial.println();
  
  mySwitch.enableTransmit(0);
  
  // Wi-Fi connection
  wifiSetup();
  
  fauxmo.createServer(true); 
  fauxmo.setPort(80); 
  fauxmo.enable(true);
  fauxmo.addDevice(app1);
  fauxmo.addDevice(app2);
  fauxmo.addDevice(app3);

  fauxmo.onSetState([](unsigned char device_id, const char * device_name, bool state, unsigned char value) {    
    Serial.printf("[MAIN] Device #%d (%s) state: %s value: %d\n", device_id, device_name, state ? "ON" : "OFF", value);
    if ( (strcmp(device_name, app1) == 0) ) {
      Serial.println("Outlet 1 Switched by Alexa");
      if (state) {
        
      } else {
        
      }
    }
    if ( (strcmp(device_name, app2) == 0) ) {
      Serial.println("Outlet 2 switched by Alexa");
      if (state) {
        
      } else {
        
      }
    }
    if ( (strcmp(device_name, app3) == 0) ) {
      Serial.println("Outlet 3 switched by Alexa");
      if (state) {
        
      } else {
        
      }
    }
  });

}

void loop() {
  fauxmo.handle();

  static unsigned long last = millis();
  if (millis() - last > 5000) {
    last = millis();
    Serial.printf("[MAIN] Free heap: %d bytes\n", ESP.getFreeHeap());
  }
}
 
