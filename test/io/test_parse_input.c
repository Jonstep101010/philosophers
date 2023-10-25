// #ifdef TEST

#include "parse_input.h"

#include "unity.h"

void setUp(void)
{
}

void tearDown(void)
{
}

void test_parse_input_returns_1_invalid_input(){
	t_input s_input;
	char	*av[] = {"philo", "2", "1000", "800", "200", NULL};
	TEST_ASSERT_EQUAL_INT_MESSAGE(1, parse_input(4, av, &s_input), "incorrect return value");
}

void test_parse_input_returns_0_valid_input(){
	t_input s_input;
	char	*av[] = {"philo", "2", "1000", "800", "200", NULL};
	TEST_ASSERT_EQUAL_INT_MESSAGE(0, parse_input(5, av, &s_input), "did not return 0 on valid input");
}

void test_parse_input_parses_mandatory_input(){
	t_input s_input;
	char	*av[] = {"philo", "2", "1000", "800", "200", NULL};
	TEST_ASSERT_EQUAL_INT_MESSAGE(0, parse_input(5, av, &s_input), "did not return 0 on valid input");
	TEST_ASSERT_EQUAL_INT_MESSAGE(2, s_input.num_philos, "num_philos");
	TEST_ASSERT_EQUAL_INT_MESSAGE(1000, s_input.time_to_die, "time_to_die");
	TEST_ASSERT_EQUAL_INT_MESSAGE(800, s_input.time_to_eat, "time_to_eat");
	TEST_ASSERT_EQUAL_INT_MESSAGE(200, s_input.time_to_sleep, "time_to_sleep");
}

void test_parse_input_parses_optional_input(){
	t_input s_input;
	char	*av[] = {"philo", "2", "1000", "800", "200", "2", NULL};
	TEST_ASSERT_EQUAL_INT_MESSAGE(0, parse_input(6, av, &s_input), "did not return 0 on valid input");
	TEST_ASSERT_EQUAL_INT_MESSAGE(2, s_input.num_philos, "num_philos");
	TEST_ASSERT_EQUAL_INT_MESSAGE(1000, s_input.time_to_die, "time_to_die");
	TEST_ASSERT_EQUAL_INT_MESSAGE(800, s_input.time_to_eat, "time_to_eat");
	TEST_ASSERT_EQUAL_INT_MESSAGE(200, s_input.time_to_sleep, "time_to_sleep");
	TEST_ASSERT_EQUAL_INT_MESSAGE(2, s_input.req_meals, "req_meals");
}

// #endif // TEST
