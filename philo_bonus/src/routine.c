/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschwabe <jschwabe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 14:59:02 by jschwabe          #+#    #+#             */
/*   Updated: 2023/11/28 10:09:45 by jschwabe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"
#include "struct.h"
#include <semaphore.h>
#include <signal.h>

bool	philo_first_action(t_philo *philo)
{
	if (philo->id % 2 == 0)
	{
		if (!sleeping(philo))
			return (false);
	}
	else
	{
		if (!eating(philo))
			return (false);
		if (!sleeping(philo))
			return (false);
	}
	return (true);
}

void	*philo_routine(t_philo *philo)
{
	while (philo->dead == false)
	{
		sem_post(philo->sem);
		if (!eating(philo))
			break ;
		if (!sleeping(philo))
			break ;
		if (!thinking(philo))
			break ;
		sem_wait(philo->sem);
	}
	sem_post(philo->sem);
	return (NULL);
}
