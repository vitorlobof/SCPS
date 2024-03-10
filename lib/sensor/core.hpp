#pragma once

class Sensor
{
public:
    Sensor();
    void attach(int pin);                   // Conecta o sensor ao pino que recebe o sinal.
    void detach();                          // Desconecta o sensor do pino.
    bool attached();                        // Determina se o sensor está conectado a um pino ou não.
    float readVoltage(int numberOfSamples); // Lê a tensão usando um dado número de amostras.
    float readCurrent(int numberOfSamples); // Lê a corrente elétrica usando um dado número de amostras.

private:
    int pin;           // Pino que receberá o sinal analógico.
    int sensitivity;   // Sensitividade do sensor utilizado em mV/A.
    int offsetVoltage; // A tensão de offset do ACS712 em mV.
};
