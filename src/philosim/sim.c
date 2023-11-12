/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sim.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschwabe <jschwabe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 16:46:29 by jschwabe          #+#    #+#             */
/*   Updated: 2023/11/12 20:09:30 by jschwabe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <pthread.h>

void	take_fork(t_philo *philo, int n)
{
	if (philo)
		printf("%lu philo %d has taken a fork\n", timestamp(philo->table), n);
}

void	select_fork(t_philo *philo)
{
	if (philo->id == philo->table->num_philos)
	{
		pthread_mutex_lock(&philo->right);
		take_fork(philo, philo->id);
		pthread_mutex_lock(philo->left);
		take_fork(philo, philo->id);
	}
	else
	{
		pthread_mutex_lock(philo->left);
		take_fork(philo, philo->id);
		pthread_mutex_lock(&philo->right);
		take_fork(philo, philo->id);
	}

}

void	eating(t_philo *philo)
{
	// check if philo is valid
	if (philo)
	{
		if (timestamp(philo->table) > (unsigned int)philo->table->time_to_die)
		{
			printf("%lu philo %d had died\n", timestamp(philo->table), philo->id);
			pthread_mutex_lock(&philo->table->death);
			philo->table->dead = true;
			pthread_mutex_unlock(&philo->table->death);
		}
		select_fork(philo);
		philo->time_since_meal = get_time_ms();
		printf("%lu philo %d is eating\n", timestamp(philo->table), philo->id);
		p_sleep(philo->table->time_to_eat);
		pthread_mutex_unlock(philo->left);
		pthread_mutex_unlock(&philo->right);
		// p_sleep(philo->table->time_to_sleep);
	}

	// take forks
	// eat
	// put forks
}
void	*philo_routine(void *arg)
{
	t_philo	*philo;
	bool	dead;

	philo = (t_philo *)arg;
	if (!philo)
		return (NULL);
	if (philo->id % 2 == 0)
		p_sleep(philo->table->time_to_eat / 2);
	while (1)
	{
		pthread_mutex_lock(&philo->table->death);
		dead = philo->table->dead;
		pthread_mutex_unlock(&(philo->table->death));
		if (dead)
		{
			printf("philo %d is dead\n", philo->id);
			break;
		}
		// eat
		eating(philo);
		// printf("%lu philo %d is eating\n", timestamp(philo->table), philo->id);
		// p_sleep(philo->table->time_to_eat);

		// sleep
		printf("%lu philo %d is sleeping\n", timestamp(philo->table), philo->id);
		p_sleep(philo->table->time_to_sleep);

		// think
		printf("%lu philo %d is thinking\n", timestamp(philo->table), philo->id);
		p_sleep(philo->table->time_to_think);
	}
	printf("some philo data from thread: %d\n", philo->id);
	return (NULL);
}

// responsible for supervising philos
void	*table_routine(void *arg)
{
	t_table	*table;

	table = (t_table *)arg;
	while (1)
	{
		pthread_mutex_lock(&table->death);
		if (table->dead == true)
			break;
		pthread_mutex_unlock(&table->death);
		p_sleep(50);
	}
		// p_sleep(50);
	// p_sleep(1000);
	// pthread_mutex_lock(&(table->death));
	// supervise philos, see if they are dead -> using time
	// printf("some table data from thread: %d\n", table->num_philos);
	return (NULL);
}

	// pthread_detach??
t_err_table	simulation(t_philo *philos, t_table *table)
{
	// if (pthread_create(&(table->thread), NULL, table_routine, table) != 0)
	// 	return (TABLE_CREATE);
	// // pthread_create(&(table->thread), NULL, table_routine, table);
	(void)philos;
	// if (pthread_join(table->thread, NULL) != 0)
	// 	return (TABLE_JOIN);
	table_routine(table);
	return (TABLE_OK);
	// (void)rules;
	// (void)philos;
	// spawn threads for philos (each with own routine)
	// spawn table for supervision
	// t_sim	*sim;

	// if (rules->num_philos % 2 == 0)
	// 	even_number_philos
	// if (pthread_create(philos->thread_id, , &philo_routine, philos))
}
