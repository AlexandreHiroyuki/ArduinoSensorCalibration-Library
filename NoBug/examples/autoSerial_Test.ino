#include <NoBug.h>

void setup()
{
    NoSerial MySerial(9600);
}

void loop()
{
    MySerial.autoPrint(analogRead(A0));
}