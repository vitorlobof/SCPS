#pragma once

#include <Arduino.h>
#include "../lib/servo/servo.hpp"

#define SERVO_PIN 4
#define SERVO_LED_PIN 19

#define CLOSE_CIRCUIT_ANGLE 120
#define OPEN_CIRCUIT_ANGLE (CLOSE_CIRCUIT_ANGLE - 90)

void setupServo(CServo &servo);
void openCircuit(CServo &servo);
void closeCircuit(CServo &servo);
void swapState(CServo &servo, bool &state);
