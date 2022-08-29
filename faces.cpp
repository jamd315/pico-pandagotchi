// Autogenerated.  Takes 546 bytes of flash.
// NOTE these are declared backwards for linked list purposes

#include <avr/pgmspace.h>
#include "faces.h"
#include "Animator.h"
#include "images.hpp"
#include "globals.hpp"  // Face size declarations

#pragma region eatFace_1
static const AnimationElement _eatFace_1_hand_id140636590484512 = 
{
 .x = FACE_LEFT + 36,
 .y = 45,
 .w = 16,
 .h = 12,
 .meta = IMAGE_TRANSPARENT,
 .delay = 0,
 .image = eat_animation_hand,
 .next = nullptr
};

static const AnimationElement _eatFace_1_mouth_id140636590484992 = 
{
 .x = MOUTH_LEFT,
 .y = MOUTH_TOP,
 .w = MOUTH_WIDTH,
 .h = MOUTH_HEIGHT,
 .meta = IMAGE_TRANSPARENT,
 .delay = 0,
 .image = hungry_mouth,
 .next = &_eatFace_1_hand_id140636590484512
};

static const AnimationElement _eatFace_1_right_eye_id140636590484320 = 
{
 .x = LEFT_EYE_LEFT,
 .y = LEFT_EYE_TOP,
 .w = EYE_WIDTH,
 .h = EYE_HEIGHT,
 .meta = IMAGE_TRANSPARENT,
 .delay = 0,
 .image = eat_animation_eye_right,
 .next = &_eatFace_1_mouth_id140636590484992
};

static const AnimationElement _eatFace_1_left_eye_id140636590484800 = 
{
 .x = LEFT_EYE_LEFT,
 .y = LEFT_EYE_TOP,
 .w = EYE_WIDTH,
 .h = EYE_HEIGHT,
 .meta = IMAGE_TRANSPARENT,
 .delay = 0,
 .image = eat_animation_eye_left,
 .next = &_eatFace_1_right_eye_id140636590484320
};

static const AnimationElement _eatFace_1_base_id140636590483264 = 
{
 .x = FACE_LEFT,
 .y = FACE_TOP,
 .w = FACE_WIDTH,
 .h = FACE_HEIGHT,
 .meta = IMAGE_DEFAULT,
 .delay = 0,
 .image = base,
 .next = &_eatFace_1_left_eye_id140636590484800
};

const AnimationSequence eatFace_1 = 
{
 .id = 0,
 .head = &_eatFace_1_base_id140636590483264
};
#pragma endregion eatFace_1

#pragma region eatFace_2
static const AnimationElement _eatFace_2_hand_id140636590485424 = 
{
 .x = FACE_LEFT + 29,
 .y = 32,
 .w = 16,
 .h = 12,
 .meta = IMAGE_TRANSPARENT,
 .delay = 0,
 .image = eat_animation_hand,
 .next = nullptr
};

static const AnimationElement _eatFace_2_mouth_id140636590484272 = 
{
 .x = MOUTH_LEFT,
 .y = MOUTH_TOP,
 .w = MOUTH_WIDTH,
 .h = MOUTH_HEIGHT,
 .meta = IMAGE_TRANSPARENT,
 .delay = 0,
 .image = hungry_mouth,
 .next = &_eatFace_2_hand_id140636590485424
};

static const AnimationElement _eatFace_2_right_eye_id140636590483216 = 
{
 .x = LEFT_EYE_LEFT,
 .y = LEFT_EYE_TOP,
 .w = EYE_WIDTH,
 .h = EYE_HEIGHT,
 .meta = IMAGE_TRANSPARENT,
 .delay = 0,
 .image = eat_animation_eye_right,
 .next = &_eatFace_2_mouth_id140636590484272
};

