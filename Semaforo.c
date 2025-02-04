#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/timer.h"

#define red_pin 11
#define blue_pin 12
#define green_pin 13

uint8_t contador = 0;


void inicializar_pinos(){
    gpio_init(red_pin);
    gpio_set_dir(red_pin, GPIO_OUT);
    gpio_init(blue_pin);
    gpio_set_dir(blue_pin, GPIO_OUT);
    gpio_init(green_pin);
    gpio_set_dir(green_pin, GPIO_OUT);
}

void ligar_vermelho(){
    gpio_put(red_pin, 1);
    gpio_put(blue_pin, 0);
    gpio_put(green_pin, 0);
}

void ligar_amarelo(){
    gpio_put(red_pin, 1);
    gpio_put(blue_pin, 0);
    gpio_put(green_pin, 1);
}

void ligar_verde(){
    gpio_put(red_pin, 0);
    gpio_put(blue_pin, 0);
    gpio_put(green_pin, 1);
}

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
    struct repeating_timer timer;

    stdio_init_all();
    inicializar_pinos();

    add_repeating_timer_ms(3000, repeating_timer_callback, NULL, &timer);

    while (true) {
        printf("Funcao principal rodando\n");
        sleep_ms(1000);
    }
}
