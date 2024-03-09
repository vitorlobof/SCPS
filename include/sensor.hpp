#ifndef CURRENTSENSOR_HPP
#define CURRENTSENSOR_HPP

#include <Arduino.h>
#include "delay.hpp"

namespace sensor
{
    float readCurrent(int numberOfSamples = 10)
    {
        /*
        Determina a voltagem do sistema.
        */

        float currentValue = 0.0, samplesSum = 0.0;
        float samplesAverage;
        float voltage;

        for (int i = 0; i < numberOfSamples; i++)
        {
            currentValue = analogRead(A0); // Lê o valor atual coletado pelo sensor.
            samplesSum += currentValue;    // Adiciona o valor lido a soma das amostras.
            dly::millisDelay(3);           // Deixa o ADC termine suas operações antes de coletar a próxima amostra.
        }

        samplesAverage = samplesSum / numberOfSamples; // Determina a média das amostras.
        voltage = samplesAverage * (5.0 / 1024.0);     //((samplesAverage * (5.0 / 1024.0)) converte a tensão lida para 0-5 volts.
        return voltage;
    }
}

#endif