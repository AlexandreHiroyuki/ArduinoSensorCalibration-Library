/**********************************************************
  NoSerial.h - Library for debugging code.
  Created by Alexandre Hiroyuki Yamauchi, November 4, 2018.
  Released under the MIT License.
**********************************************************/
#ifndef NoSerial_h
#define NoSerial_h

#include <Arduino.h>

class NoSerial
{
  public:
    NoSerial(int baud);
    bool autoPrint(int value);
    bool commonPrint(int value);

  private:
    bool _lastPrint;
};

#endif