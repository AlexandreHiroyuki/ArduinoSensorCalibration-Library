/**********************************************************
  NoSerial.h - Library for debugging code.
  Created by Alexandre Hiroyuki Yamauchi, November 4, 2018.
  Released under the MIT License.
**********************************************************/
#ifndef NOSERIAL_H
#define NOSERIAL_H

#include <Arduino.h>
#include <limits.h>

class NoSerial
{
public:
  NoSerial(bool mode);

  bool autoPrint(int value, int filterVal);
  bool commonPrint(int value);
  bool autoPrintln(int value, int filterVal);
  bool commonPrintln(int value);

private:
  bool _debugMode;
  int _lastPrint;
};

#endif