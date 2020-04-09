#include "build/temp/_test_lights.c"
#include "C:/Ruby26-x64/lib/ruby/gems/2.6.0/gems/ceedling-0.29.1/vendor/unity/src/unity.h"
#include "src/lights.h"








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

   ), (UNITY_UINT)(25), UNITY_DISPLAY_STYLE_INT);

}





void test_WhenTheHeadlight_SwitchIsOn_ThenTheHeadLightsAreOn(void)

{



    lights_SetHeadlightSwitchOn();





    UnityAssertEqualNumber((UNITY_INT)((

   1

   )), (UNITY_INT)((lights_AreHeadlightsOn())), (

   ((void *)0)

   ), (UNITY_UINT)(35), UNITY_DISPLAY_STYLE_INT);

}
