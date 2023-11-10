// #ifdef TEST

#include "unity.h"

#include "unity.h"
#include "philo.h"
#include "struct.h"
#include "set_philos.h"
#include "utils/utils.h"
#include "utils/ft_calloc.c"

void setUp(void)
{
}

void tearDown(void)
{
}

void test_set_philos_with_non_null_table(void)
{
	t_table *table = malloc(sizeof(t_table *));
	table->num_philos = 1;
	t_philo *new_philo = create_philo(table, 1);
	TEST_ASSERT_NOT_NULL(new_philo);
	TEST_ASSERT_EQUAL(1, new_philo->id);
	TEST_ASSERT_NULL(new_philo->next);
	TEST_ASSERT_EQUAL_PTR(table, new_philo->input);
	free(table);
	table = malloc(sizeof(t_table *));
	table->num_philos = 3;
	t_philo *first_philo = set_philos(table);
	TEST_ASSERT_NOT_NULL(first_philo);
	TEST_ASSERT_EQUAL(1, first_philo->id);
	TEST_ASSERT_EQUAL_PTR(first_philo->next->next->next, first_philo);
	TEST_ASSERT_EQUAL_PTR(first_philo->left, &first_philo->next->next->right);
	TEST_ASSERT_EQUAL_PTR(first_philo->next->left, &first_philo->right);
	TEST_ASSERT_EQUAL_PTR(table->philo_list[3], NULL);
	free(table);

	// TEST_ASSERT_EQUAL(PTHREAD_MUTEX_INITIALIZER, new_philo->right);
}


// @warning should only be static anyway
// checks are made anyway, should not happen since caller (set_philos) is responsible for catching invalid input
// void test_create_philo_returns_null_when_id_greater_than_num_philos(void)
// {
// 	t_table table = {0};
// @brief if no num_philos set, main will return invalid_input info to user
// 	t_philo *new_philo = create_philo(&table, 2);
// 	TEST_ASSERT_NULL(new_philo);
// }

void test_setup_table_assigns_philo_list_correctly(void)
{
	t_table	table;
	memset(&table, 0, sizeof(table));
	table.num_philos = 1;
	t_philo *first_philo = create_philo(&table, 1);
	setup_table(&table, first_philo);
	TEST_ASSERT_NOT_NULL(table.philo_list);
	TEST_ASSERT_EQUAL_PTR(first_philo, table.philo_list[0]);
}

void test_setup_table_handles_null(void)
{
	t_table *table = {0};
	t_philo *first_philo = create_philo(table, 1);
	TEST_ASSERT_NULL(table);
	TEST_ASSERT_NULL(first_philo);
	setup_table(table, first_philo);
	TEST_ASSERT_NULL(table);
}

void test_set_philos_returns_first_philo(void)
{
	t_table table = {0};
	table.num_philos = 3;
	t_philo *first_philo = set_philos(&table);
	TEST_ASSERT_NOT_NULL(first_philo);
	TEST_ASSERT_EQUAL(1, first_philo->id);
	TEST_ASSERT_EQUAL_PTR(first_philo->next->next->next, first_philo);
	TEST_ASSERT_EQUAL_PTR(first_philo->left, &first_philo->next->next->right);
	TEST_ASSERT_EQUAL_PTR(first_philo->next->left, &first_philo->right);
	TEST_ASSERT_EQUAL_PTR(table.philo_list[3], NULL);
}

void test_set_philos_returns_null_invalid_table(void)
{
	t_philo *first_philo = set_philos(NULL);
	TEST_ASSERT_NULL(first_philo);
}
