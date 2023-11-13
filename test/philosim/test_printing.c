// #ifdef TEST

#include "unity.h"

#include "struct.h"
#include "printing.h"
#include <unistd.h>


void setUp(void)
{
}

void tearDown(void)
{
}

void	test_assert_stdout_output(void)
{
	// provide mock data and initialize table.printing mutex
	t_philo	philo;
	t_table	table;
	pthread_mutex_init(&table.printing, NULL);
	philo.id = 1;
	philo.table = &table;
	mock_print_message(&philo, "hello world\n");
}

// void	test_redirect_to_assert(void)
// {
// 	// provide mock data and initialize table.printing mutex
// 	t_philo	philo;
// 	t_table	table;
// 	pthread_mutex_init(&table.printing, NULL);
// 	philo.id = 1;
// 	philo.table = &table;

// 	// redirect stdout to a pipe
// 	int	pipefd[2];
// 	pipe(pipefd);
// 	dup2(pipefd[1], STDOUT_FILENO);
// 	mock_print_message(&philo, "hello world\n");
// 	// read from the pipe
// 	char	buf[100];
// 	int		n = read(pipefd[0], buf, 100);
// 	buf[n] = '\0';
// 	// assert
// 	TEST_ASSERT_EQUAL_STRING("hello world\n", buf);
// 	// restore stdout
// 	dup2(STDOUT_FILENO, pipefd[1]);
// 	close(pipefd[0]);
// 	close(pipefd[1]);

// }

// #endif // TEST
