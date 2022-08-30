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
    
    gpio_init(LED_PIN);
    gpio_set_dir(LED_PIN, GPIO_OUT);
    //PandaStateMachine panda;
    Animator anim(i2c_default, 4, 5);
    anim.startAnimationSequence(testAnimation);

    while(1)
    {
        gpio_put(LED_PIN, 0);
        sleep_ms(250);
        gpio_put(LED_PIN, 1);
        sleep_ms(250);
    }
}