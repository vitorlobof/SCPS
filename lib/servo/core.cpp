#include <Arduino.h>
#include "core.hpp"

void CServo::toAngle(int angle)
{
    int currentAngle = this->read();

    for (; currentAngle < angle; currentAngle++)
    {
        this->write(currentAngle);
        delay(5);
    }

    for (; currentAngle > angle; currentAngle--)
    {
        this->write(currentAngle);
        delay(5);
    }

    this->write(angle);
}
