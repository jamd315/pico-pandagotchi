#include "hardware/gpio.h"
#include "hardware/i2c.h"
#include "Animator.hpp"
#include "pico-ssd1306/ssd1306.h"
#include "logging.hpp"

#define LOG_SOURCE "Animator"


Animator::Animator(pico_ssd1306::SSD1306 *display)
    : _display(display)
{
    _display->setOrientation(false);
    pretty_log(LOG_VERBOSE, LOG_SOURCE, "Animator created");
}

void Animator::startAnimationSequence(const AnimationSequence &sequence)
{
    pretty_log(LOG_INFO, LOG_SOURCE, "Started animation id %d", sequence.id);
    activeAnimationElement = sequence.head;
}

void Animator::drawActiveAnimationElement()
{
    _display->addBitmapImage(
        activeAnimationElement->x,
        activeAnimationElement->y,
        activeAnimationElement->w,
        activeAnimationElement->h,
        activeAnimationElement->image
    );
}

void Animator::draw()
{
    _display->sendBuffer();
}