static const AnimationElement _eatFace_2_left_eye_id140636590485232 = 
{
 .x = LEFT_EYE_LEFT,
 .y = LEFT_EYE_TOP,
 .w = EYE_WIDTH,
 .h = EYE_HEIGHT,
 .meta = IMAGE_TRANSPARENT,
 .delay = 0,
 .image = eat_animation_eye_left,
 .next = &_eatFace_2_right_eye_id140636590483216
};

static const AnimationElement _eatFace_2_base_id140636590484704 = 
{
 .x = FACE_LEFT,
 .y = FACE_TOP,
 .w = FACE_WIDTH,
 .h = FACE_HEIGHT,
 .meta = IMAGE_DEFAULT,
 .delay = 0,
 .image = base,
 .next = &_eatFace_2_left_eye_id140636590485232
};

const AnimationSequence eatFace_2 = 
{
 .id = 1,
 .head = &_eatFace_2_base_id140636590484704
};
#pragma endregion eatFace_2

#pragma region eatFace_3
static const AnimationElement _eatFace_3_mouth_id140636590485472 = 
{
 .x = MOUTH_LEFT,
 .y = MOUTH_TOP,
 .w = MOUTH_WIDTH,
 .h = MOUTH_HEIGHT,
 .meta = IMAGE_TRANSPARENT,
 .delay = 0,
 .image = eat_animation_mouth_chew_1,
 .next = nullptr
};

static const AnimationElement _eatFace_3_right_eye_id140636590485952 = 
{
 .x = LEFT_EYE_LEFT,
 .y = LEFT_EYE_TOP,
 .w = EYE_WIDTH,
 .h = EYE_HEIGHT,
 .meta = IMAGE_TRANSPARENT,
 .delay = 0,
 .image = eat_animation_eye_right,
 .next = &_eatFace_3_mouth_id140636590485472
};

static const AnimationElement _eatFace_3_left_eye_id140636590484464 = 
{
 .x = LEFT_EYE_LEFT,
 .y = LEFT_EYE_TOP,
 .w = EYE_WIDTH,
 .h = EYE_HEIGHT,
 .meta = IMAGE_TRANSPARENT,
 .delay = 0,
 .image = eat_animation_eye_left,
 .next = &_eatFace_3_right_eye_id140636590485952
};

static const AnimationElement _eatFace_3_base_id140636590485664 = 
{
 .x = FACE_LEFT,
 .y = FACE_TOP,
 .w = FACE_WIDTH,
 .h = FACE_HEIGHT,
 .meta = IMAGE_DEFAULT,
 .delay = 0,
 .image = base,
 .next = &_eatFace_3_left_eye_id140636590484464
};

const AnimationSequence eatFace_3 = 
{
 .id = 2,
 .head = &_eatFace_3_base_id140636590485664
};
#pragma endregion eatFace_3

#pragma region eatFace_4
static const AnimationElement _eatFace_4_mouth_id140636590486384 = 
{
 .x = MOUTH_LEFT,
 .y = MOUTH_TOP,
 .w = MOUTH_WIDTH,
 .h = MOUTH_HEIGHT,
 .meta = IMAGE_TRANSPARENT,
 .delay = 0,
 .image = eat_animation_mouth_chew_2,
 .next = nullptr
};

static const AnimationElement _eatFace_4_right_eye_id140636590485856 = 
{
 .x = LEFT_EYE_LEFT,
 .y = LEFT_EYE_TOP,
 .w = EYE_WIDTH,
 .h = EYE_HEIGHT,
 .meta = IMAGE_TRANSPARENT,
 .delay = 0,
 .image = eat_animation_eye_right,
 .next = &_eatFace_4_mouth_id140636590486384
};

static const AnimationElement _eatFace_4_left_eye_id140636590486192 = 
{
 .x = LEFT_EYE_LEFT,
 .y = LEFT_EYE_TOP,
 .w = EYE_WIDTH,
 .h = EYE_HEIGHT,
 .meta = IMAGE_TRANSPARENT,
 .delay = 0,
 .image = eat_animation_eye_left,
 .next = &_eatFace_4_right_eye_id140636590485856
};

