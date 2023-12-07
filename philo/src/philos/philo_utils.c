/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschwabe <jschwabe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 12:38:31 by jschwabe          #+#    #+#             */
/*   Updated: 2023/12/07 08:56:04 by jschwabe         ###   ########.fr       */
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

bool	eating(t_philo *philo)
{
	if (philo)
	{
		if (!select_forks(philo))
			return (false);
		else
		{
			pthread_mutex_lock(&philo->table->death);
			philo->time_since_meal = timestamp(philo->start_time);
			pthread_mutex_unlock(&philo->table->death);
			print_message(philo, "is eating");
			pthread_mutex_lock(&philo->table->death);
			philo->meal_count--;
			pthread_mutex_unlock(&philo->table->death);
			p_sleep(philo->table->time_to_eat);
			pthread_mutex_unlock(philo->left);
			pthread_mutex_unlock(&philo->right);
		}
	}
	if (philo->meal_count == 0)
		return (false);
	return (true);
}

void	print_message(t_philo *philo, char *msg)
{
	pthread_mutex_lock(&philo->table->printing);
	pthread_mutex_lock(&philo->table->death);
	if (!philo->table->dead)
		printf("%lu\t%d %s\n", timestamp(philo->start_time), philo->id, msg);
	pthread_mutex_unlock(&philo->table->death);
	pthread_mutex_unlock(&philo->table->printing);
}

void	sleeping(t_philo *philo)
{
	if (philo_is_dead(philo))
		return ;
	print_message(philo, "is sleeping");
	p_sleep(philo->table->time_to_sleep);
}

void	thinking(t_philo *philo)
{
	if (philo_is_dead(philo))
		return ;
	print_message(philo, "is thinking");
}
