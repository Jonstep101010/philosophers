/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschwabe <jschwabe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 14:59:02 by jschwabe          #+#    #+#             */
/*   Updated: 2023/11/24 20:33:50 by jschwabe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"
#include <semaphore.h>

#include <signal.h>
void	*philo_routine(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	if (!philo)
		return (NULL);
	sem_wait(philo->sem);
	sem_post(philo->sem);
	if (philo->id % 2 == 0)
		sleeping(philo);
	while (1)
	{
		if (!eating(philo))
			break;
		// sem_wait(philo->table->death);
		if (philo->dead)
		{
			// sem_post(philo->sem);
			// sem_post(philo->table->death);
			break ;
		}
		// sem_post(philo->table->death);
		sleeping(philo);
		thinking(philo);
	}
	return (NULL);
}
