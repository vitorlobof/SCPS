#include <Arduino.h>
#include "../lib/servo/servo.hpp"
#include "../lib/sensor/sensor.hpp"

#define SERVO_PIN 4
#define SENSOR_PIN A0
#define BUTTON_PIN 5

CServo servo;
Sensor sensor;

int state = LOW; // A chave começa fechada.

float currentLimit = 10.0; // Limite de corrente aceito. Ao ser superado, a chave será aberta.
float current;             // Vai guardar as leituras de corrente.
