#ifdef TEST

#include "user_input.h"
#include "../../src/utils/ft_atol.c"
#include "../../src/utils/ft_calloc.c"
#include "../../src/utils/utils_time.c"

#include "unity.h"

void setUp(void)
{
}

void tearDown(void)
{
}

void test_isdigit()
{
	for (int i = 0; i <= 9; i++) {
		TEST_ASSERT_EQUAL(true, ft_isdigit(i + '0'));
	}
	for (int i = 10; i <= 127; i++) {
		TEST_ASSERT_EQUAL(false, ft_isdigit(i + '0'));
	}
}

void test_parse_input_returns_1_invalid_input(){
	t_table *table;
	char	*av[] = {"philo", "2", "1000", "800", "200", NULL};
	TEST_ASSERT_EQUAL_INT_MESSAGE(EXIT_FAILURE, validate_and_init(&table , 4, av), "incorrect return value");
}

void test_parse_input_returns_0_valid_input(){
	t_table *table;
	char	*av[] = {"philo", "2", "1000", "800", "200", NULL};
	TEST_ASSERT_EQUAL_INT_MESSAGE(0, validate_and_init(&table ,5, av), "did not return 0 on valid input");
	free(table);
}

void test_parse_input_parses_mandatory_input(){
	t_table *table;
	char	*av[] = {"philo", "2", "1000", "800", "200", NULL};
	TEST_ASSERT_EQUAL_INT_MESSAGE(0, validate_and_init(&table ,5, av), "did not return 0 on valid input");
	TEST_ASSERT_EQUAL_INT_MESSAGE(2, table->num_philos, "num_philos");
	TEST_ASSERT_EQUAL_INT_MESSAGE(1000, table->time_to_die, "time_to_die");
	TEST_ASSERT_EQUAL_INT_MESSAGE(800, table->time_to_eat, "time_to_eat");
	TEST_ASSERT_EQUAL_INT_MESSAGE(200, table->time_to_sleep, "time_to_sleep");
	free(table);
}

void test_parse_input_parses_optional_input(){
	t_table *table;
	char	*av[] = {"philo", "2", "1000", "800", "200", "2", NULL};
	TEST_ASSERT_EQUAL_INT_MESSAGE(0, validate_and_init(&table, 6, av), "did not return 0 on valid input");
	TEST_ASSERT_EQUAL_INT_MESSAGE(2, table->num_philos, "num_philos");
	TEST_ASSERT_EQUAL_INT_MESSAGE(1000, table->time_to_die, "time_to_die");
	TEST_ASSERT_EQUAL_INT_MESSAGE(800, table->time_to_eat, "time_to_eat");
	TEST_ASSERT_EQUAL_INT_MESSAGE(200, table->time_to_sleep, "time_to_sleep");
	TEST_ASSERT_EQUAL_INT_MESSAGE(2, table->meals_to_eat, "req_meals");
	free(table);
}

void test_parse_input_parses_correct_time(){
	t_table	*table;
	char	*av[] = {"philo", "2", "1000", "800", "200", "2", NULL};
	time_t	cmp = time(NULL);
	validate_and_init(&table, 6, av);
	TEST_ASSERT_UINT64_WITHIN(2, cmp, table->start_time/1000);
	free(table);
}

#endif // TEST
