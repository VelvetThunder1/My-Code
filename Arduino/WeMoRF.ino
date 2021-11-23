#include <ArduinoJson.h>
#include <Arduino.h>
#include <ESP8266WiFi.h>
#include "fauxmoESP.h"
#include <RCSwitch.h>

RCSwitch mySwitch = RCSwitch();

/* Network credentials */
#define WIFI_SSID "Mani"
#define WIFI_PASS "Welc0me@u"    

/* Belkin WeMo emulation */
fauxmoESP fauxmo;

/* -----------------------------------------------------------------------------
 Wifi Setup
 -----------------------------------------------------------------------------*/
void wifiSetup() {
   // Set WIFI module to STA mode
   WiFi.mode(WIFI_STA);

   // Connect
   Serial.println ();
   Serial.printf("[WIFI] Connecting to %s ", WIFI_SSID);
   Serial.println();
   WiFi.begin(WIFI_SSID, WIFI_PASS);

   // Wait
   while (WiFi.status() != WL_CONNECTED) 
   {
      Serial.print(".");
      delay(100);
   }
   Serial.print(" ==> CONNECTED!" );
   Serial.println();

   // Connected!
   Serial.printf("[WIFI] STATION Mode, SSID: %s, IP address: %s\n", WiFi.SSID().c_str(), WiFi.localIP().toString().c_str());
   Serial.println();
}

void setup() 
{
   Serial.begin(9600);
   //setup and wifi connection
   wifiSetup();
  
  // Transmitter is connected to Arduino Pin #10  
   mySwitch.enableTransmit(3);
 
   // Device Names for Simulated Wemo switches
   fauxmo.addDevice("Outlet One");
   fauxmo.addDevice("Outlet Two");
   fauxmo.addDevice("Outlet Three");
   fauxmo.onMessage(callback); 
}

void loop() 
{
  fauxmo.handle();
}

/* ---------------------------------------------------------------------------
 Device Callback
 ----------------------------------------------------------------------------*/
void callback(uint8_t device_id, const char * device_name, bool state) 
{
  Serial.print("Device "); Serial.print(device_name); 
  Serial.print(" state: ");
  if (state) 
  {
    Serial.println("ON");
  } 
  else 
  {
    Serial.println("OFF");
  }
  
  //Switching action on detection of device name
 
  if ( (strcmp(device_name, "Outlet One") == 0) ) 
  {
    if (!state) 
    {
      mySwitch.send(5313843, 24);
    } 
    else 
    {
      mySwitch.send(5313852, 24);
    }
  }
  
  if ( (strcmp(device_name, "Outlet Two") == 0) ) 
  {
    if (!state) 
    {
      mySwitch.send(5313987, 24);
    } 
    else 
    {
      mySwitch.send(5313996, 24);
    }
  }
  if ( (strcmp(device_name, "Outlet Three") == 0) ) 
  {
    if (!state) 
    {
      mySwitch.send(5314307, 24);
    } 
    else 
    {
      mySwitch.send(5313996, 24);
    }
  }
}      
