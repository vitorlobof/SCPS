#include "servo.hpp"

void setupServo(CServo &servo)
{
    servo.attach(SERVO_PIN);
    closeCircuit(servo); // A chave começa fechada.

    pinMode(SERVO_LED_PIN, OUTPUT);
    digitalWrite(SERVO_LED_PIN, LOW); // LED começa desligado.
}

void openCircuit(CServo &servo)
{
    /*
    Aciona o servo motor para abrir o circuito e acende o LED
    associado a ele.
    */

    servo.toAngle(OPEN_CIRCUIT_ANGLE);
    digitalWrite(SERVO_LED_PIN, HIGH);
}

void closeCircuit(CServo &servo)
{
    /*
    Aciona o servo motor para fechar o circuito e apaga o LED a
    associado a ele.
    */

    servo.toAngle(CLOSE_CIRCUIT_ANGLE);
    digitalWrite(SERVO_LED_PIN, LOW);
}

void swapState(CServo &servo, bool &state)
{
    /*
    Inverte o estado do servo.
    */

    state = !state;

    if (state == HIGH)
    {
        openCircuit(servo);
    }
    else
    {
        closeCircuit(servo);
    }
}
