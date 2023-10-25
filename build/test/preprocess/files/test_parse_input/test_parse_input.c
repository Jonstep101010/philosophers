// CEEDLING NOTICE: This generated file only to be consumed for test runner creation

#include "include/io/parse_input.h"
#include "include/philo.h"
#include "build/vendor/unity/src/unity.h"

void setUp(void)
{
}

void tearDown(void)
{
}

void test_parse_input_returns_1_invalid_input(){
 char *av[] = {"philo", "2", "1000", "800", "200", ((void*)0)};

 UnityAssertEqualNumber((UNITY_INT)((parse_input(1, av))), (UNITY_INT)((1)), (("incorrect return value")), (UNITY_UINT)(19), UNITY_DISPLAY_STYLE_INT);
}

void test_parse_input_returns_0_valid_input(){
 char *av[] = {"philo", "2", "1000", "800", "200", ((void*)0)};

 UnityAssertEqualNumber((UNITY_INT)((parse_input(5, av))), (UNITY_INT)((0)), (("did not return 0 on valid input")), (UNITY_UINT)(24), UNITY_DISPLAY_STYLE_INT);
}
