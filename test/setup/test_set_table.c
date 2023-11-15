// #ifdef TEST

#include "unity.h"

#include "unity.h"
#include "struct.h"
#include "set_table.h"
#include "utils/utils.h"
#include "utils/ft_calloc.c"

void setUp(void)
{
}

void tearDown(void)
{
}

void	test_setup_table_returns_null_invalid() {
	t_table table = {0};
	TEST_ASSERT_NULL(table.num_philos);
	TEST_ASSERT_NULL(setup(&table));
	TEST_ASSERT_NULL(setup(NULL));
}

// // FILEPATH: /workspace/philo/test/setup/test_set_table.c
void	test_create_philo_returns_null_invalid(){
	t_table	table = {0};
	TEST_ASSERT_NULL(create_philo(NULL, 1));
	TEST_ASSERT_NULL(create_philo(&table, 0));
	TEST_ASSERT_NULL(create_philo(&table, 1));
	table.num_philos = 1;
	TEST_ASSERT_NULL(create_philo(&table, 2));
}

void test_create_philo_returns_null_when_id_greater_than_num_philos(void)
{
	t_table table = {0};
	t_philo *new_philo = create_philo(&table, 2);
	TEST_ASSERT_NULL(new_philo);
}
void	test_create_philo_returns_valid(){
	t_table	table = {0};
	table.num_philos = 1;
	TEST_ASSERT_NOT_NULL(create_philo(&table, 1));
}

// FILEPATH: /workspace/philo/test/setup/test_set_table.c
void	test_setup_returns_valid(){
	t_table	table = {0};
	table.num_philos = 1;
	TEST_ASSERT_NOT_NULL(setup(&table));
}

void test_set_philos_returns_first_philo(void)
{
	t_table table = {0};
	table.num_philos = 3;
	t_philo *first_philo = create_philo(&table, 1);
	TEST_ASSERT_NOT_NULL(first_philo);
	TEST_ASSERT_EQUAL(1, first_philo->id);
	TEST_ASSERT_EQUAL_PTR(first_philo->next->next->next, first_philo);
	// TEST_ASSERT_EQUAL_PTR(&first_philo->right, first_philo->left);
}

void test_setup_table_assigns_id_correctly(void)
{
	t_table	table;
	memset(&table, 0, sizeof(table));
	table.num_philos = 4;
	t_philo *first_philo = create_philo(&table, 1);
	setup(&table);
	TEST_ASSERT_NOT_NULL(table.philo_list);
	TEST_ASSERT_NOT_NULL(table.philo_list[0]);
}

void test_set_philos_with_non_null_table(void)
{
	t_table table;
	table.num_philos = 3;
	setup(&table);
	TEST_ASSERT_NOT_NULL(&table);
	for (int i = 0; i < table.num_philos; i++)
	{
		TEST_ASSERT_NOT_NULL(table.philo_list[i]);
		TEST_ASSERT_EQUAL(i + 1, table.philo_list[i]->id);
	}
	TEST_ASSERT_NULL(table.philo_list[table.num_philos]);
	// check next pointers
	t_philo	*first;
	first = table.philo_list[0];
	TEST_ASSERT_EQUAL_PTR(first, table.philo_list[0]);
	for (int i = 0; i < table.num_philos - 1; i++)
	{
		TEST_ASSERT_EQUAL_PTR(first, table.philo_list[i]);
		first = first->next;
	}
	// check fork last right is first left
	first = table.philo_list[0];
	TEST_ASSERT_EQUAL_PTR(first->left, &table.philo_list[table.num_philos - 1]->right);
}
