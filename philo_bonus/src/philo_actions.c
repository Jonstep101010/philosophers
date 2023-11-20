/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_actions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschwabe <jschwabe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 12:38:31 by jschwabe          #+#    #+#             */
/*   Updated: 2023/11/20 13:03:54 by jschwabe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

static bool	select_forks(t_philo *philo)
{
	sem_wait(philo->table->forks);
	print_message(philo, "has taken a fork");
	print_message(philo, "has taken a fork");
	if (philo->table->num_philos == 1)
	{
		sem_post(philo->table->forks);
		p_sleep(philo->table->time_to_eat + 10);
		return (false);
	}
	return (true);
}

bool	eating(t_philo *philo)
{
	if (philo->dead)
		return (false);
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
	if (philo && !(philo->dead))
		print_message(philo, "is thinking");
}

void	sleeping(t_philo *philo)
{
	if (philo && !(philo->dead))
	{
		print_message(philo, "is sleeping");
		p_sleep(philo->table->time_to_sleep);
	}
}
