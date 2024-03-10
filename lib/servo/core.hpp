#pragma once

#include <Servo.h>

class CServo : public Servo
{
public:
    void toAngle(int angle);
};

// namespace srv
// {
//     void initServo(int);
//     int getAngle();
//     void servoToAngle(int *, int);
//     void keyToState(int);
// }