static const AnimationElement _eatFace_4_base_id140636590485808 = 
{
 .x = FACE_LEFT,
 .y = FACE_TOP,
 .w = FACE_WIDTH,
 .h = FACE_HEIGHT,
 .meta = IMAGE_DEFAULT,
 .delay = 0,
 .image = base,
 .next = &_eatFace_4_left_eye_id140636590486192
};

const AnimationSequence eatFace_4 = 
{
 .id = 3,
 .head = &_eatFace_4_base_id140636590485808
};
#pragma endregion eatFace_4

#pragma region satisfiedFace
static const AnimationElement _satisfiedFace_mouth_id140636590486816 = 
{
 .x = MOUTH_LEFT,
 .y = MOUTH_TOP,
 .w = MOUTH_WIDTH,
 .h = MOUTH_HEIGHT,
 .meta = IMAGE_TRANSPARENT,
 .delay = 0,
 .image = satisfied_mouth,
 .next = nullptr
};

static const AnimationElement _satisfiedFace_right_eye_id140636590486288 = 
{
 .x = RIGHT_EYE_LEFT,
 .y = RIGHT_EYE_TOP,
 .w = EYE_WIDTH,
 .h = EYE_HEIGHT,
 .meta = IMAGE_TRANSPARENT | IMAGE_DRAWONLY,
 .delay = 0,
 .image = satisfied_eye_right,
 .next = &_satisfiedFace_mouth_id140636590486816
};

static const AnimationElement _satisfiedFace_left_eye_id140636590486624 = 
{
 .x = LEFT_EYE_LEFT,
 .y = LEFT_EYE_TOP,
 .w = EYE_WIDTH,
 .h = EYE_HEIGHT,
 .meta = IMAGE_TRANSPARENT | IMAGE_DRAWONLY,
 .delay = 0,
 .image = satisfied_eye_left,
 .next = &_satisfiedFace_right_eye_id140636590486288
};

static const AnimationElement _satisfiedFace_base_id140636590486048 = 
{
 .x = FACE_LEFT,
 .y = FACE_TOP,
 .w = FACE_WIDTH,
 .h = FACE_HEIGHT,
 .meta = IMAGE_DRAWONLY,
 .delay = 0,
 .image = base,
 .next = &_satisfiedFace_left_eye_id140636590486624
};

const AnimationSequence satisfiedFace = 
{
 .id = 4,
 .head = &_satisfiedFace_base_id140636590486048
};
#pragma endregion satisfiedFace

#pragma region happyFace
static const AnimationElement _happyFace_mouth_id140636590486864 = 
{
 .x = MOUTH_LEFT,
 .y = MOUTH_TOP,
 .w = MOUTH_WIDTH,
 .h = MOUTH_HEIGHT,
 .meta = IMAGE_TRANSPARENT,
 .delay = 0,
 .image = happy_mouth,
 .next = nullptr
};

static const AnimationElement _happyFace_right_eye_id140636590487152 = 
{
 .x = RIGHT_EYE_LEFT,
 .y = RIGHT_EYE_TOP,
 .w = EYE_WIDTH,
 .h = EYE_HEIGHT,
 .meta = IMAGE_TRANSPARENT | IMAGE_DRAWONLY,
 .delay = 0,
 .image = happy_eye_right,
 .next = &_happyFace_mouth_id140636590486864
};

static const AnimationElement _happyFace_left_eye_id140636590485616 = 
{
 .x = LEFT_EYE_LEFT,
 .y = LEFT_EYE_TOP,
 .w = EYE_WIDTH,
 .h = EYE_HEIGHT,
 .meta = IMAGE_TRANSPARENT | IMAGE_DRAWONLY,
 .delay = 0,
 .image = happy_eye_left,
 .next = &_happyFace_right_eye_id140636590487152
};

static const AnimationElement _happyFace_base_id140636590486960 = 
{
 .x = FACE_LEFT,
 .y = FACE_TOP,
 .w = FACE_WIDTH,
 .h = FACE_HEIGHT,
 .meta = IMAGE_DRAWONLY,
 .delay = 0,
 .image = base,
 .next = &_happyFace_left_eye_id140636590485616
};

