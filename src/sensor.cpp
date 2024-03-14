#include "sensor.hpp"

void setupSensor(Sensor &sensor)
{
    sensor.attach(SENSOR_PIN);
}