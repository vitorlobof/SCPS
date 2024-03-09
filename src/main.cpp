#include <Arduino.h>
#include "../lib/servo/servo.hpp"
#include "../lib/sensor/sensor.hpp"

#define SERVO_PIN 4
#define BUTTON_PIN 5
#define SENSOR_PIN A0

int state = LOW; // A chave começa fechada.

float current;            // Vai guardar as leituras de tensão.
float currentLimit = 10.0; // Limite de tensão aceito. Ao ser superado, a chave será aberta.

void setup()
{
  Serial.begin(9600); // Comunicação serial.

  srv::initServo(SERVO_PIN);
  sensor::initSensor(SENSOR_PIN);
  pinMode(BUTTON_PIN, INPUT);
}

void loop()
{
  current = sensor::readCurrent(10);

  Serial.print("Valor de corrente:");
  Serial.print(current);
  Serial.println(" A\n");

  if (abs(current) > currentLimit)
  {
    state = HIGH;
    srv::keyToState(state);
  }

  if (digitalRead(BUTTON_PIN) == HIGH)
  {
    state = !state;
    srv::keyToState(state);
    Serial.println("O botão foi precionado\n");
  }
}
