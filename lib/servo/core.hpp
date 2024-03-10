#pragma once

#include <Servo.h>

class CServo : public Servo
{
public:
    void toAngle(int angle);
};
