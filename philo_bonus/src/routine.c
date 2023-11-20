/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschwabe <jschwabe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 14:59:02 by jschwabe          #+#    #+#             */
/*   Updated: 2023/11/20 18:39:42 by jschwabe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

/**
 * @brief checks if philo has died
 * should have same memory as forked_philo
 */
void	*monitor_philo(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	if (!philo)
		return (NULL);
	philo->dead = false;
	// run loop unlocking philo->sem
	// if death at table, set philo->dead to true
		// find out using "/death"
	// use sem_wait(philo->sem) to lock philo
	// use sem_post(philo->sem) to unlock philo
	while (1)
	{
		sem_wait(philo->sem);
		if (philo_starving(philo))
		{
			sem_post(philo->table->death);
			philo->dead = true;
		}
		sem_post(philo->sem);
	}
	return (NULL);
}

/**
 * @brief frees philo memory
 */
void	*cleanup_philo(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	if (!philo)
		return (NULL);
	// if (philo->dead == false)
	// 	sem_post(philo->table->sim_end);
	if (philo->dead)
	{
		deconstruct(philo->table);
		sem_unlink("/forks");
		sem_unlink("/death");
		sem_unlink("/print");
		sem_unlink("/sim_end");
		sem_unlink("/req_meals");
	}
	return (NULL);
}

void	*forked_philo(void *arg)
{
	t_philo		*philo;
	pthread_t	monitor;
	pthread_t	cleanup;

	philo = (t_philo *)arg;
	if (!philo)
		return (NULL);
	if (pthread_create(&monitor, NULL, monitor_philo, philo) != 0)
		return (NULL);
	if (pthread_create(&cleanup, NULL, cleanup_philo, philo) != 0)
		return (NULL);
	// sem_wait(philo->sem);
	philo_routine(philo);
	if (pthread_join(monitor, NULL) != 0)
		perror("pthread_join monitor");
	if (pthread_join(cleanup, NULL) != 0)
		perror("pthread_join cleanup");
	return (NULL);
}

void	*philo_routine(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	if (!philo)
		return (NULL);
	if (philo->id % 2 == 0)
		sleeping(philo);
	while (philo->dead == false)
	{
		sem_wait(philo->sem);
		if (!eating(philo))
			break ;
		sleeping(philo);
		thinking(philo);
		sem_post(philo->sem);
	}
	return (NULL);
}
