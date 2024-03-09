#ifndef SERVO_HPP
#define SERVO_HPP

#include <Servo.h>
#include "delay.hpp"

namespace srv
{
    Servo servo;
    int servoPin = 4;
    int angle = 0;
    int state = LOW;

    void initServo()
    {
        servo.attach(servoPin);
        servo.write(angle);
    }

    void servoToAngle(int &currentAngle, int newAngle)
    {
        /*
        Altera o angulo do servo para o valor recebido como
        argumento.
        */
        for (; currentAngle < newAngle; currentAngle++)
        {
            srv::servo.write(currentAngle);
            dly::millisDelay(5);
        }

        for (; currentAngle > newAngle; currentAngle--)
        {
            srv::servo.write(currentAngle);
            dly::millisDelay(5);
        }
    }

    void keyToState(int state)
    {
        /*
        Recebe o estado que o servo deve apresentar. Se for HIGH,
        a chave será aberta, se for LOW a chave será fechada.
        */

        if (state == HIGH)
        {
            servoToAngle(angle, 90); // Abre a chave.
        }
        else
        {
            servoToAngle(angle, 0); // Fecha a chave.
        }
    }
}

#endif