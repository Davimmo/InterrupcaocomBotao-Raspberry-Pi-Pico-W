# Projeto Controle de LEDs - EmbarcaTech

## Sobre o Projeto
Este projeto implementa um sistema de controle de LEDs utilizando a Raspberry Pi Pico. Os LEDs são acionados com base no pressionamento de um botão e desligam de forma programada em diferentes ciclos de tempo. Foi desenvolvido no âmbito do **EmbarcaTech** por **Davi Bezerra Cavalcanti**.

## Requisitos
Para compilar e executar este projeto, são necessárias as seguintes ferramentas:

## Extensões para o VS Code
- **Wokwi**
- **CMake**
- **Raspberry Pi Pico Project**

O código está organizado da seguinte forma:

- **Definições de Pinos:**
  - `BLUE`: Pino do LED azul.
  - `RED`: Pino do LED vermelho.
  - `GREEN`: Pino do LED verde.
  - `BUTTON_PIN`: Pino do botão.
- **Variáveis Globais:**
  - `is_running`: Controla o estado de execução do sistema.
- **Funções:**
  - `desligar_verde()`, `desligar_azul()`, `desligar_vermelho()`: Funções de callback que desligam os LEDs após tempos programados.
  - `init_led()`: Inicializa os pinos dos LEDs.
  - `init_button()`: Configura o pino do botão.
  - `desligar_leds()`: Agenda o desligamento dos LEDs em ciclos específicos.
- **Função `main()`:**
  - Inicializa os LEDs e o botão.
  - Monitora o pressionamento do botão.
  - Ativa os LEDs e agenda o desligamento programado.

## Como Compilar e Executar
1. Certifique-se de ter o ambiente de desenvolvimento do Raspberry Pi Pico configurado.
2. Clone este repositório:
   https://github.com/Davimmo/InterrupcaocomBotao-Raspberry-Pi-Pico-W.git

3. Importe o projeto utilizando as pastas BitDogLab ou Simulacao

4. Compile o projeto utilizando a extensão para Raspberry Pi Pico

5. Transfira o binário gerado para a Raspberry Pi Pico e realize seus testes.


---
**Nota:** Este projeto faz parte do programa EmbarcaTech e foi desenvolvido para fins educacionais e experimentação com a Raspberry Pi Pico.

