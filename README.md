# Projeto SCPS - Sistema de Proteção de Rede Elétrica com Arduino

O Projeto SCPS é um sistema de proteção de rede elétrica desenvolvido com o Arduino utilizando o sensor de corrente não invasivo ACS712 e um servo motor. O objetivo do sistema é simular um dispositivo de proteção capaz de desligar automaticamente uma carga elétrica em caso de sobrecorrente.

## Funcionamento

O sistema funciona da seguinte maneira:

1. **Leitura de Corrente:**
   O sensor de corrente ACS712 é utilizado para medir a corrente elétrica que passa pela carga. Ele é não invasivo, o que significa que não é necessário interromper o circuito para realizar a medição.

2. **Monitoramento da Corrente:**
   O Arduino lê continuamente os valores de corrente fornecidos pelo sensor ACS712.

3. **Detecção de Sobrecorrente:**
   O sistema monitora os valores de corrente e ativa um mecanismo de proteção caso a corrente medida ultrapasse um determinado limite pré-definido.

4. **Atuação do Servo Motor:**
   Quando a sobrecorrente é detectada, o Arduino aciona um servo motor para desligamento da carga elétrica.

## Componentes Utilizados

- Arduino Mega 2560.
- Sensor de Corrente Não Invasivo ACS712.
- Servo Motor: Utilizado para abrir e fechar o circuito, atuando como a proteção.
- Resistores e Componentes Eletrônicos Diversos.
