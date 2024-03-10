#include <Arduino.h>
#include "../lib/servo/servo.hpp"
#include "../lib/sensor/sensor.hpp"

#define SERVO_PIN 4
#define BUTTON_PIN 5
#define SENSOR_PIN A0

CServo servo;
Sensor sensor;

int state = LOW; // A chave começa fechada.

float current;             // Vai guardar as leituras de tensão.
float currentLimit = 10.0; // Limite de tensão aceito. Ao ser superado, a chave será aberta.
