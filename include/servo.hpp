#include <Arduino.h>
#include "../lib/servo/servo.hpp"

#define SERVO_PIN 4
#define SERVO_LED_PIN 19

CServo servo;

int state = LOW; // HIGH para chave aberta e LOW para fechada.
                 // Inicialmente a chave se encontra fechada.

void openCircuit()
{
    /*
    Aciona o servo motor para abrir o circuito e acende o LED
    associado a ele.
    */

    servo.toAngle(90);
    digitalWrite(SERVO_LED_PIN, HIGH);
}

void closeCircuit()
{
    /*
    Aciona o servo motor para fechar o circuito e apaga o LED a
    associado a ele.
    */

    servo.toAngle(0);
    digitalWrite(SERVO_LED_PIN, LOW);
}

void swapState()
{
    /*
    Inverte o estado do servo.
    */

    state = !state;

    if (state == HIGH)
    {
        openCircuit();
    }
    else
    {
        closeCircuit();
    }

    Serial.println("O botão foi pressionado");
}
