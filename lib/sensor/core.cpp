#include <Arduino.h>
#include "core.hpp"

Sensor::Sensor() : pin(-1), sensitivity(185.0f), offsetVoltage(4000.0f) {}

void Sensor::attach(int pin)
{
    this->pin = pin;
}

void Sensor::detach()
{
    this->pin = -1;
}

bool Sensor::attached()
{
    return !(this->pin == -1);
}

float Sensor::readVoltage(int numberOfSamples)
{
    /*
    Recebe o número de amostras que devem ser coletadas e
    retorna a tensão lida em mV.
    */

    float samplesSum = 0.0;
    float samplesAverage, voltage;

    for (int i = 0; i < numberOfSamples; i++)
    {
        samplesSum += analogRead(this->pin);
        delay(5);
    }

    samplesAverage = samplesSum / numberOfSamples;
    voltage = samplesAverage * (5000.0f / 1024.0f);

    return voltage;
}

float Sensor::readCurrent(int numberOfSamples)
{
    /*
    Recebe o número de amostras que devem ser coletadas e
    retorna a corrente elétrica lida em A.
    */

    float current, voltage;

    voltage = readVoltage(numberOfSamples);
    current = (voltage - this->offsetVoltage) / this->sensitivity;

    return current;
}
