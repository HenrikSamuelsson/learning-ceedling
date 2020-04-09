
#include "lights.h"
#include "stdbool.h"
#include "unity.h"


void setUp(void)
{
    /* Do nothing. */
}


void tearDown(void)
{
    /* Do nothing. */
}


void test_WhenTheHeadlightSwitchIsOff_ThenTheHeadLightsAreOff(void)
{
    /* Turn off the headligths. */
    lights_SetHeadlightSwitchOff();

    /* Test that the headlights are off. */
    TEST_ASSERT_EQUAL(false, lights_AreHeadlightsOn());
}


void test_WhenTheHeadlight_SwitchIsOn_ThenTheHeadLightsAreOn(void)
{
    /* Turn on the headlights. */
    lights_SetHeadlightSwitchOn();

    /* Test that the headlights are on. */
    TEST_ASSERT_EQUAL(true, lights_AreHeadlightsOn());
}
