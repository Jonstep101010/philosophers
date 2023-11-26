/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_actions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschwabe <jschwabe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 12:38:31 by jschwabe          #+#    #+#             */
/*   Updated: 2023/11/26 15:09:52 by jschwabe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"
#include <semaphore.h>

bool	eating(t_philo *philo)
{
	sem_wait(philo->table->forks);
	sem_wait(philo->sem);
	if (philo->dead)
		return (false);
	sem_post(philo->sem);
	print_message(philo, "has taken a fork");
	print_message(philo, "has taken a fork");
	sem_wait(philo->sem);
	philo->time_since_meal = timestamp(philo->start_time);
	sem_post(philo->sem);
	print_message(philo, "is eating");
	p_sleep(philo->table->time_to_eat);
	sem_post(philo->table->forks);
	return (true);
}

void	thinking(t_philo *philo)
{
	print_message(philo, "is thinking");
}

void	sleeping(t_philo *philo)
{
	print_message(philo, "is sleeping");
	p_sleep(philo->table->time_to_sleep);
}
