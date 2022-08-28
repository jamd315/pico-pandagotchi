#ifndef _PANDA_H
#define _PANDA_H

// Long time, e.g. time spent on neutral state or between asleep checks
#define DELAY_LONG_LOW 10000
#define DELAY_LONG_HIGH 20000

// Standard wait time before consequences, most actions
#define DELAY_MEDIUM_LOW 5000
#define DELAY_MEDIUM_HIGH 10000

// Actions that need to be remedied quickly
#define DELAY_SHORT_LOW 1000
#define DELAY_SHORT_HIGH 5000

// Configurable
#define SLEEP_TIME 60000  // 1 minute
#define WAKE_INTERACTION_COUNT 5  // How many button presses before forced wake
#define HEALTH_MAX 10
// Percents
#define UNDECAY_CHANCE 10  // Chance to undecay (e.g. from satisfied to happy)
#define HEALTH_GAIN_CHANCE 25  // After successful interaction (e.g. fed when hungry) chance to gain health
#define MISCHIEVIOUS_CHANCE 10
#define WASTE_TO_SICK_CHANCE 20  // After failing to clear waste, chance to get sick
#define HUNGRY_TO_SICK_CHANCE 10  // After failed to feed when hungry, chance to get sick

typedef enum PandaState  // State of the Panda
{
    FAKE_NEED_ATTENTION,
    SICK,
    WASTE,
    HUNGRY,
    TIRED,
    ASLEEP,
    BORED,
    HAPPY,
    SATISFIED,
    NEUTRAL
} PandaState;

typedef enum ApplicationState  // State of the application (e.g. what screen is displayed)
{
    MAIN_SCREEN,
    INFO_SCREEN
} ApplicationState;

class PandaStateMachine
{
public:
    PandaStateMachine();

    // Panda transition FROM
    void transitionFromNeutralState();
    void transitionFromSatisfiedState();
    void transitionFromHappyState();
    void transitionFromSickState();
    void transitionFromWasteState();
    void transitionFromHungryState();
    void transitionFromTiredState();
    void transitionFromAsleepState();
    void transitionFromBoredState();
    void transitionFromFakeNeedsAttentionState();

    // Panda transition TO
    PandaState getNewRandomState();
    void transitionToNewRandomState();
    void transitionToNeutralState();
    void transitionToSatisfiedState();
    void transitionToHappyState();
    void transitionToSickState();
    void transitionToWasteState();
    void transitionToHungryState();
    void transitionToTiredState();
    void transitionToAsleepState();
    void transitionToBoredState();
    void transitionToFakeNeedsAttentionState();

    // Panda callback after timeout
    void callback();
    void callbackNeutralState();
    void callbackSatisfiedState();
    void callbackHappyState();
    void callbackSickState();
    void callbackWasteState();
    void callbackHungryState();
    void callbackTiredState();
    void callbackAsleepState();
    void callbackBoredState();
    void callbackFakeNeedsAttentionState();

    // Application state management
    void enterInfoScreen();
    void exitInfoScreen();

    // Draw and display
    void redraw();
    void drawMenu();
    void drawNeutralState();
    void drawSatisfiedState();
    void drawHappyState();
    void drawSickState();
    void drawWasteState();
    void drawHungryState();
    void drawTiredState();
    void drawAsleepState();
    void drawBoredState();
    void drawFakeNeedsAttentionState();
    void drawInfoScreen();
    void display();
    uint8_t getMenuX(uint8_t index);
    uint8_t getMenuY(uint8_t index);

    // Button presses
    void pressA();
    void pressB();
    void pressC();
    void buttonFood();
    void buttonLight();
    void buttonPlay();
    void buttonDoctor();
    void buttonToilet();
    void buttonInfo();
    void buttonDiscipline();

    // Save and load state
    void loadState();
    void saveState();

    // Delays
    uint32_t getDelayLong(); // Long time, e.g. time spent on neutral state or between asleep checks
    uint32_t getDelayMedium(); // Standard wait time before consequences, most actions
    uint32_t getDelayShort(); // Actions that need to be remedied quickly
    uint32_t getDelayCustom(uint32_t min, uint32_t max);  // Custom delay between min and max ms

    // Misc and helper funcs
    void lightsOn();
    void lightsOff();
    // Modify value by difference and clamp between min and max
    uint8_t clampedMath(uint8_t value, int16_t difference, uint8_t min=0, uint8_t max=255);

protected:
    PandaState activePandaState;
    ApplicationState applicationState;
};

#endif // Header guard