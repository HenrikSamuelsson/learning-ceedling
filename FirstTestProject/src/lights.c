#include "lights.h"


static bool areLightsOn = false;


void lights_SetHeadlightSwitchOff(void)
{
    areLightsOn = false;
}


void lights_SetHeadlightSwitchOn(void)
{
    /* Do nothing to see that test fails before doing the implementation. */
}


bool lights_AreHeadlightsOn(void)
{
    return areLightsOn;
}
