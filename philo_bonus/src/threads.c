/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschwabe <jschwabe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/26 15:00:20 by jschwabe          #+#    #+#             */
/*   Updated: 2023/11/28 08:46:41 by jschwabe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"
#include <semaphore.h>

void	philo_starving(t_philo *philo)
{
	sem_wait(philo->table->print);
	sem_wait(philo->sem);
	time_t	philo_time_since_meal = timestamp(philo->start_time) - philo->time_since_meal;
	if (philo_time_since_meal >= philo->table->time_to_die && !philo->sim_end)
	{
		philo->dead = true;
		sem_post(philo->sem);
		return ;
	}
	else
	{
		sem_post(philo->sem);
		sem_post(philo->table->print);
	}
}

void	*monitor_philo(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	if (!philo)
		return (NULL);
	// printf("%d from thread\n", getpid());
	philo->time_since_meal = 0;
	philo->start_time = get_time_ms();
	sem_wait(philo->table->sync_start);
	philo->start_time = get_time_ms();
	sem_post(philo->sem);
	p_sleep(philo->table->time_to_die);
	while (1)
	{
		philo_starving(philo);
		sem_wait(philo->sem);
		if (philo->dead && !philo->sim_end)
		{
			printf("\033[1;31m\033[1m%lu\t%d died\033[0m\n", timestamp(philo->start_time), philo->id);
			sem_post(philo->sem);
			sem_post(philo->table->death);
			return (NULL);
		}
		sem_post(philo->sem);
	}
	return (NULL);
}

void	*cleanup_philo(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	if (!philo)
		return (NULL);
	sem_wait(philo->table->sim_end);
	sem_wait(philo->sem);
	exit(0);
}
