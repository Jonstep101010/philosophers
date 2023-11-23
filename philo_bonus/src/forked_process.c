/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   forked_process.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschwabe <jschwabe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 11:43:09 by jschwabe          #+#    #+#             */
/*   Updated: 2023/11/23 19:37:36 by jschwabe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"
#include <fcntl.h>
#include <pthread.h>
#include <semaphore.h>

static bool	philo_starving(t_philo *philo)
{
	sem_wait(philo->table->print);
	sem_wait(philo->table->time_since_meal);
	if (timestamp(philo->start_time)
		- philo->time_since_meal
			> philo->table->time_to_die)
	{
		philo->dead = true;
		printf("%lu %d died\n", timestamp(philo->start_time), philo->id);
		sem_post(philo->table->death);
		sem_wait(philo->sem);
		return (true);
	}
	sem_post(philo->table->time_since_meal);
	sem_post(philo->table->print);
	return (false);
}

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
	philo->time_since_meal = 0;
	sem_wait(philo->table->sync_start);
	sem_post(philo->table->sync_start);
	philo->start_time = get_time_ms();
	sem_post(philo->sem);
	// run loop unlocking philo->sem
	// if death at table, set philo->dead to true
		// find out using "/death"
	// use sem_wait(philo->sem) to lock philo
	// use sem_post(philo->sem) to unlock philo
	while (1)
	{
		// sem_wait(philo->sem);
		// sem_wait(philo->table->death);
		if (philo_starving(philo))
		{
			// sem_post(philo->table->death);
			sem_wait(philo->sem);
			// sem_post(philo->table->sim_end);
			break;
		}
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
	// sem_wait(philo->table->death);
	sem_wait(philo->table->death);
	sem_close(philo->sem);
	sem_unlink(philo->sem_name);
	// sem_post(philo->table->print);
	// sem_post(philo->table->sim_end);
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
	// sem_close(philo->table->sim_end);
	// sim_end = sem_open("/sim_end", O_RDWR);
	// philo->table->sim_end = sim_end;
	if (pthread_create(&monitor, NULL, monitor_philo, philo) != 0)
		return (NULL);
	if (pthread_create(&cleanup, NULL, cleanup_philo, philo) != 0)
		return (NULL);
	// sem_wait(philo->sem);
	philo_routine(philo);
	if (pthread_join(monitor, NULL) != 0)
		perror("pthread_join monitor");
	pthread_detach(cleanup);
	if (pthread_join(cleanup, NULL) == 0)
		perror("pthread_join cleanup");
	return (NULL);
}
