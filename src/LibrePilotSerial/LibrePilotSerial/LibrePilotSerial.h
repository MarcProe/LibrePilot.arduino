#ifndef LibrePilotSerial_h
#define LibrePilotSerial_h

#include "Arduino.h"
#include <SoftwareSerial.h>

#define byte uint8_t

union {
    float f;
    unsigned long ul;
 } u2f;

class LibrePilotSerial {
  public:
    LibrePilotSerial(SoftwareSerial* ser);
    boolean receive(unsigned long objId, byte *ret, unsigned int timeout = 100);
    void request(unsigned long objId);
    SoftwareSerial* serial;
    
  private:
    byte _pBuf[265];
    byte _crc(int len);
};

#endif
