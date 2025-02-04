# EmbarcaTech_Semaforo
Este projeto consiste na utilização de um temporizador periódico para a simulação de um sistema de semáforo.

## Estrutura do Código
O código está organizado da seguinte maneira:

- `inicializar_pinos()`: Inicializa os pinos a serem utilizados.
- `ligar_vermelho()`: Acende o LED vermelho.
- `ligar_amarelo()`: Acende o LED amarelo.
- `ligar_verde()`: Acende o LED verde.
- `repeating_timer_callback(struct repeating_timer *t)`: Executa a lógica do temporizador no tempo estipulado.
- `add_repeating_timer_ms(3000, repeating_timer_callback, NULL, &timer)`: Configura o temporizador para chamar a função `repeating_timer_callback` no tempo estipulado.

## Desenvolvedor
Guilherme Miller Gama Cardoso
