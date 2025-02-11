//bibliotecas e constantes usadas
#include <stdio.h>
#include "pico/stdlib.h"
#include <hardware/pwm.h>
#define PIN_MOTOR 22
#define PWM_CLOCK 125
#define WRAP 4000
#define GRAU_0 500
#define GRAU_90 1470
#define GRAU_180 2400

//função para controlar a direção que o motor irá girar
void mov_graus(uint pin, uint duty, uint tempo) {
    pwm_set_gpio_level(pin, duty);
    sleep_ms(tempo);
}

//função para movimentar o motor uma vez que a direção foi definida
void mov_periodica_0_a_180(uint pin) {
    uint16_t duty = GRAU_0;
    int direcao = 5;

    while (1) {
        duty += direcao;
        if (duty >= GRAU_180 || duty <= GRAU_0) {
            direcao = -direcao;
        }
        mov_graus(pin, duty, 10);
    }
}

int main() {
    //inicialização do pico e motor
    stdio_init_all();
    gpio_set_function(PIN_MOTOR, GPIO_FUNC_PWM);
    uint slice = pwm_gpio_to_slice_num(PIN_MOTOR);
    pwm_set_clkdiv(slice, PWM_CLOCK);
    pwm_set_wrap(slice, WRAP);
    pwm_set_enabled(slice, true);

    //movimentação do motor nas direções 0, 90 e 180 graus respectivamente, a cada 5 segundos
    mov_graus(PIN_MOTOR, GRAU_180, 5000);
    mov_graus(PIN_MOTOR, GRAU_90, 5000);
    mov_graus(PIN_MOTOR, GRAU_0, 5000);

    //movimentação do motor de 0 a 180 graus periodicamente
    mov_periodica_0_a_180(PIN_MOTOR);
    
    return 0;
}