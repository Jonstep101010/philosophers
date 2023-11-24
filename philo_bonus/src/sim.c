/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sim.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschwabe <jschwabe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 16:46:29 by jschwabe          #+#    #+#             */
/*   Updated: 2023/11/24 15:14:57 by jschwabe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"
#include <semaphore.h>

	// if (philo->meal_count == 0)
	// {
	// 	// pthread_mutex_unlock(&philo->table->death);
	// 	sem_post(philo->table->death);
	// 	return (false);
	// }

/*
bool	philos_have_eaten(t_philo *philo, int *tmp_id)
{
	sem_wait(philo->table->death);
	if (philo->meal_count == 0)
	{
		*tmp_id = philo->id;
		philo = philo->next;
		while (philo->id != *tmp_id)
		{
			if (philo->meal_count != 0)
				break ;
			philo = philo->next;
		}
		if (philo->id == *tmp_id)
		{
			sem_post(philo->table->death);
			return (true);
		}
	}
	sem_post(philo->table->death);
	return (false);
}
*/

#include <signal.h>
void	simulation(t_table *table)
{
	t_philo	*philo;
	t_philo	**list;
	int		i;

	list = table->philo_list;
	philo = list[0];
	i = -1;
	while (++i < table->num_philos)
	{
		table->philo_list[i]->pro_id = fork();
		if (table->philo_list[i]->pro_id == 0)
			forked_philo(table->philo_list[i]);
	}
	sem_post(table->sync_start);
	// sem_wait(philo->table->sim_end);
	sem_wait(philo->table->sim_end);
	i = -1;
	while (list[++i])
		kill(list[i]->pro_id, SIGKILL);
}
