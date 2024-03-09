#include <Arduino.h>

namespace sensor
{
    int sensorPin;
    int sensitivity = 185.0f;   // Sensitividade do sensor utilizado em mV/A.
    int offsetVoltage = 4000.0f; // A tensão de offset do ACS712 em mV.

    void initSensor(int pin)
    {
        sensorPin = pin;
    }

    float readCurrent(int numberOfSamples)
    {
        /*
        Determina a corrente em A.
        */

        float currentValue = 0.0, samplesSum = 0.0;
        float samplesAverage;
        float voltage;
        float current;

        for (int i = 0; i < numberOfSamples; i++)
        {
            currentValue = analogRead(sensorPin); // Lê o valor atual coletado pelo sensor.
            samplesSum += currentValue;           // Adiciona o valor lido a soma das amostras.
            delay(10);                            // Deixa o ADC termine suas operações antes de coletar a próxima amostra.
        }

        samplesAverage = samplesSum / numberOfSamples;     // Determina a média das amostras.
        voltage = samplesAverage * (5000.0f / 1024.0f);    // Converte a tensão lida para mV.
        current = (voltage - offsetVoltage) / sensitivity; // Determina a corrente que passa pelo circuito em A.

        return current;
    }
}
