#pragma once

#include <Arduino.h>
#include "servo.hpp"

#define INTERVENTION_PIN 18
#define INTERVENTION_MODE RISING

void setupIntervention(void (*interruptFunction)(void));
