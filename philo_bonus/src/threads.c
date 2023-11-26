/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschwabe <jschwabe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/26 15:00:20 by jschwabe          #+#    #+#             */
/*   Updated: 2023/11/26 17:42:17 by jschwabe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	philo_starving(t_philo *philo)
{
	sem_wait(philo->sem);
	time_t	philo_time_since_meal = timestamp(philo->start_time) - philo->time_since_meal;
	if (philo_time_since_meal >= philo->table->time_to_die)
	{
		sem_wait(philo->table->print);
		philo->dead = true;
		printf("\033[1;31m\033[1m%lu\t%d died\033[0m\n", timestamp(philo->start_time), philo->id);
		sem_post(philo->table->death);
		sem_wait(philo->sem);
	}
	else
	{
		sem_post(philo->sem);
	}
}

void	*monitor_philo(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	if (!philo)
		return (NULL);
	philo->dead = false;
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
		if (philo->dead)
			break;
		sem_post(philo->sem);
	}
	// sem_post(philo->table->death);
	return (NULL);
}

void	*cleanup_philo(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	if (!philo)
		return (NULL);
	sem_wait(philo->table->death);
	// sem_wait(philo->table->print);
	// kill(philo->pro_id, SIGKILL);
	sem_post(philo->table->death);
	sem_post(philo->table->sim_end);
	return (NULL);
}
