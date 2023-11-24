/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_actions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschwabe <jschwabe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 12:38:31 by jschwabe          #+#    #+#             */
/*   Updated: 2023/11/24 20:30:33 by jschwabe         ###   ########.fr       */
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
// bool	select_forks(t_philo *philo)
// {
// 	return (false);
// }

bool	eating(t_philo *philo)
{
	sem_wait(philo->table->forks);
	if (philo->dead)
	{
		// sem_post(philo->table->forks);
		return (false);
	}
	print_message(philo, "has taken a fork");
	print_message(philo, "has taken a fork");
	sem_wait(philo->sem);
	philo->time_since_meal = timestamp(philo->start_time);
	sem_post(philo->sem);
	print_message(philo, "is eating");
	sem_post(philo->table->forks);
	p_sleep(philo->table->time_to_eat);
	return (true);
}

void	thinking(t_philo *philo)
{
	sem_wait(philo->sem);
	print_message(philo, "is thinking");
	sem_post(philo->sem);
}

void	sleeping(t_philo *philo)
{
	sem_wait(philo->sem);
	print_message(philo, "is sleeping");
	p_sleep(philo->table->time_to_sleep);
	sem_post(philo->sem);
}
