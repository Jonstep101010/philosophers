/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   forked_process.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschwabe <jschwabe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 11:43:09 by jschwabe          #+#    #+#             */
/*   Updated: 2023/11/27 15:15:35 by jschwabe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"
#include <semaphore.h>

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
	sem_post(philo->sem);
	philo_first_action(philo);
	sem_wait(philo->sem);
	// printf("child thread monitor %lu\t cleanup %lu\n", monitor, cleanup);
	philo_routine(philo);
	sem_post(philo->sem);
	printf("%d\n", getpid());
	// sem_post(philo->sem);
	// pthread_detach(monitor);
	// pthread_detach(cleanup);
	pthread_join(monitor, NULL);
	pthread_join(cleanup, NULL);
	// if (pthread_join(monitor, NULL) != 0)
	// 	return (printf("error monitor\n"), NULL);
	// if (pthread_join(cleanup, NULL) != 0)
	// 	return (printf("error monitor\n"), NULL);
	printf("proceeding to close...%d\n", philo->id);
	sem_close(philo->sem);
	// sem_close(philo->death);
	return (NULL);
}
