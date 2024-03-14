#include "main.h"

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

  Serial.print(abs(current));
  Serial.print(" mA");

  if (!state && abs(current) > CURRENT_LIMIT)
  {
    state = HIGH;
    openCircuit(servo);

    Serial.println(" (Sobrecorrente)");
  }
  else
  {
    Serial.println("");
  }
}

void interruptFunction()
{
  /*
  Inverte o estado do servo.
  */

  swapState(servo, state);

  Serial.println("O botao foi pressionado");
}
