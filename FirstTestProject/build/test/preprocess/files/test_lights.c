#include "build/temp/_test_lights.c"
#include "src/lights.h"
#include "C:/Ruby26-x64/lib/ruby/gems/2.6.0/gems/ceedling-0.29.1/vendor/unity/src/unity.h"






void setUp(void)

{

}



void tearDown(void)

{

}



void test_WhenTheHeadlightSwitchIsOff_ThenTheHeadLightsAreOff(void)

{



    lights_SetHeadlightSwitchOff();



    UnityAssertEqualNumber((UNITY_INT)((

   0

   )), (UNITY_INT)((lights_AreHeadlightsOn())), (

   ((void *)0)

   ), (UNITY_UINT)(19), UNITY_DISPLAY_STYLE_INT);

}
