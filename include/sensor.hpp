#pragma once

#include <Arduino.h>
#include "../lib/sensor/sensor.hpp"

#define SENSOR_PIN A0
#define CURRENT_LIMIT 100.0 // Limite de corrente em mA. Ao ser superado, a chave será aberta.

void setupSensor(Sensor &sensor);
