/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   forked_process.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschwabe <jschwabe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 11:43:09 by jschwabe          #+#    #+#             */
/*   Updated: 2023/11/25 17:35:26 by jschwabe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"
#include <semaphore.h>

bool	philo_starving(t_philo *philo)
{
	sem_wait(philo->table->print);
	sem_post(philo->sem);
	if (timestamp(philo->start_time)
		- philo->time_since_meal > philo->table->time_to_die)
	{
		printf("%lu %d died\n", timestamp(philo->start_time), philo->id);
		philo->dead = true;
		sem_wait(philo->sem);
		// sem_post(philo->sem);
		return (true);
	}
	sem_wait(philo->sem);
	sem_post(philo->table->print);
	return (false);
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
		// supervise philo, check if dead
		philo_starving(philo);
		sem_wait(philo->sem);
		if (philo->dead)
			break;
		sem_post(philo->sem);
	}
	sem_post(philo->table->death);
	sem_post(philo->table->death);
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
	sem_wait(philo->sem);
	philo_first_action(philo);
	sem_post(philo->sem);// @audit
	philo_routine(philo);
	sem_post(philo->sem);
	pthread_detach(monitor);
	pthread_detach(cleanup);
	sem_close(philo->sem);
	return (NULL);
}
