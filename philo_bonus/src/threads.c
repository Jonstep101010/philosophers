/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschwabe <jschwabe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/26 15:00:20 by jschwabe          #+#    #+#             */
/*   Updated: 2023/12/01 18:13:59 by jschwabe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"
#include <semaphore.h>
#include <unistd.h>

void	philo_starving(t_philo *philo)
{
	time_t	philo_time_since_meal;
	if (!philo || !philo->sem)
		return ;
	sem_wait(philo->sem);
	philo_time_since_meal = timestamp(philo->start_time) - philo->time_since_meal;
	if (philo_time_since_meal > philo->table->time_to_die && !philo->dead)
	{
		printf("still alive: %d\n", philo->id);
		sem_post(philo->sem);
		sem_post(philo->table->death);
		sem_wait(philo->table->print);
		sem_wait(philo->sem);
		if (philo->sim_end)
		{
			printf("detected sim end: %d\n", philo->id);
			sem_post(philo->table->print);
			p_sleep(1);
			sem_post(philo->sem);
			sem_post(philo->sem);
			return ;
		}
		philo->dead = true;
		sem_post(philo->sem);
	}
	else
		sem_post(philo->sem);
	p_sleep(1);
}

void	*monitor_philo(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	if (!philo)
		return (NULL);
	philo->time_since_meal = 0;
	sem_wait(philo->table->sync_start);
	sem_post(philo->table->sync_start);
	philo->start_time = get_time_ms();
	sem_post(philo->sem);
	p_sleep(philo->table->time_to_die);
	while (1)
	{
		philo_starving(philo);
		sem_wait(philo->sem);
		if (philo->dead)
		{
			sem_post(philo->sem);
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
	if (timestamp(philo->start_time) - philo->time_since_meal > philo->table->time_to_die && philo->dead)
	{
		sem_wait(philo->table->death);
		printf("\033[1;31m\033[1m%lu\t%d died\033[0m\n", timestamp(philo->start_time), philo->id);
		philo->sim_end = false;
		philo->dead = false;
		sem_post(philo->sem);
		sem_post(philo->table->print);
		return (NULL);
	}
	philo->dead = true;
	philo->sim_end = true;
	sem_post(philo->sem);
	p_sleep(10);
	printf("philo check 2: %d\n", philo->id);
	return (NULL);
}
