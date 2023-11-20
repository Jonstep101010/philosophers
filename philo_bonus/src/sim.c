/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sim.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschwabe <jschwabe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 16:46:29 by jschwabe          #+#    #+#             */
/*   Updated: 2023/11/20 18:28:20 by jschwabe         ###   ########.fr       */
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
bool	philo_starving(t_philo *philo)
{
	// pthread_mutex_lock(&philo->table->death);
	// sem_wait(philo->table->death);
	// sem_wait(philo->sem);
	if (timestamp(philo->start_time)
		- philo->time_since_meal > philo->table->time_to_die)
	{
		// pthread_mutex_unlock(&philo->table->death);
		philo->dead = true;
		sem_post(philo->table->death);
		print_message(philo, "has died");
		// pthread_mutex_lock(&philo->table->death);
		sem_wait(philo->table->death);
		// pthread_mutex_unlock(&philo->table->death);
		// sem_post(philo->table->death);
		return (true);
	}
	// sem_post(philo->sem);
	// pthread_mutex_unlock(&philo->table->death);
	return (false);
}
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

// #include <signal.h>
// static void	kill_all_philos(t_philo **list)
// {
// 	int	i;

// 	i = -1;
// 	while (list[++i])
// 		kill(list[i]->pro_id, SIGSTOP);
// }

// #include <wait.h>
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
		{
			forked_philo(table->philo_list[i]);
		}
	}
}
