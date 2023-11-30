/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   forked_process.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschwabe <jschwabe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 11:43:09 by jschwabe          #+#    #+#             */
/*   Updated: 2023/11/30 14:40:49 by jschwabe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"
#include "struct.h"
#include <semaphore.h>
#include <stdio.h>

void	*forked_cleanup(t_table *table)
{
	if (!table)
		return (NULL);
	deconstruct(table);
	// sem_unlink("/forks");
	// sem_unlink("/death");
	// sem_unlink("/print");
	// sem_unlink("/sim_end");
	// sem_unlink("/sync_start");
	// sem_unlink("/req_meals");
	return (NULL);
}

void	*forked_philo(t_philo *philo, t_table *table)
{
	pthread_t	monitor;
	pthread_t	cleanup;

	if (!philo || !table)
		exit(0);
	if (pthread_create(&monitor, NULL, monitor_philo, philo) != 0)
		return (NULL);
	if (pthread_create(&cleanup, NULL, cleanup_philo, philo) != 0)
		return (NULL);
	sem_wait(philo->sem);
	sem_post(philo->sem);
	philo_first_action(philo);
	sem_wait(philo->sem);
	philo_routine(philo);
	if (pthread_detach(monitor) != 0)
		printf("Error joining monitor thread\n");
	if (pthread_detach(cleanup) != 0)
		printf("Error detaching cleanup thread\n");
	exit(0);
}
