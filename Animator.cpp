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
    if (animationAlarm != 0 || animationID != 0)  // Really both should be either zero OR nonzero at any time
    {
        pretty_log(LOG_WARNING, LOG_SOURCE, "Prematurely stopping alarm %ld animationID %u", animationAlarm, animationID);
    }
    pretty_log(LOG_INFO, LOG_SOURCE, "Started animation id %d", sequence.id);
    activeAnimationElement = sequence.head;
    animationCallback();
}

void Animator::drawActiveAnimationElement()
{
    if (activeAnimationElement->meta & IMAGE_CLEARDISPLAY)
    {
        _display->clear();
    }
    _display->addBitmapImage(
        activeAnimationElement->x,
        activeAnimationElement->y,
        activeAnimationElement->w,
        activeAnimationElement->h,
        activeAnimationElement->image
    );
    if (!(activeAnimationElement->meta & IMAGE_RENDERONLY))  // By default we drawToScreen, unless IMAGE_RENDERONLY is set
    {
        drawToScreen();
    }
}

void Animator::drawToScreen()
{
    _display->sendBuffer();
}

void Animator::animationCallback()
{
    absolute_time_t t1 = get_absolute_time();
    animationAlarm = 0;
    animationID = 0;
    activeAnimationElement = activeAnimationElement->next;
    if (activeAnimationElement == nullptr)
    {
        pretty_log(LOG_VERBOSE, "Animator Callback", "Animation Sequence finished");
        return;
    }
    drawActiveAnimationElement();
    absolute_time_t t2 = get_absolute_time();
    // We technically allow as much as 500us of error per frame with this divide, or 0.1s after 200 frames
    accumulatedDrawTimeOffset += absolute_time_diff_us(t1, t2) / 1000;
    int newDelay = activeAnimationElement->delay - accumulatedDrawTimeOffset;
    pretty_log(LOG_VERBOSE, LOG_SOURCE, "New callback in %dms", newDelay);
    
    if (newDelay <= 0)
    {
        accumulatedDrawTimeOffset -= activeAnimationElement->delay;
        pretty_log(LOG_VERBOSE, LOG_SOURCE, "Negative or zero delay, instantly triggered next animationCallback()");
        animationCallback();
    }
    else
    {
        accumulatedDrawTimeOffset = 0;
        add_alarm_in_ms(newDelay, staticAnimationCallback, this, false);
        pretty_log(LOG_VERBOSE, LOG_SOURCE, "Callback triggered in %dms", newDelay);

    }
}

int64_t Animator::staticAnimationCallback(alarm_id_t id, void *user_data)
{
    Animator *caller = (Animator *)user_data;
    caller->animationCallback();
    return 0;
}

uint8_t Animator::getAnimationID()
{
    return animationID;
}