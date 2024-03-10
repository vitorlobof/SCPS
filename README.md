# Projeto SCPS - Sistema de Proteção de Rede Elétrica com Arduino

O Projeto SCPS é um sistema de proteção de rede elétrica desenvolvido com o Arduino utilizando o sensor de corrente não invasivo ACS712 e um servo motor. O objetivo do sistema é simular um dispositivo de proteção capaz de desligar automaticamente uma carga elétrica em caso de sobrecorrente.

## Funcionamento

O sistema funciona da seguinte maneira:

1. **Leitura de Corrente:**
   O sensor de corrente ACS712 é utilizado para medir a corrente elétrica que passa pela carga. Ele é não invasivo, o que significa que não é necessário interromper o circuito para realizar a medição. Isso permite que os valores sejam lidos contínuamente.

2. **Atuação do Servo Motor:**
   Quando a sobrecorrente é detectada, o Arduino aciona um servo motor para desligamento da carga elétrica.

3. **Proteção contra sobrecorrente:**
   A leitura dos valores de corrente detecta uma sobrecorrente e ativa o servo motor para abrir o circuito.

## Componentes Utilizados

- 1 Arduino Mega 2560.
- 1 Sensor de Corrente Não Invasivo ACS712.
- 1 Micro Servo MG90S.
- Vários resistores.
- 2 botões.
- 1 LED.
