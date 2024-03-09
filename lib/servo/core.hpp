#pragma once

namespace srv
{
    void initServo(int);
    int getAngle();
    void servoToAngle(int *, int);
    void keyToState(int);
}
