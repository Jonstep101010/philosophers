// #ifdef TEST

#include "unity.h"

#include "struct.h"
#include <unistd.h>
# include <stddef.h>
# include <sys/time.h>
# include <stdio.h>

time_t	mock_get_time_ms(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return ((tv.tv_sec * 1000) + (tv.tv_usec / 1000));
}

unsigned long	mock_timestamp(t_table *table)
{
	return ((mock_get_time_ms() - table->start_time));
}

void	mock_print_message(t_philo *philo, char *msg)
{
	pthread_mutex_lock(&philo->table->printing);
	pthread_mutex_lock(&philo->table->death);
	if (!philo->table->dead)
		printf("%lu %d %s\n", mock_timestamp(philo->table), philo->id, msg);
	pthread_mutex_unlock(&philo->table->death);
	pthread_mutex_unlock(&philo->table->printing);
}

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
