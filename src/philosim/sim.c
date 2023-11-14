/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sim.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschwabe <jschwabe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 16:46:29 by jschwabe          #+#    #+#             */
/*   Updated: 2023/11/14 12:47:10 by jschwabe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <pthread.h>

// responsible for supervising philos
void	*table_routine(void *arg)
{
	t_table	*table;
	t_philo	*philo;
	int		tmp_id;

	table = (t_table *)arg;
	philo = table->philo_list[0];
	while (1)
	{
		pthread_mutex_lock(&philo->mutex);
		if (timestamp(philo->table) - philo->time_since_meal > philo->table->time_to_die && philo->meal_count != 0)
		{
			print_message(philo, "has died");
			pthread_mutex_lock(&philo->table->death);
			philo->table->dead = true;
			pthread_mutex_unlock(&philo->table->death);
			pthread_mutex_unlock(&philo->mutex);
			return (NULL);
		}
		if (philo->meal_count == 0)
		{
			tmp_id = philo->id;
			philo = philo->next;
			while (philo->id != tmp_id)
			{
				if (philo->meal_count == 0)
				{
					philo = philo->next;
				}
			}
			if (philo->id == tmp_id)
				return (NULL);
		}
		pthread_mutex_unlock(&philo->mutex);
		philo = philo->next;
	}
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
	// if (pthread_create(&(table->thread), NULL, table_routine, table) != 0)
	// 	return (TABLE_CREATE);
	table_routine((void *)table);
	// // pthread_create(&(table->thread), NULL, table_routine, table);
	// (void)philos;
	// if (pthread_join(table->thread, NULL) != 0)
	// 	return (TABLE_JOIN);
	int i = -1;
	while (++i < table->num_philos)
		pthread_join(table->philo_list[i]->thread_id, NULL);
	// printf("%lu n has died\n", timestamp(table));
	// pthread_mutex_unlock(&table->printing);
	// pthread_mutex_unlock(&table->death);
	// table_routine(table);
	return (TABLE_OK);
	// spawn threads for philos (each with own routine)

}
