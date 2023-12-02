/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_actions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschwabe <jschwabe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 12:38:31 by jschwabe          #+#    #+#             */
/*   Updated: 2023/12/02 18:21:44 by jschwabe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	eating(t_philo *philo)
{
	if (!philo || !philo->sem)
		return ;
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
