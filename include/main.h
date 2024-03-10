#include <Arduino.h>
#include "../lib/servo/servo.hpp"
#include "../lib/sensor/sensor.hpp"

#define SERVO_PIN 4
#define SENSOR_PIN A0
#define BUTTON_PIN 21

CServo servo;
Sensor sensor;

int state = LOW; // A chave começa fechada.

float currentLimit = 10.0; // Limite de corrente aceito. Ao ser superado, a chave será aberta.
float current;             // Vai guardar as leituras de corrente.

void swapState()
{
    state = !state;

    if (state == HIGH)
    {
        servo.toAngle(90); // Abre a chave.
    }
    else
    {
        servo.toAngle(0); // Fecha a chave.
    }

    Serial.println("O botão foi pressionado");
}
