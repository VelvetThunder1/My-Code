#include <RCSwitch.h>

/*
  Example for different sending methods
  
  https://github.com/sui77/rc-switch/
  
*/

RCSwitch mySwitch = RCSwitch();

void setup() {

  Serial.begin(9600);  
  mySwitch.enableTransmit(0);
}

void loop() {  
  mySwitch.send(5313987, 24);
  delay(1000);  
  mySwitch.send(5313996, 24);
  delay(1000);  
}
