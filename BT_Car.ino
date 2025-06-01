#include "BluetoothSerial.h"

BluetoothSerial SerialBT;
char receivedChar;

#define Motor_Pin1 23
#define Motor_Pin2 22
#define Motor_Pin3 19
#define Motor_Pin4 18

// Function Prototypes
void Forward();
void Back();
void Left();
void Right();
void Stop();

void setup()
{
    Serial.begin(9600);
    SerialBT.begin("Team 4");

    pinMode(Motor_Pin1, OUTPUT);
    pinMode(Motor_Pin2, OUTPUT);
    pinMode(Motor_Pin3, OUTPUT);
    pinMode(Motor_Pin4, OUTPUT);
}

void loop()
{
    if (SerialBT.available())
    {
        receivedChar = SerialBT.read();
        Serial.print("Received: ");
        Serial.println(receivedChar);

        if (receivedChar == 'F')
        {
            Forward();
        }
        else if (receivedChar == 'B')
        {
            Back();
        }
        else if (receivedChar == 'L')
        {
            Left();
        }
        else if (receivedChar == 'R')
        {
            Right();
        }
        else if (receivedChar == 'S')
        {
            Stop();
        }
    }
    delay(20);
}

// Function Definitions
void Forward()
{
    digitalWrite(Motor_Pin1, HIGH);
    digitalWrite(Motor_Pin2, LOW);
    digitalWrite(Motor_Pin3, HIGH);
    digitalWrite(Motor_Pin4, LOW);
}

void Left()
{
    digitalWrite(Motor_Pin1, LOW);
    digitalWrite(Motor_Pin2, LOW);
    digitalWrite(Motor_Pin3, HIGH);
    digitalWrite(Motor_Pin4, LOW);
}

void Right()
{
    digitalWrite(Motor_Pin1, HIGH);
    digitalWrite(Motor_Pin2, LOW);
    digitalWrite(Motor_Pin3, LOW);
    digitalWrite(Motor_Pin4, LOW);
}

void Back()
{
    digitalWrite(Motor_Pin1, LOW);
    digitalWrite(Motor_Pin2, HIGH);
    digitalWrite(Motor_Pin3, LOW);
    digitalWrite(Motor_Pin4, HIGH);
}

void Stop()
{
    digitalWrite(Motor_Pin1, LOW);
    digitalWrite(Motor_Pin2, LOW);
    digitalWrite(Motor_Pin3, LOW);
    digitalWrite(Motor_Pin4, LOW);
}