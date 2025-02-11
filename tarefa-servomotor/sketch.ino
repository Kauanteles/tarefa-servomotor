#include "pico/stdlib.h"
#include "hardware/pwm.h"

#define SERVO_PIN 22
#define LED_RGB 12
#define FREQ_PWM 50 // Frequência do PWM em Hz
#define PERIODO_US 20000 // Período do PWM em microssegundos

void configurar_pwm(uint pin) {
    gpio_set_function(pin, GPIO_FUNC_PWM);
    uint slice = pwm_gpio_to_slice_num(pin);
    pwm_set_wrap(slice, 12500); // 12500 = 20ms / (1/2500000s) (contando com clock base de 2.5MHz)
    pwm_set_enabled(slice, true);
}

void definir_angulo_servo(uint pin, uint ciclo_us) {
    uint slice = pwm_gpio_to_slice_num(pin);
    pwm_set_gpio_level(pin, (ciclo_us * 12500) / PERIODO_US);
}

int main() {
    stdio_init_all();
    configurar_pwm(SERVO_PIN);
    gpio_init(LED_RGB);
    gpio_set_dir(LED_RGB, GPIO_OUT);

    while (1) {
        // 180 graus
        definir_angulo_servo(SERVO_PIN, 2400);
        sleep_ms(5000);

        // 90 graus
        definir_angulo_servo(SERVO_PIN, 1470);
        sleep_ms(5000);

        // 0 graus
        definir_angulo_servo(SERVO_PIN, 500);
        sleep_ms(5000);

        // Movimentação suave entre 0 e 180 graus
        for (uint ciclo = 500; ciclo <= 2400; ciclo += 5) {
            definir_angulo_servo(SERVO_PIN, ciclo);
            sleep_ms(10);
        }
        for (uint ciclo = 2400; ciclo >= 500; ciclo -= 5) {
            definir_angulo_servo(SERVO_PIN, ciclo);
            sleep_ms(10);
        }
    }
}
