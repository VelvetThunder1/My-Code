/*
 * Example for how to use SinricPro Switch device:
 * - setup a switch device
 * - handle request using callback (turn on/off builtin led indicating device power state)
 * - send event to sinricPro server (flash button is used to turn on/off device manually)
 * 
 * If you encounter any issues:
 * - check the readme.md at https://github.com/sinricpro/esp8266-esp32-sdk/blob/master/README.md
 * - ensure all dependent libraries are installed
 *   - see https://github.com/sinricpro/esp8266-esp32-sdk/blob/master/README.md#arduinoide
 *   - see https://github.com/sinricpro/esp8266-esp32-sdk/blob/master/README.md#dependencies
 * - open serial monitor and check whats happening
 * - check full user documentation at https://sinricpro.github.io/esp8266-esp32-sdk
 * - visit https://github.com/sinricpro/esp8266-esp32-sdk/issues and check for existing issues or open a new one
 */

// Uncomment the following line to enable serial debug output
//#define ENABLE_DEBUG

#include <RCSwitch.h>
#ifdef ENABLE_DEBUG
       #define DEBUG_ESP_PORT Serial
       #define NODEBUG_WEBSOCKETS
       #define NDEBUG
#endif 

#include <Arduino.h>
#ifdef ESP8266 
       #include <ESP8266WiFi.h>
#endif 
#ifdef ESP32   
       #include <WiFi.h>
#endif

#include "SinricPro.h"
#include "src/SinricProSwitch.h"

#define WIFI_SSID         "Mani"    
#define WIFI_PASS         "Welc0me@u"
#define APP_KEY           "5307cb1f-0c28-4cee-af20-48194031688a"      // Should look like "de0bxxxx-1x3x-4x3x-ax2x-5dabxxxxxxxx"
#define APP_SECRET        "2491f9ce-609c-45d5-8fff-d0693068a96b-b6e526ac-2a0a-4a48-8732-db90e0d8ee61"   // Should look like "5f36xxxx-x3x7-4x3x-xexe-e86724a9xxxx-4c4axxxx-3x3x-x5xe-x9x3-333d65xxxxxx"

#define SWITCH_ID       "6331228c36b44d06d4c57597"    // Should look like "5dc1564130xxxxxxxxxxxxxx"
#define BAUD_RATE         9600                // Change baudrate to your need

bool myPowerState = false;
RCSwitch rcSwitch;
/* bool onPowerState(String deviceId, bool &state) 
 *
 * Callback for setPowerState request
 * parameters
 *  String deviceId (r)
 *    contains deviceId (useful if this callback used by multiple devices)
 *  bool &state (r/w)
 *    contains the requested state (true:on / false:off)
 *    must return the new state
 * 
 * return
 *  true if request should be marked as handled correctly / false if not
 */
bool onPowerState(const String &deviceId, bool &state) {
  if (state == true) {
    Serial.println("Sending ON signal");
    rcSwitch.send(5314307, 24);
  } else {
    Serial.println("Sending OFF signal");
    rcSwitch.send(5314316, 24);
  }
  return true;
}
/*
void handleButtonPress() {
  unsigned long actualMillis = millis(); // get actual millis() and keep it in variable actualMillis
  if (digitalRead(BUTTON_PIN) == LOW && actualMillis - lastBtnPress > 1000)  { // is button pressed (inverted logic! button pressed = LOW) and debounced?
    if (myPowerState) {     // flip myPowerState: if it was true, set it to false, vice versa
      myPowerState = false;
    } else {
      myPowerState = true;
    }
    digitalWrite(LED_PIN, myPowerState?LOW:HIGH); // if myPowerState indicates device turned on: turn on led (builtin led uses inverted logic: LOW = LED ON / HIGH = LED OFF)

    // get Switch device back
    SinricProSwitch& mySwitch = SinricPro[SWITCH_ID];
    // send powerstate event
    mySwitch.sendPowerStateEvent(myPowerState); // send the new powerState to SinricPro server
    Serial.printf("Device %s turned %s (manually via flashbutton)\r\n", mySwitch.getDeviceId().c_str(), myPowerState?"on":"off");

    lastBtnPress = actualMillis;  // update last button press variable
  } 
}
*/
// setup function for WiFi connection
void setupWiFi() {
  Serial.printf("\r\n[Wifi]: Connecting");
  WiFi.begin(WIFI_SSID, WIFI_PASS);

  while (WiFi.status() != WL_CONNECTED) {
    Serial.printf(".");
    delay(250);
  }
  Serial.printf("connected!\r\n[WiFi]: IP-Address is %s\r\n", WiFi.localIP().toString().c_str());
}

// setup function for SinricPro
void setupSinricPro() {
  // add device to SinricPro
  SinricProSwitch& mySwitch = SinricPro[SWITCH_ID];

  // set callback function to device
  mySwitch.onPowerState(onPowerState);

  // setup SinricPro
  SinricPro.onConnected([](){ Serial.printf("Connected to SinricPro\r\n"); }); 
  SinricPro.onDisconnected([](){ Serial.printf("Disconnected from SinricPro\r\n"); });
  //SinricPro.restoreDeviceStates(true); // Uncomment to restore the last known state from the server.
  SinricPro.begin(APP_KEY, APP_SECRET);
}

// main setup function
void setup() {
  rcSwitch.enableTransmit(5);
  rcSwitch.setPulseLength(183);

  Serial.begin(BAUD_RATE); Serial.printf("\r\n\r\n");
  setupWiFi();
  setupSinricPro();
}

void loop() {
  SinricPro.handle();
}
