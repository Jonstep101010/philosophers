// #ifdef TEST

#include "parse_input.h"
#include "../../src/io/ft_atol.c"
#include "../../src/utils/checks.c"
#include "../../src/utils/ft_calloc.c"

#include "unity.h"

void setUp(void)
{
}

void tearDown(void)
{
}

void test_parse_input_returns_1_invalid_input(){
	t_input *s_input;
	char	*av[] = {"philo", "2", "1000", "800", "200", NULL};
	TEST_ASSERT_EQUAL_INT_MESSAGE(EXIT_FAILURE, validate_and_init(&s_input , 4, av), "incorrect return value");
}

void test_parse_input_returns_0_valid_input(){
	t_input *s_input;
	char	*av[] = {"philo", "2", "1000", "800", "200", NULL};
	TEST_ASSERT_EQUAL_INT_MESSAGE(0, validate_and_init(&s_input ,5, av), "did not return 0 on valid input");
	free(s_input);
}

void test_parse_input_parses_mandatory_input(){
	t_input *s_input;
	char	*av[] = {"philo", "2", "1000", "800", "200", NULL};
	TEST_ASSERT_EQUAL_INT_MESSAGE(0, validate_and_init(&s_input ,5, av), "did not return 0 on valid input");
	TEST_ASSERT_EQUAL_INT_MESSAGE(2, s_input->num_philos, "num_philos");
	TEST_ASSERT_EQUAL_INT_MESSAGE(1000, s_input->time_to_die, "time_to_die");
	TEST_ASSERT_EQUAL_INT_MESSAGE(800, s_input->time_to_eat, "time_to_eat");
	TEST_ASSERT_EQUAL_INT_MESSAGE(200, s_input->time_to_sleep, "time_to_sleep");
	free(s_input);
}

void test_parse_input_parses_optional_input(){
	t_input *s_input;
	char	*av[] = {"philo", "2", "1000", "800", "200", "2", NULL};
	TEST_ASSERT_EQUAL_INT_MESSAGE(0, validate_and_init(&s_input, 6, av), "did not return 0 on valid input");
	TEST_ASSERT_EQUAL_INT_MESSAGE(2, s_input->num_philos, "num_philos");
	TEST_ASSERT_EQUAL_INT_MESSAGE(1000, s_input->time_to_die, "time_to_die");
	TEST_ASSERT_EQUAL_INT_MESSAGE(800, s_input->time_to_eat, "time_to_eat");
	TEST_ASSERT_EQUAL_INT_MESSAGE(200, s_input->time_to_sleep, "time_to_sleep");
	TEST_ASSERT_EQUAL_INT_MESSAGE(2, s_input->meals_to_eat, "req_meals");
	free(s_input);
}

// #endif // TEST
