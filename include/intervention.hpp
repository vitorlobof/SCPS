#pragma once

#include <Arduino.h>

#define INTERVENTION_PIN 18
#define INTERVENTION_MODE RISING

void setupIntervention();
void interruptFunction();
