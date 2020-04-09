#include "tempSensor.h"
#include "unity.h"

#include "mock_i2c.h"


void setUp(void)
{
    /* Do nothing. */
}


void tearDown(void)
{
    /* Do nothing. */
}


void test_whenTempRegisterReadsMaxValue_thenTheTempIsTheMaxValue(void)
{
    const uint8_t TEMP_REGISTER_ADDRESS = 0x03;
    float expectedTemp = 104.6f;
    float tolerance = 0.1f;
    
    /* When the temperature register of mock temperature sensor holds 0x3ff. */
    i2c_readRegister_ExpectAndReturn(TEMP_REGISTER_ADDRESS, 0x3ff);
    
    /* Then we expect to to get a certain temperature */
    float actualTemperature = tempSensor_getTemperature();

    /* Test that we got the expected temperature. */
    TEST_ASSERT_FLOAT_WITHIN(tolerance, expectedTemp, actualTemperature);
}
