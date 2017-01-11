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
    void send(unsigned long objId, byte* data, int length);    //datapointer: pointer do a *DataUnion.arr element
    SoftwareSerial* serial;
    
  private:
    byte _pBuf[265];  //internal packetbuffer for receiving a generic packet
    byte _crc(int len);  //calc crc over _pBuf with length len
    byte _crc(byte* header, byte* data, int len);  //calc crc over header and data array; expects 10 byte header and len byte data array pointers
};

#endif
