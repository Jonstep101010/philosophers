/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   forked_process.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschwabe <jschwabe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 11:43:09 by jschwabe          #+#    #+#             */
/*   Updated: 2023/11/24 15:54:37 by jschwabe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"
#include <fcntl.h>
#include <pthread.h>
#include <semaphore.h>

static bool	philo_starving(t_philo *philo)
{

	if (timestamp(philo->start_time)
		- philo->time_since_meal
			> philo->table->time_to_die)
	{
		// do something
		return (true);
	}
	return (false);
}

void	*monitor_philo(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	if (!philo)
		return (NULL);
	philo->dead = false;
	// communicate death using "/death"
	philo->time_since_meal = 0;
	sem_post(philo->table->sync_start);
	philo->start_time = get_time_ms();
	sem_post(philo->table->print);
	sem_post(philo->sem);
	while (1)
	{
		if (philo_starving(philo))
			break;
	}
	return (NULL);
}

void	*cleanup_philo(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	if (!philo)
		return (NULL);
	sem_wait(philo->table->death);
	sem_post(philo->sem);
	sem_close(philo->sem);
	sem_unlink(philo->sem_name);
	sem_post(philo->table->sim_end);
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
	pthread_detach(cleanup);
	philo_routine(philo);
	if (pthread_join(monitor, NULL) != 0)
		perror("pthread_join monitor");
	// if (pthread_join(cleanup, NULL) != 0)
	// 	perror("pthread_join cleanup");
	return (NULL);
}
