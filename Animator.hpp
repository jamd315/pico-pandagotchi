#ifndef _ANIMATOR_H
#define _ANIMATOR_H
#include <stdint.h>
#include "pico-ssd1306/ssd1306.h"
#include "hardware/i2c.h"

#define IMAGE_DEFAULT 0  // Default is non-inverted, opaque, doesn't clear display
#define IMAGE_INVERT 1 << 1
#define IMAGE_TRANSPARENT 1 << 2
#define IMAGE_CLEARDISPLAY 1 << 3
#define IMAGE_RENDERONLY 1 << 4

// Comment out to reduce log volume by omitting Animator logs
//#define USE_SERIAL_ANIMATOR

typedef struct AnimationElement
{
    uint8_t x;
    uint8_t y;
    uint8_t w;
    uint8_t h;
    uint8_t meta;
    uint16_t delay;
    uint8_t *image;
    const AnimationElement *next;
} AnimationElement;

typedef struct AnimationSequence
{
    uint8_t id;  // Just for debugging
    const AnimationElement *head;
} AnimationSequence;

typedef struct SoundElement
{
    float frequency;
    uint16_t duration;
    uint16_t delay;
    const SoundElement *next;
} SoundElement;

typedef struct SoundSequence
{
    uint8_t id;  // Just for debugging
    const SoundElement *head;
} SoundSequence;


class Animator
{
public:
    Animator(pico_ssd1306::SSD1306 *display);
    void startAnimationSequence(const AnimationSequence &sequence);
    void startSoundSequence(const SoundSequence &sequence);
    void drawActiveAnimationElement();
    void drawToScreen();
    void animationCallback();
    static int64_t staticAnimationCallback(alarm_id_t id, void *user_data);
    uint8_t getAnimationID();


    // Hardcoded animations that need some context
    void cleanAnimation(bool invert=false);

protected:
    pico_ssd1306::SSD1306 *_display;
    const AnimationElement *activeAnimationElement;
    const SoundElement *activeSoundElement;
    uint8_t _speakerPin;
    alarm_id_t animationAlarm = 0;
    uint8_t animationID = 0;
    int16_t accumulatedDrawTimeOffset = 0;  // It takes time to to display, but frames want to be an exact delay apart, this compensates.
    
};

#endif