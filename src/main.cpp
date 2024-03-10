#include "main.h"

void setup()
{
  Serial.begin(9600); // Comunicação serial.

  sensor.attach(SENSOR_PIN);

  servo.attach(SERVO_PIN);
  servo.write(0); // O servo começa com ângulo 0.

  pinMode(BUTTON_PIN, INPUT);
}

void loop()
{
  current = sensor.readCurrent(10);

  if (abs(current) > currentLimit)
  {
    state = HIGH;
    servo.toAngle(90);

    Serial.print("Sobrecorrente: ");
    Serial.print(abs(current));
    Serial.println(" A\n");
  }

  if (digitalRead(BUTTON_PIN) == HIGH)
  {
    state = !state;

    if (state == HIGH)
    {
      servo.toAngle(90);
    }
    else
    {
      servo.toAngle(0);
    }

    Serial.println("O botão foi precionado\n");
  }
}
