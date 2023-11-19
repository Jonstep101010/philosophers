/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_actions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschwabe <jschwabe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 12:38:31 by jschwabe          #+#    #+#             */
/*   Updated: 2023/11/15 20:08:14 by jschwabe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static bool	select_forks(t_philo *philo)
{
	if (philo->id == philo->table->num_philos)
	{
		pthread_mutex_lock(&philo->right);
		print_message(philo, "has taken a fork");
		if (philo->table->num_philos == 1)
		{
			pthread_mutex_unlock(&philo->right);
			return (false);
		}
		pthread_mutex_lock(philo->left);
		print_message(philo, "has taken a fork");
	}
	else
	{
		pthread_mutex_lock(philo->left);
		print_message(philo, "has taken a fork");
		pthread_mutex_lock(&philo->right);
		print_message(philo, "has taken a fork");
	}
	return (true);
}

static bool	philo_is_dead(t_philo *philo)
{
	bool	dead;

	pthread_mutex_lock(&philo->table->death);
	dead = philo->table->dead;
	pthread_mutex_unlock(&philo->table->death);
	return (dead);
}

bool	eating(t_philo *philo)
{
	if (philo_is_dead(philo))
		return (false);
	if (philo)
	{
		if (!select_forks(philo))
			return (false);
		else
		{
			pthread_mutex_lock(&philo->table->death);
			philo->time_since_meal = timestamp(philo->start_time);
			pthread_mutex_unlock(&philo->table->death);
		}
		pthread_mutex_lock(&philo->table->death);
		philo->meal_count--;
		pthread_mutex_unlock(&philo->table->death);
		pthread_mutex_unlock(philo->left);
		pthread_mutex_unlock(&philo->right);
		print_message(philo, "is eating");
		p_sleep(philo->table->time_to_eat);
	}
	if (philo->meal_count == 0)
		return (false);
	return (true);
}

void	thinking(t_philo *philo)
{
	if (philo && !philo_is_dead(philo))
		print_message(philo, "is thinking");
}

void	sleeping(t_philo *philo)
{
	if (philo && !philo_is_dead(philo))
	{
		print_message(philo, "is sleeping");
		p_sleep(philo->table->time_to_sleep);
	}
}
