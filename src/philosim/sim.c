/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sim.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschwabe <jschwabe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 16:46:29 by jschwabe          #+#    #+#             */
/*   Updated: 2023/11/13 11:24:15 by jschwabe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <pthread.h>

void	take_fork(t_philo *philo)
{
	if (philo)
		print_message(philo, "has taken a fork");
}

void	select_fork(t_philo *philo)
{
	if (philo->id == philo->table->num_philos)
	{
		pthread_mutex_lock(&philo->right);
		take_fork(philo);
		pthread_mutex_lock(philo->left);
		take_fork(philo);
	}
	else
	{
		pthread_mutex_lock(philo->left);
		take_fork(philo);
		pthread_mutex_lock(&philo->right);
		take_fork(philo);
	}

}

void	eating(t_philo *philo)
{
	if (philo)
	{
		if (get_time_ms() - philo->time_since_meal > (unsigned int)philo->table->time_to_die && get_time_ms() - philo->table->start_time > philo->table->time_to_die)
		{
			print_message(philo, "has died");
			pthread_mutex_lock(&philo->table->death);
			philo->table->dead = true;
			pthread_mutex_unlock(&philo->table->death);
			return ;
		}
		select_fork(philo);
		philo->time_since_meal = timestamp(philo->table);
		print_message(philo, "is eating");
		p_sleep(philo->table->time_to_eat);
		pthread_mutex_unlock(philo->left);
		pthread_mutex_unlock(&philo->right);
		// p_sleep(philo->table->time_to_sleep);
	}
}

void	sleeping(t_philo *philo)
{
	if (philo)
	{
		print_message(philo, "is sleeping");
		p_sleep(philo->table->time_to_sleep);
	}
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
			break;
		}
		// eat
		eating(philo);
		// printf("%lu philo %d is eating\n", timestamp(philo->table), philo->id);
		// p_sleep(philo->table->time_to_eat);

		// sleep
		sleeping(philo);

		// think
		print_message(philo, "is thinking");
	}
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


/**
 * @brief
 * @warning indexing starts at 0, index num_philos points to NULL
 * @param table
 * @param first
 */
void	setup_table(t_table *table, t_philo *cur)
{
	int		i;

	if (!table)
		return ;
	i = -1;
	cur->table = table;
	table->philo_list = ft_calloc(table->num_philos + 1, sizeof(t_philo *));
	table->philo_list[table->num_philos] = NULL;
	while (++i < table->num_philos)
	{
		table->philo_list[i] = cur;
		pthread_create(&cur->thread_id, NULL, philo_routine, cur);
		cur = cur->next;
	}
}

	// pthread_detach??
t_err_table	simulation(t_philo *philos, t_table *table)
{
	setup_table(table, philos);
	if (pthread_create(&(table->thread), NULL, table_routine, table) != 0)
		return (TABLE_CREATE);
	// // pthread_create(&(table->thread), NULL, table_routine, table);
	(void)philos;
	if (pthread_join(table->thread, NULL) != 0)
		return (TABLE_JOIN);
	// table_routine(table);
	return (TABLE_OK);
	// spawn threads for philos (each with own routine)

}
