#include "../lib/sensor/sensor.hpp"

#define SENSOR_PIN A0

Sensor sensor;
float currentLimit = 10.0; // Limite de corrente aceito. Ao ser superado, a chave será aberta.
float current;             // Vai guardar as leituras de corrente.
