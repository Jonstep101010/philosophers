/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sim.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschwabe <jschwabe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 16:46:29 by jschwabe          #+#    #+#             */
/*   Updated: 2023/11/13 15:40:06 by jschwabe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <pthread.h>

bool	philo_is_dead(t_philo *philo)
{
	bool	dead;

	if (philo)
	{
		pthread_mutex_lock(&philo->table->death);
		dead = philo->table->dead;
		pthread_mutex_unlock(&philo->table->death);
		return (dead);
	}
	return (false);
}

// responsible for supervising philos
void	*table_routine(void *arg)
{
	t_table	*table;
	t_philo	*philo;


	table = (t_table *)arg;
	philo = table->philo_list[0];
	while (1)
	{
		if (timestamp(philo->table) - philo->time_since_meal > philo->table->time_to_die)
		{
			pthread_mutex_lock(&table->printing);
			print_message(philo, "has died");
			pthread_mutex_lock(&philo->table->death);
			philo->table->dead = true;
			pthread_mutex_unlock(&philo->table->death);
			pthread_mutex_unlock(&table->printing);
			return (NULL);
		}
		philo = philo->next;
		// pthread_mutex_lock(&table->death);
		// if (table->dead == true)
		// {
		// 	pthread_mutex_lock(&table->printing);
		// 	pthread_mutex_unlock(&table->death);
		// 	break;
		// }
		// pthread_mutex_unlock(&table->death);
		// p_sleep(50);

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
	int i = -1;
	while (++i < table->num_philos)
	{
		pthread_join(table->philo_list[i]->thread_id, NULL);
	}
	// printf("%lu n has died\n", timestamp(table));
	pthread_mutex_unlock(&table->printing);
	// pthread_mutex_unlock(&table->death);
	// table_routine(table);
	return (TABLE_OK);
	// spawn threads for philos (each with own routine)

}
