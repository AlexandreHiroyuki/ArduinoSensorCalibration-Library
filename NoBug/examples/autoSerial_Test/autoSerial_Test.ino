#include <NoBug.h>

void myName()
{
    Serial.print("Potenciometro: ");
}

NoSerial MySerial(true, myName);

void setup()
{
    pinMode(A0, INPUT);
    Serial.begin(9600);
}

void loop()
{
    int value = analogRead(A0);
    MySerial.autoPrintln(value, 2);
}
