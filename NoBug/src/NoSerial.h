/**********************************************************
  NoSerial.h - Library for debugging code.
  Created by Alexandre Hiroyuki Yamauchi, November 4, 2018.
  Released under the MIT License.
**********************************************************/
#ifndef NOSERIAL_H
#define NOSERIAL_H

#include <Arduino.h>
#include <limits.h>

typedef void (*namePrint)(void);

void defaultName();
class NoSerial
{
  public:
    NoSerial(bool mode);
    NoSerial(bool mode, namePrint name);

    bool autoPrint(int value, int filterVal);
    bool commonPrint(int value);

  private:
    bool _debugMode;
    int _lastPrint;
    namePrint _name;
};

#endif