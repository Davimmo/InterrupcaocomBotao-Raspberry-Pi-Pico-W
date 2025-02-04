#include <stdio.h> // Biblioteca padrão do C.
#include "pico/stdlib.h" // Biblioteca padrão do Raspberry Pi Pico para controle de GPIO, temporização e comunicação serial.
#include "pico/time.h"   // Biblioteca para gerenciamento de temporizadores e alarmes.

const uint GREEN = 11;    
const uint BLUE = 12;    
const uint RED = 13;    
const uint BUTTON_PIN = 5;  // Define o pino GPIO 5 para ler o estado do botão.
bool executando=false;

// Função de callback para desligar o LED verde após o tempo programado.
int64_t desligar_verde(alarm_id_t id, void *user_data) {
    gpio_put(GREEN, false);
    return 0;
}

// Função de callback para desligar o LED azul após o tempo programado.
int64_t desligar_azul(alarm_id_t id, void *user_data) {
    gpio_put(BLUE, false);
    return 0;
}

// Função de callback para desligar o LED vermelho após o tempo programado.
int64_t desligar_vermelho(alarm_id_t id, void *user_data) {
    gpio_put(RED, false);
    executando=false;
    return 0;
}

void desligar_leds(){
    add_alarm_in_ms(3000, desligar_verde, NULL, false);
    add_alarm_in_ms(6000, desligar_azul, NULL, false);
    add_alarm_in_ms(9000, desligar_vermelho, NULL, false);   
}

gpio_irq_handler(uint gpio, uint32_t events);


int main() {
    stdio_init_all();

    // Configura os pinos dos LEDs como saída.
    gpio_init(RED);
    gpio_init(BLUE);
    gpio_init(GREEN);
    gpio_set_dir(RED, GPIO_OUT);
    gpio_set_dir(BLUE, GPIO_OUT);
    gpio_set_dir(GREEN, GPIO_OUT);

    // Configura o pino do botão como entrada e ativa o pull-up.
    gpio_init(BUTTON_PIN);
    gpio_set_dir(BUTTON_PIN, GPIO_IN);
    gpio_pull_up(BUTTON_PIN);

    while (true) {
        // Verifica se o botão foi pressionado.
        if (gpio_get(BUTTON_PIN) == 0 && !executando) {
            sleep_ms(50); // Debounce

            // Verifica novamente o estado do botão após o debounce.
            if (gpio_get(BUTTON_PIN) == 0 && !executando) {
                executando = true;
                // Acende os LEDs.
                gpio_put(RED, true);
                gpio_put(GREEN, true);
                gpio_put(BLUE, true);

                // Agenda o desligamento dos LEDs após o tempo especificado.
                desligar_leds();


            }
        }

        sleep_ms(10); // Reduz o uso da CPU.
    }

    return 0; // Este código nunca será alcançado.
}