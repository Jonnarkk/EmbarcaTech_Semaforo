#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/timer.h"

// Defines dos pinos
#define red_pin 11
#define yellow_pin 12
#define green_pin 13

// Variáveis globais
uint8_t contador = 0;

// Inicializa pinos utilizados
void inicializar_pinos(){
    gpio_init(red_pin);
    gpio_set_dir(red_pin, GPIO_OUT);
    gpio_init(yellow_pin);
    gpio_set_dir(yellow_pin, GPIO_OUT);
    gpio_init(green_pin);
    gpio_set_dir(green_pin, GPIO_OUT);
}

// Liga LED vermelho
void ligar_vermelho(){
    gpio_put(red_pin, 1);
    gpio_put(yellow_pin, 0);
    gpio_put(green_pin, 0);
}

// Liga LED amarelo
void ligar_amarelo(){
    gpio_put(red_pin, 0);
    gpio_put(yellow_pin, 1);
    gpio_put(green_pin, 0);
}

// Liga LED verde
void ligar_verde(){
    gpio_put(red_pin, 0);
    gpio_put(yellow_pin, 0);
    gpio_put(green_pin, 1);
}

// Função para executar lógica quando temporizador é chamado
bool repeating_timer_callback(struct repeating_timer *t){

    switch (contador){
    case 0:
        ligar_vermelho();
        break;
    case 1: 
        ligar_amarelo();
        break;
    case 2:
        ligar_verde();
        break;
    }

    contador++;

    if(contador > 2)
        contador = 0;

    return true;
}

int main(){
    struct repeating_timer timer; // Estrutura para armazenar informações do temporizador

    stdio_init_all();
    inicializar_pinos();

    add_repeating_timer_ms(3000, repeating_timer_callback, NULL, &timer); // Função que configura tempo do temporizador e chama função repeating_timer_callback

    while (true) {
        printf("Funcao principal rodando\n"); // Mensagem da rotina principal
        sleep_ms(1000);
    }
}
