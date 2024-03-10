#include "../lib/sensor/sensor.hpp"

#define SENSOR_PIN A0

Sensor sensor;
float currentLimit = 100.0; // Limite de corrente em mA. Ao ser superado, a chave será aberta.
float current;              // Vai guardar as leituras de corrente.
