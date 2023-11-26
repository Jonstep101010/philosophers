/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschwabe <jschwabe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 14:59:02 by jschwabe          #+#    #+#             */
/*   Updated: 2023/11/26 14:28:42 by jschwabe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"
#include "struct.h"
#include <semaphore.h>

#include <signal.h>
void	*philo_routine(t_philo *philo)
{
	while (philo->dead == false)
	{
		sem_post(philo->sem);
		eating(philo);
		sleeping(philo);
		thinking(philo);
		sem_wait(philo->sem);
	}
	sem_post(philo->death);
	return (NULL);
}
