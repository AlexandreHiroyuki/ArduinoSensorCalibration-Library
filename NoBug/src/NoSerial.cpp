/**********************************************************
  NoSerial.h - Library for debugging code.
  Created by Alexandre Hiroyuki Yamauchi, November 4, 2018.
  Released under the MIT License.
**********************************************************/
#include <NoSerial.h>
#include <stdlib.h>

void defaultName()
{
  Serial.print("Nameless: ");
  return;
}

NoSerial::NoSerial(bool mode)
{
  _debugMode = mode;
  _lastPrint = INT_MAX;
  _name = defaultName;
}
NoSerial::NoSerial(bool mode, namePrint name)
{
  _debugMode = mode;
  _lastPrint = INT_MAX;
  _name = name;
}

bool NoSerial::autoPrintln(int value, int filterVal)
{
  if (_debugMode)
  {
    int filter = value - _lastPrint;
    if (((filter > 0) && (filter >= filterVal)) || ((filter < 0) && (filter <= filterVal * -1)))
    {
      _name();
      size_t printed = Serial.print(value);

      if (printed < 3)
        Serial.print("No value received! ");

      _lastPrint = value;
      return true;
    }
  }

  return false;
}

bool NoSerial::commonPrintln(int value)
{
  if (_debugMode)
  {
    _name();
    size_t printed = Serial.print(value);

    if (printed < 3)
      Serial.print("No value received!");

    return true;
  }
}

bool NoSerial::autoPrintln(int value, int filterVal)
{
  if (_debugMode)
  {
    int filter = value - _lastPrint;
    if (((filter > 0) && (filter >= filterVal)) || ((filter < 0) && (filter <= filterVal * -1)))
    {
      _name();
      size_t printed = Serial.println(value);

      if (printed < 3)
        Serial.println("No value received!");

      _lastPrint = value;
      return true;
    }
  }

  return false;
}

bool NoSerial::commonPrintln(int value)
{
  if (_debugMode)
  {
    _name();
    size_t printed = Serial.println(value);

    if (printed < 3)
      Serial.println("No value received!");

    return true;
  }

  return false;
}