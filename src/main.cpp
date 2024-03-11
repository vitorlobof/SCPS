#include "main.h"

void setup()
{
  Serial.begin(9600); // Comunicação serial.

  sensor.attach(SENSOR_PIN);

  servo.attach(SERVO_PIN);
  servo.write(0); // O servo começa com ângulo 0. Ou seja, chave fechada.

  pinMode(SERVO_LED_PIN, OUTPUT);
  digitalWrite(SERVO_LED_PIN, LOW); // LED começa desligado.

  pinMode(BUTTON_PIN, INPUT);
  attachInterrupt(
      digitalPinToInterrupt(BUTTON_PIN),
      swapState, // Inverte o estado do servo.
      RISING);
}

void loop()
{
  current = sensor.readCurrent(10);

  Serial.print(abs(current));
  Serial.println(" mA");

  if (abs(current) > currentLimit)
  {
    state = HIGH;
    openCircuit();

    Serial.println("(Sobrecorrente)");
  } else {
    Serial.println("");
  }
}
