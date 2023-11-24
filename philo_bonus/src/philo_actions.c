/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_actions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschwabe <jschwabe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 12:38:31 by jschwabe          #+#    #+#             */
/*   Updated: 2023/11/24 15:57:32 by jschwabe         ###   ########.fr       */
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
	sem_wait(philo->table->forks);
	print_message(philo, "has taken a fork");
	print_message(philo, "has taken a fork");
	return (true);
}

bool	eating(t_philo *philo)
{
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
			return (true);
		}
	}
	return (false);
	// if (philo->meal_count == 0)
	// 	return (false);
}

void	thinking(t_philo *philo)
{
	if (!philo)
		return ;
	print_message(philo, "is thinking");
}

void	sleeping(t_philo *philo)
{
	if (!philo)
		return ;
	print_message(philo, "is sleeping");
	p_sleep(philo->table->time_to_sleep);
}