const AnimationSequence happyFace = 
{
 .id = 5,
 .head = &_happyFace_base_id140636590486960
};
#pragma endregion happyFace

#pragma region asleepFace
static const AnimationElement _asleepFace_mouth_id140636590486912 = 
{
 .x = MOUTH_LEFT,
 .y = MOUTH_TOP,
 .w = MOUTH_WIDTH,
 .h = MOUTH_HEIGHT,
 .meta = IMAGE_TRANSPARENT,
 .delay = 0,
 .image = asleep_mouth,
 .next = nullptr
};

static const AnimationElement _asleepFace_zzzs_id140636590487728 = 
{
 .x = FACE_LEFT + 55,
 .y = FACE_TOP + 7,
 .w = 8,
 .h = 11,
 .meta = IMAGE_TRANSPARENT | IMAGE_DRAWONLY,
 .delay = 0,
 .image = asleep_zzz,
 .next = &_asleepFace_mouth_id140636590486912
};

static const AnimationElement _asleepFace_right_eye_id140636590487248 = 
{
 .x = RIGHT_EYE_LEFT,
 .y = RIGHT_EYE_TOP,
 .w = EYE_WIDTH,
 .h = EYE_HEIGHT,
 .meta = IMAGE_TRANSPARENT | IMAGE_DRAWONLY,
 .delay = 0,
 .image = asleep_eye_right,
 .next = &_asleepFace_zzzs_id140636590487728
};

static const AnimationElement _asleepFace_left_eye_id140636590487536 = 
{
 .x = LEFT_EYE_LEFT,
 .y = LEFT_EYE_TOP,
 .w = EYE_WIDTH,
 .h = EYE_HEIGHT,
 .meta = IMAGE_TRANSPARENT | IMAGE_DRAWONLY,
 .delay = 0,
 .image = asleep_eye_left,
 .next = &_asleepFace_right_eye_id140636590487248
};

static const AnimationElement _asleepFace_base_id140636590486528 = 
{
 .x = FACE_LEFT,
 .y = FACE_TOP,
 .w = FACE_WIDTH,
 .h = FACE_HEIGHT,
 .meta = IMAGE_DRAWONLY,
 .delay = 0,
 .image = base,
 .next = &_asleepFace_left_eye_id140636590487536
};

const AnimationSequence asleepFace = 
{
 .id = 6,
 .head = &_asleepFace_base_id140636590486528
};
#pragma endregion asleepFace

#pragma region boredFace
static const AnimationElement _boredFace_mouth_id140636590488064 = 
{
 .x = MOUTH_LEFT,
 .y = MOUTH_TOP,
 .w = MOUTH_WIDTH,
 .h = MOUTH_HEIGHT,
 .meta = IMAGE_TRANSPARENT,
 .delay = 0,
 .image = bored_mouth,
 .next = nullptr
};

static const AnimationElement _boredFace_right_eye_id140636590488256 = 
{
 .x = RIGHT_EYE_LEFT,
 .y = RIGHT_EYE_TOP,
 .w = EYE_WIDTH,
 .h = EYE_HEIGHT,
 .meta = IMAGE_TRANSPARENT | IMAGE_DRAWONLY,
 .delay = 0,
 .image = bored_eye_right,
 .next = &_boredFace_mouth_id140636590488064
};

static const AnimationElement _boredFace_left_eye_id140636590487488 = 
{
 .x = LEFT_EYE_LEFT,
 .y = LEFT_EYE_TOP,
 .w = EYE_WIDTH,
 .h = EYE_HEIGHT,
 .meta = IMAGE_TRANSPARENT | IMAGE_DRAWONLY,
 .delay = 0,
 .image = bored_eye_left,
 .next = &_boredFace_right_eye_id140636590488256
};

