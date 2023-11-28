/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_actions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschwabe <jschwabe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 12:38:31 by jschwabe          #+#    #+#             */
/*   Updated: 2023/11/28 11:01:07 by jschwabe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"
#include <semaphore.h>

bool	print_eating(t_philo *philo)
{
	if (!print_message(philo, "has taken a fork"))
		return (false);
	if (!print_message(philo, "has taken a fork"))
		return (false);
	if (!print_message(philo, "is eating"))
		return (false);
	return (true);
}

bool	eating(t_philo *philo)
{
	sem_wait(philo->sem);
	if (philo->table->num_philos == 1)
	{
		sem_post(philo->sem);
		print_message(philo, "has taken a fork");
		p_sleep(philo->table->time_to_die + 10);
		return (false);
	}
	sem_post(philo->sem);
	sem_wait(philo->sem);
	if (philo->dead)
	{
		sem_post(philo->sem);
		return (false);
	}
	sem_post(philo->sem);
	sem_wait(philo->table->forks);
	if (!print_eating(philo))
		return (false);
	p_sleep(philo->table->time_to_eat);
	sem_wait(philo->sem);
	if (philo->dead)
	{
		sem_post(philo->sem);
		return (false);
	}
	philo->time_since_meal = timestamp(philo->start_time);
	sem_post(philo->sem);
	sem_post(philo->table->forks);
	return (true);
}

bool	thinking(t_philo *philo)
{
	if (!print_message(philo, "is thinking"))
		return (false);
	return (true);
}

bool	sleeping(t_philo *philo)
{
	if (!print_message(philo, "is sleeping"))
		return (false);
	p_sleep(philo->table->time_to_sleep);
	return (true);
}
