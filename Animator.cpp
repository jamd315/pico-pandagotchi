#include "hardware/gpio.h"
#include "hardware/i2c.h"
#include "Animator.hpp"
#include "pico-ssd1306/ssd1306.h"
#include "logging.hpp"

#define LOG_SOURCE "Animator"


Animator::Animator(i2c_inst_t *i2c_port, uint8_t sda_pin, uint8_t scl_pin)
: display(pico_ssd1306::SSD1306(i2c_port, 0x3C, pico_ssd1306::Size::W128xH64))
{
    i2c_init(i2c_port, 3200000);  // Usually 100kHz, 400kHz, 1MHz, 3.2MHz
    gpio_set_function(sda_pin, GPIO_FUNC_I2C);
    gpio_set_function(scl_pin, GPIO_FUNC_I2C);
    gpio_pull_up(sda_pin);
    gpio_pull_up(scl_pin);
    display.setOrientation(false);
    pretty_log(LOG_VERBOSE, LOG_SOURCE, "Animator created");
}

void Animator::startAnimationSequence(const AnimationSequence &sequence)
{
    pretty_log(LOG_INFO, LOG_SOURCE, "Started animation id %d", sequence.id);
    activeAnimationElement = sequence.head;
}

void Animator::drawActiveAnimationElement()
{
    display.addBitmapImage(
        activeAnimationElement->x,
        activeAnimationElement->y,
        activeAnimationElement->w,
        activeAnimationElement->h,
        activeAnimationElement->image
    );
}

