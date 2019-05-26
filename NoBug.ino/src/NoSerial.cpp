/**********************************************************
  NoSerial.h - Library for debugging code.
  Created by Alexandre Hiroyuki Yamauchi, November 4, 2018.
  Released under the MIT License.
**********************************************************/
#include <NoSerial.h>
#include <stdlib.h>

NoSerial::NoSerial(bool mode)
{
  _debugMode = mode;
  _lastPrint = INT_MAX;
}

bool NoSerial::autoPrint(int value, int filterVal)
{
  if (_debugMode)
  {
    int filter = value - _lastPrint;
    if (((filter > 0) && (filter >= filterVal)) || ((filter < 0) && (filter <= filterVal * -1)))
    {
      size_t printed = Serial.print(value);
      Serial.print(" ");

      if (printed < 3)
      {
        Serial.println("- No value received! -");
        return false;
      }

      _lastPrint = value;
      return true;
    }
  }

  return false;
}

bool NoSerial::print(int value)
{
  if (_debugMode)
  {
    size_t printed = Serial.print(value);
    Serial.print(" ");

    if (printed < 3)
    {
      Serial.println("- No value received! -");
      return false;
    }

    return true;
  }

  return false;
}

bool NoSerial::autoPrintln(int value, int filterVal)
{
  if (_debugMode)
  {
    int filter = value - _lastPrint;
    if (((filter > 0) && (filter >= filterVal)) || ((filter < 0) && (filter <= filterVal * -1)))
    {
      size_t printed = Serial.println(value);

      if (printed < 3)
      {
        Serial.println("- No value received! -");
        return false;
      }

      _lastPrint = value;
      return true;
    }
  }

  return false;
}

bool NoSerial::println(int value)
{
  if (_debugMode)
  {
    size_t printed = Serial.println(value);

    if (printed < 3)
    {
      Serial.println("- No value received! -");
      return false;
    }

    return true;
  }

  return false;
}