#include "main.h"

void setup()
{
  Serial.begin(9600); // Comunicação serial.

  sensor.attach(SENSOR_PIN);

  servo.attach(SERVO_PIN);
  servo.write(0); // O servo começa com ângulo 0. Ou seja, chave fechada.

  pinMode(BUTTON_PIN, INPUT);
  attachInterrupt(
      digitalPinToInterrupt(BUTTON_PIN),
      swapState,
      CHANGE);
}

void loop()
{
  current = sensor.readCurrent(10);

  if (abs(current) > currentLimit)
  {
    state = HIGH;
    servo.toAngle(90); // Abre a chave.

    Serial.print("Sobrecorrente: ");
    Serial.print(abs(current));
    Serial.println(" A");
  }
}
