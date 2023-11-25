/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_actions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschwabe <jschwabe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 12:38:31 by jschwabe          #+#    #+#             */
/*   Updated: 2023/11/25 20:02:55 by jschwabe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

bool	eating(t_philo *philo)
{
	sem_wait(philo->table->forks);
	sem_post(philo->sem);
	if (philo->dead)
		return (false);
	print_message(philo, "has taken a fork");
	print_message(philo, "has taken a fork");
	philo->time_since_meal = timestamp(philo->start_time);
	print_message(philo, "is eating");
	sem_wait(philo->sem);
	sem_post(philo->table->forks);
	p_sleep(philo->table->time_to_eat);
	return (true);
}

void	thinking(t_philo *philo)
{
	sem_post(philo->sem);
	print_message(philo, "is thinking");
	sem_wait(philo->sem);
}

void	sleeping(t_philo *philo)
{
	sem_post(philo->sem);
	print_message(philo, "is sleeping");
	p_sleep(philo->table->time_to_sleep);
	sem_wait(philo->sem);
}

void	philo_first_action(t_philo *philo)
{
	if (philo->id % 2 == 0)
	{
		sleeping(philo);
	}
	else
	{
		eating(philo);
		sleeping(philo);
	}
}