static const AnimationElement _boredFace_base_id140636590487968 = 
{
 .x = FACE_LEFT,
 .y = FACE_TOP,
 .w = FACE_WIDTH,
 .h = FACE_HEIGHT,
 .meta = IMAGE_DRAWONLY,
 .delay = 0,
 .image = base,
 .next = &_boredFace_left_eye_id140636590487488
};

const AnimationSequence boredFace = 
{
 .id = 7,
 .head = &_boredFace_base_id140636590487968
};
#pragma endregion boredFace

#pragma region hungryFace
static const AnimationElement _hungryFace_mouth_id140636590488832 = 
{
 .x = MOUTH_LEFT,
 .y = MOUTH_TOP,
 .w = MOUTH_WIDTH,
 .h = MOUTH_HEIGHT,
 .meta = IMAGE_TRANSPARENT,
 .delay = 0,
 .image = hungry_mouth,
 .next = nullptr
};

static const AnimationElement _hungryFace_right_eye_id140636590488160 = 
{
 .x = RIGHT_EYE_LEFT,
 .y = RIGHT_EYE_TOP,
 .w = EYE_WIDTH,
 .h = EYE_HEIGHT,
 .meta = IMAGE_TRANSPARENT | IMAGE_DRAWONLY,
 .delay = 0,
 .image = hungry_eye_right,
 .next = &_hungryFace_mouth_id140636590488832
};

static const AnimationElement _hungryFace_left_eye_id140636590488640 = 
{
 .x = LEFT_EYE_LEFT,
 .y = LEFT_EYE_TOP,
 .w = EYE_WIDTH,
 .h = EYE_HEIGHT,
 .meta = IMAGE_TRANSPARENT | IMAGE_DRAWONLY,
 .delay = 0,
 .image = hungry_eye_left,
 .next = &_hungryFace_right_eye_id140636590488160
};

static const AnimationElement _hungryFace_base_id140636590487680 = 
{
 .x = FACE_LEFT,
 .y = FACE_TOP,
 .w = FACE_WIDTH,
 .h = FACE_HEIGHT,
 .meta = IMAGE_DRAWONLY,
 .delay = 0,
 .image = base,
 .next = &_hungryFace_left_eye_id140636590488640
};

const AnimationSequence hungryFace = 
{
 .id = 8,
 .head = &_hungryFace_base_id140636590487680
};
#pragma endregion hungryFace

#pragma region neutralFace
static const AnimationElement _neutralFace_mouth_id140636590488448 = 
{
 .x = MOUTH_LEFT,
 .y = MOUTH_TOP,
 .w = MOUTH_WIDTH,
 .h = MOUTH_HEIGHT,
 .meta = IMAGE_TRANSPARENT,
 .delay = 0,
 .image = neutral_mouth,
 .next = nullptr
};

static const AnimationElement _neutralFace_right_eye_id140636590489072 = 
{
 .x = RIGHT_EYE_LEFT,
 .y = RIGHT_EYE_TOP,
 .w = EYE_WIDTH,
 .h = EYE_HEIGHT,
 .meta = IMAGE_TRANSPARENT | IMAGE_DRAWONLY,
 .delay = 0,
 .image = neutral_eye_right,
 .next = &_neutralFace_mouth_id140636590488448
};

static const AnimationElement _neutralFace_left_eye_id140636590488544 = 
{
 .x = LEFT_EYE_LEFT,
 .y = LEFT_EYE_TOP,
 .w = EYE_WIDTH,
 .h = EYE_HEIGHT,
 .meta = IMAGE_TRANSPARENT | IMAGE_DRAWONLY,
 .delay = 0,
 .image = neutral_eye_left,
 .next = &_neutralFace_right_eye_id140636590489072
};

static const AnimationElement _neutralFace_base_id140636590488880 = 
{
 .x = FACE_LEFT,
 .y = FACE_TOP,
 .w = FACE_WIDTH,
 .h = FACE_HEIGHT,
 .meta = IMAGE_DRAWONLY,
 .delay = 0,
 .image = base,
 .next = &_neutralFace_left_eye_id140636590488544
};

