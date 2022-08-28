#include <stdio.h>
#include "pico/stdlib.h"
#include "PandaStateMachine.hpp"

PandaStateMachine::PandaStateMachine()
{
    printf("Hello Panda!");
}

#pragma region transition_from

void PandaStateMachine::transitionFromNeutralState()
{

}

void PandaStateMachine::transitionFromSatisfiedState()
{

}

void PandaStateMachine::transitionFromHappyState()
{

}

void PandaStateMachine::transitionFromSickState()
{

}

void PandaStateMachine::transitionFromWasteState()
{

}

void PandaStateMachine::transitionFromHungryState()
{

}

void PandaStateMachine::transitionFromTiredState()
{

}

void PandaStateMachine::transitionFromAsleepState()
{

}

void PandaStateMachine::transitionFromBoredState()
{

}

void PandaStateMachine::transitionFromFakeNeedsAttentionState()
{

}

#pragma endregion transition_from


#pragma region transition_to

PandaState PandaStateMachine::getNewRandomState()
{
    return NEUTRAL;
}

void PandaStateMachine::transitionToNewRandomState()
{

}

void PandaStateMachine::transitionToNeutralState()
{

}

void PandaStateMachine::transitionToSatisfiedState()
{

}

void PandaStateMachine::transitionToHappyState()
{

}

void PandaStateMachine::transitionToSickState()
{

}

void PandaStateMachine::transitionToWasteState()
{

}

void PandaStateMachine::transitionToHungryState()
{

}

void PandaStateMachine::transitionToTiredState()
{

}

void PandaStateMachine::transitionToAsleepState()
{

}

void PandaStateMachine::transitionToBoredState()
{

}

void PandaStateMachine::transitionToFakeNeedsAttentionState()
{

}

#pragma endregion transition_to


#pragma region callbacks

void PandaStateMachine::callback()
{

}

void PandaStateMachine::callbackNeutralState()
{

}

void PandaStateMachine::callbackSatisfiedState()
{

}

void PandaStateMachine::callbackHappyState()
{

}

void PandaStateMachine::callbackSickState()
{

}

void PandaStateMachine::callbackWasteState()
{

}

void PandaStateMachine::callbackHungryState()
{

}

void PandaStateMachine::callbackTiredState()
{

}

void PandaStateMachine::callbackAsleepState()
{

}

void PandaStateMachine::callbackBoredState()
{

}

void PandaStateMachine::callbackFakeNeedsAttentionState()
{

}


#pragma endregion callbacks


#pragma region application_state_management

void PandaStateMachine::enterInfoScreen()
{

}

void PandaStateMachine::exitInfoScreen()
{

}

#pragma endregion application_state_management


#pragma region display_and_draw

void PandaStateMachine::redraw()
{

}

void PandaStateMachine::drawMenu()
{

}

void PandaStateMachine::drawNeutralState()
{

}

void PandaStateMachine::drawSatisfiedState()
{

}

void PandaStateMachine::drawHappyState()
{

}

void PandaStateMachine::drawSickState()
{

}

void PandaStateMachine::drawWasteState()
{

}

void PandaStateMachine::drawHungryState()
{

}

void PandaStateMachine::drawTiredState()
{

}

void PandaStateMachine::drawAsleepState()
{

}

void PandaStateMachine::drawBoredState()
{

}

void PandaStateMachine::drawFakeNeedsAttentionState()
{

}

void PandaStateMachine::drawInfoScreen()
{

}

void PandaStateMachine::display()
{

}

uint8_t PandaStateMachine::getMenuX(uint8_t index)
{
    return 0;
}

uint8_t PandaStateMachine::getMenuY(uint8_t index)
{
    return 0;
}


#pragma endregion display_and_draw


#pragma region buttons

void PandaStateMachine::pressA()
{

}

void PandaStateMachine::pressB()
{

}

void PandaStateMachine::pressC()
{

}

void PandaStateMachine::buttonFood()
{

}

void PandaStateMachine::buttonLight()
{

}

void PandaStateMachine::buttonPlay()
{

}

void PandaStateMachine::buttonDoctor()
{

}

void PandaStateMachine::buttonToilet()
{

}

void PandaStateMachine::buttonInfo()
{

}

void PandaStateMachine::buttonDiscipline()
{

}

#pragma endregion buttons


#pragma region save_load

void PandaStateMachine::loadState()
{

}

void PandaStateMachine::saveState()
{

}

#pragma endregion save_load


#pragma region delays

uint32_t PandaStateMachine::getDelayLong()
{
    return 0;
}

uint32_t PandaStateMachine::getDelayMedium()
{
    return 0;
}

uint32_t PandaStateMachine::getDelayShort()
{
    return 0;
}

uint32_t PandaStateMachine::getDelayCustom(uint32_t min, uint32_t max)
{
    return 0;
}

#pragma endregion delays


#pragma region misc

void PandaStateMachine::lightsOn()
{

}

void PandaStateMachine::lightsOff()
{

}

uint8_t PandaStateMachine::clampedMath(uint8_t value, int16_t difference, uint8_t min, uint8_t max)
{
    return 0;
}

#pragma endregion misc