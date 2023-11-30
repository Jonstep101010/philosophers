/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_actions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschwabe <jschwabe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 12:38:31 by jschwabe          #+#    #+#             */
/*   Updated: 2023/11/30 16:21:14 by jschwabe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"
#include <semaphore.h>

void	eating(t_philo *philo)
{
	if (philo->table->num_philos == 1)
	{
		print_message(philo, "has taken a fork");
		p_sleep(philo->table->time_to_die + 10);
		return ;
	}
	sem_wait(philo->table->forks);
	print_message(philo, "has taken a fork");
	print_message(philo, "has taken a fork");
	print_message(philo, "is eating");
	sem_wait(philo->sem);
	philo->time_since_meal = timestamp(philo->start_time);
	philo->meal_count++;
	if (philo->meal_count == philo->table->meals_to_eat)
		sem_post(philo->table->req_meals);
	sem_post(philo->sem);
	p_sleep(philo->table->time_to_eat);
	sem_post(philo->table->forks);
}

void	thinking(t_philo *philo)
{
	print_message(philo, "is thinking");
	p_sleep(1);
}

void	sleeping(t_philo *philo)
{
	print_message(philo, "is sleeping");
	p_sleep(philo->table->time_to_sleep);
}
