// #ifdef TEST

// #include "unity_internals.h"

#include "parse_input.h"
#include "philo.h"
#include "unity.h"

void setUp(void)
{
}

void tearDown(void)
{
}

void test_parse_input_returns_1_invalid_input(){
	char	*av[] = {"philo", "2", "1000", "800", "200", NULL};
	TEST_ASSERT_EQUAL_INT_MESSAGE(parse_input(1, av), 1, "incorrect return value");
}

void test_parse_input_returns_0_valid_input(){
	char	*av[] = {"philo", "2", "1000", "800", "200", NULL};
	TEST_ASSERT_EQUAL_INT_MESSAGE(parse_input(5, av), 0, "did not return 0 on valid input");
}

// #endif // TEST
