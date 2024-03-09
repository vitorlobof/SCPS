#include <Arduino.h>
#include <Servo.h>

namespace srv
{
    Servo servo;
    int angle = 0;

    void initServo(int pin)
    {
        servo.attach(pin);
        servo.write(angle); // Move para o ângulo inicial.
    }

    int getAngle()
    {
        return angle;
    }

    void servoToAngle(int &currentAngle, int newAngle)
    {
        /*
        Altera o angulo do servo para o valor recebido como
        argumento.
        */

        for (; currentAngle < newAngle; currentAngle++)
        {
            servo.write(currentAngle);
            delay(5);
        }

        for (; currentAngle > newAngle; currentAngle--)
        {
            servo.write(currentAngle);
            delay(5);
        }

        servo.write(currentAngle);
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
