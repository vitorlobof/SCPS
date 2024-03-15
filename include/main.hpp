#pragma once

#include "servo.hpp"
#include "sensor.hpp"
#include "intervention.hpp"

Sensor sensor;
float current;

CServo servo;
bool state = LOW; // HIGH para chave aberta e LOW para fechada.
                  // Inicialmente a chave se encontra fechada.
