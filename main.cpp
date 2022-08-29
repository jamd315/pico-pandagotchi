#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/gpio.h"
#include "pico/binary_info.h"
#include "PandaStateMachine.hpp"
#include "Animator.hpp"
#include "logging.hpp"

const uint LED_PIN = 25;

int main()
{
    stdio_init_all();
    
    gpio_init(LED_PIN);
    gpio_set_dir(LED_PIN, GPIO_OUT);
    //PandaStateMachine panda;
    //Animator anim;
    //anim.startAnimationSequence(testAnimation);
    pretty_log(LOG_VERBOSE, "Main", "Hello World!");
    pretty_log(LOG_INFO, "Main", "Hello World!");
    pretty_log(LOG_WARNING, "Main", "Hello World!");
    pretty_log(LOG_ERROR, "Main", "Hello World!");
    pretty_log(LOG_CRITICAL, "Main", "Hello World!");

    while(1)
    {
        gpio_put(LED_PIN, 0);
        sleep_ms(250);
        gpio_put(LED_PIN, 1);
        sleep_ms(250);
    }
}