#ifndef DELAY_HPP
#define DELAY_HPP

#include <Arduino.h>

namespace dly
{
    void millisDelay(float milliseconds)
    {
        /*
        Gera um delay passível a interrupções.
        */
        unsigned long startMillis = millis(), currentMillis;

        do
        {
            currentMillis = millis();
        } while (currentMillis - startMillis < milliseconds);
    }
}

#endif