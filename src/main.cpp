#include "main.hpp"

void setup()
{
  Serial.begin(9600); // Comunicação serial.

  setupSensor(sensor);
  setupServo(servo);
  setupIntervention();

  attachInterrupt(
      digitalPinToInterrupt(INTERVENTION_PIN),
      interruptFunction,
      INTERVENTION_MODE);
}

void loop()
{
  current = sensor.readCurrent(10);

  if (!state && abs(current) > CURRENT_LIMIT)
  {
    state = HIGH;
    openCircuit(servo);

    Serial.print("Sobrecorrente detectada: ");
    Serial.print(abs(current));
    Serial.println(" mA");
  }
}

void interruptFunction()
{
  /*
  Inverte o estado do servo.
  */

  swapState(servo, state);
  delay(10);

  Serial.println("Intervencao realizada.");
}
