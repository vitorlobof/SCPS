#include "intervention.hpp"

void setupIntervention(void (*interruptFunction)(void))
{
    pinMode(INTERVENTION_PIN, INPUT);

    attachInterrupt(
      digitalPinToInterrupt(INTERVENTION_PIN),
      interruptFunction,
      INTERVENTION_MODE);
}
