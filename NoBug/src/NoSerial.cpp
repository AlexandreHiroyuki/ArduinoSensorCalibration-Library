/**********************************************************
  NoSerial.h - Library for debugging code.
  Created by Alexandre Hiroyuki Yamauchi, November 4, 2018.
  Released under the MIT License.
**********************************************************/
#include "NoSerial.h"

bool NoSerial::autoPrint(int value)
{
  Serial.println(value);

  _lastPrint = true;
  return true;
}

NoSerial::NoSerial(int baud)
{
  Serial.begin(baud);
}