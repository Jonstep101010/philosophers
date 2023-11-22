/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_actions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschwabe <jschwabe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 12:38:31 by jschwabe          #+#    #+#             */
/*   Updated: 2023/11/22 17:58:49 by jschwabe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"
#include <semaphore.h>

	// if (philo->table->num_philos == 1)
	// {
	// 	sem_post(philo->table->forks);
	// 	sem_post(philo->sem);
	// 	p_sleep(philo->table->time_to_eat + 10);
	// 	return (false);
	// }
static bool	select_forks(t_philo *philo)
{
	sem_wait(philo->sem);
	if (philo->dead)
	{
		sem_post(philo->sem);
		return (false);
	}
	sem_wait(philo->table->forks);
	print_message(philo, "has taken a fork");
	print_message(philo, "has taken a fork");
	sem_post(philo->sem);
	return (true);
}

bool	eating(t_philo *philo)
{
	sem_wait(philo->sem);
	if (philo->dead)
		return (false);
	sem_post(philo->sem);
	if (philo)
	{
		if (!select_forks(philo))
			return (false);
		else
		{
			philo->time_since_meal = timestamp(philo->start_time);
			print_message(philo, "is eating");
			p_sleep(philo->table->time_to_eat);
			sem_post(philo->table->forks);
		}
	}
	if (philo->meal_count == 0)
		return (false);
	return (true);
}

void	thinking(t_philo *philo)
{
	sem_wait(philo->sem);
	if (philo && !(philo->dead))
		print_message(philo, "is thinking");
	sem_post(philo->sem);
}

void	sleeping(t_philo *philo)
{
	sem_wait(philo->sem);
	if (philo && !(philo->dead))
	{
		print_message(philo, "is sleeping");
		p_sleep(philo->table->time_to_sleep);
	}
	sem_post(philo->sem);
}
