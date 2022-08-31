#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/gpio.h"
#include "pico/binary_info.h"
#include "PandaStateMachine.hpp"
#include "Animator.hpp"
#include "logging.hpp"
#include "sequences.hpp"

const uint LED_PIN = 25;

int main()
{
    stdio_init_all();
    pretty_log(LOG_INFO, "Main", "--- STDIO initialized ---");

    gpio_init(LED_PIN);
    gpio_set_dir(LED_PIN, GPIO_OUT);
    //PandaStateMachine panda;

    // Init the I2C
    i2c_init(i2c0, 3200000);  // Usually 100kHz (standard), 400kHz (full speed), 1MHz (fast mode), 3.2MHz (high speed)
    gpio_set_function(4, GPIO_FUNC_I2C);
    gpio_set_function(5, GPIO_FUNC_I2C);
    gpio_pull_up(4);
    gpio_pull_up(5);
    pico_ssd1306::SSD1306 display = pico_ssd1306::SSD1306(i2c0, 0x3C, pico_ssd1306::Size::W128xH64);
    Animator anim = Animator(&display);
    anim.startAnimationSequence(testAnimation);
    anim.drawActiveAnimationElement();
    anim.draw();

    while(1)
    {
        gpio_put(LED_PIN, 0);
        sleep_ms(250);
        gpio_put(LED_PIN, 1);
        sleep_ms(250);
    }
}