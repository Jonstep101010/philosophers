/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschwabe <jschwabe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/26 15:00:20 by jschwabe          #+#    #+#             */
/*   Updated: 2023/11/28 17:04:27 by jschwabe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"
#include <semaphore.h>
#include <unistd.h>

	// if (philo == NULL)
	// 	return ;
	// sem_wait(philo->var_lock);
	// time_since_last_meal = get_ms(philo->start_time) - philo->last_meal;
	// if (time_since_last_meal >= philo->philo_var.time_to_die)
	// {
	// 	sem_post(philo->var_lock);
	// 	sem_wait(philo->print_lock);
	// 	printf("%ld %d died\n", get_ms(philo->start_time), philo->id);
	// 	sem_wait(philo->var_lock);
	// 	philo->isdead = true;
	// 	sem_post(philo->var_lock);
	// 	sem_post(philo->sim_end);
	// }
	// else
	// 	sem_post(philo->var_lock);

bool	philo_starving(t_philo *philo)
{
	if (!philo)
		exit(0);
	time_t	philo_time_since_meal = timestamp(philo->start_time) - philo->time_since_meal;
	if (philo_time_since_meal >= philo->table->time_to_die && !philo->dead)
	{
		sem_wait(philo->sem);
		if (philo->dead)
			return (true);
		sem_wait(philo->table->print);
		sem_post(philo->sem);
		sem_post(philo->table->death);
		printf("\033[1;31m\033[1m%lu\t%d died\033[0m\n", timestamp(philo->start_time), philo->id);
		return (true);
	}
	if (philo->dead)
		return (true);
	sem_post(philo->sem);
	return (false);
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
		if (!philo)
			exit(0);
		if (philo_starving(philo))
		{
			sem_post(philo->sem);
			return (NULL);
		}
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
	// sem_wait(philo->sem);
	// philo->dead = true;
	// sem_post(philo->table->print);
	// sem_post(philo->sem);
	// return (NULL);
	exit(0);
}