const AnimationSequence neutralFace = 
{
 .id = 9,
 .head = &_neutralFace_base_id140636590488880
};
#pragma endregion neutralFace

#pragma region sickFace
static const AnimationElement _sickFace_mouth_id140636590489024 = 
{
 .x = MOUTH_LEFT,
 .y = MOUTH_TOP,
 .w = MOUTH_WIDTH,
 .h = MOUTH_HEIGHT,
 .meta = IMAGE_TRANSPARENT,
 .delay = 0,
 .image = sick_mouth,
 .next = nullptr
};

static const AnimationElement _sickFace_right_eye_id140636590489504 = 
{
 .x = RIGHT_EYE_LEFT,
 .y = RIGHT_EYE_TOP,
 .w = EYE_WIDTH,
 .h = EYE_HEIGHT,
 .meta = IMAGE_TRANSPARENT | IMAGE_DRAWONLY,
 .delay = 0,
 .image = sick_eye_right,
 .next = &_sickFace_mouth_id140636590489024
};

static const AnimationElement _sickFace_left_eye_id140636590488976 = 
{
 .x = LEFT_EYE_LEFT,
 .y = LEFT_EYE_TOP,
 .w = EYE_WIDTH,
 .h = EYE_HEIGHT,
 .meta = IMAGE_TRANSPARENT | IMAGE_DRAWONLY,
 .delay = 0,
 .image = sick_eye_left,
 .next = &_sickFace_right_eye_id140636590489504
};

static const AnimationElement _sickFace_base_id140636590489312 = 
{
 .x = FACE_LEFT,
 .y = FACE_TOP,
 .w = FACE_WIDTH,
 .h = FACE_HEIGHT,
 .meta = IMAGE_DRAWONLY,
 .delay = 0,
 .image = base,
 .next = &_sickFace_left_eye_id140636590488976
};

const AnimationSequence sickFace = 
{
 .id = 10,
 .head = &_sickFace_base_id140636590489312
};
#pragma endregion sickFace

#pragma region tiredFace
static const AnimationElement _tiredFace_mouth_id140636588802352 = 
{
 .x = MOUTH_LEFT,
 .y = MOUTH_TOP,
 .w = MOUTH_WIDTH,
 .h = MOUTH_HEIGHT,
 .meta = IMAGE_TRANSPARENT,
 .delay = 0,
 .image = tired_mouth,
 .next = nullptr
};

static const AnimationElement _tiredFace_right_eye_id140636588810992 = 
{
 .x = RIGHT_EYE_LEFT,
 .y = RIGHT_EYE_TOP,
 .w = EYE_WIDTH,
 .h = EYE_HEIGHT,
 .meta = IMAGE_TRANSPARENT | IMAGE_DRAWONLY,
 .delay = 0,
 .image = tired_eye_right,
 .next = &_tiredFace_mouth_id140636588802352
};

static const AnimationElement _tiredFace_left_eye_id140636590489408 = 
{
 .x = LEFT_EYE_LEFT,
 .y = LEFT_EYE_TOP,
 .w = EYE_WIDTH,
 .h = EYE_HEIGHT,
 .meta = IMAGE_TRANSPARENT | IMAGE_DRAWONLY,
 .delay = 0,
 .image = tired_eye_left,
 .next = &_tiredFace_right_eye_id140636588810992
};

static const AnimationElement _tiredFace_base_id140636590488304 = 
{
 .x = FACE_LEFT,
 .y = FACE_TOP,
 .w = FACE_WIDTH,
 .h = FACE_HEIGHT,
 .meta = IMAGE_DRAWONLY,
 .delay = 0,
 .image = base,
 .next = &_tiredFace_left_eye_id140636590489408
};

const AnimationSequence tiredFace = 
{
 .id = 11,
 .head = &_tiredFace_base_id140636590488304
};
#pragma endregion tiredFace
