#include <SoftwareSerial.h>
//#include "FlightStatus.h"
#include "LibrePilotSerial.h"

SoftwareSerial mySerial(2, 3);  // RX, TX
LibrePilotSerial lps(&mySerial);

int ledPinr = 9;
int ledPiny = 8;
int ledPing = 7;

void setup() {
  // initialize serial communication at 9600 bits per second:
  Serial.begin(57600);
  //initialize LibrePilotSerial Object
  lps.serial->begin(57600);
}

void loop() {
  
  lps.request(FLIGHTSTATUS_OBJID);
  boolean ok = lps.receive(FLIGHTSTATUS_OBJID, FlightStatusDataUnion.arr, 200);

  Serial.print(" Result fs: ");
  Serial.println(FlightStatusDataUnion.data.Armed);      

  if(ok) {
    if(FlightStatusDataUnion.data.Armed == FLIGHTSTATUS_ARMED_DISARMED) {
      analogWrite(ledPinr, 0);
      analogWrite(ledPiny, 0);
      analogWrite(ledPing, 255);
    } else if (FlightStatusDataUnion.data.Armed == FLIGHTSTATUS_ARMED_ARMING) {
      analogWrite(ledPinr, 0);
      analogWrite(ledPiny, 255);
      analogWrite(ledPing, 0);
    } else if (FlightStatusDataUnion.data.Armed == FLIGHTSTATUS_ARMED_ARMED) {
      analogWrite(ledPinr, 255);
      analogWrite(ledPiny, 0);
      analogWrite(ledPing, 0);
    }
  }

  delay(50);
}




