/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschwabe <jschwabe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 14:59:02 by jschwabe          #+#    #+#             */
/*   Updated: 2023/12/02 17:37:56 by jschwabe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"
#include "struct.h"
#include <semaphore.h>
#include <signal.h>

static bool	check_death(t_philo *philo)
{
	if (timestamp(philo->start_time) <= philo->table->time_to_die + 5)
	{
		p_sleep(5);
		sem_wait(philo->sem);
		if (philo->dead == true)
		{
			sem_post(philo->sem);
			p_sleep(5);
			return (false);
		}
		sem_post(philo->sem);
	}
	return (true);
}

void	philo_first_action(t_philo *philo)
{
	if (!philo || !philo->sem)
		return ;
	if (philo->id % 2 != 0)
	{
		print_message(philo, "is sleeping");
		if (!check_death(philo))
			return ;
		p_sleep(philo->table->time_to_sleep);
	}
	else
	{
		eating(philo);
		if (!check_death(philo))
			return ;
		print_message(philo, "is sleeping");
		if (!check_death(philo))
			return ;
		p_sleep(philo->table->time_to_sleep);
	}
}

void	*philo_routine(t_philo *philo)
{
	if (!philo || !philo->sem)
		return (NULL);
	while (philo->dead == false)
	{
		sem_post(philo->sem);
		eating(philo);
		print_message(philo, "is sleeping");
		p_sleep(philo->table->time_to_sleep);
		print_message(philo, "is thinking");
		p_sleep(1);
		sem_wait(philo->sem);
	}
	sem_post(philo->sem);
	return (NULL);
}
