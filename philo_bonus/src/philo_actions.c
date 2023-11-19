/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_actions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschwabe <jschwabe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 12:38:31 by jschwabe          #+#    #+#             */
/*   Updated: 2023/11/19 13:33:55 by jschwabe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

static bool	select_forks(t_philo *philo)
{
	// if (philo->id == philo->table->num_philos)
	// {
		// pthread_mutex_lock(&philo->right);
	sem_wait(philo->table->forks);
	print_message(philo, "has taken a fork");
	if (philo->table->num_philos == 1)
	{
		// pthread_mutex_unlock(&philo->right);
		sem_post(philo->table->forks);
		p_sleep(philo->table->time_to_eat + 10);
		return (false);
	}
		// pthread_mutex_lock(philo->left);
		// sem_wait(philo->table->forks);
		// print_message(philo, "has taken a fork");
	// }
	// else
	// {
	// 	// pthread_mutex_lock(philo->left);
	// 	print_message(philo, "has taken a fork");
	// 	// pthread_mutex_lock(&philo->right);
	// 	print_message(philo, "has taken a fork");
	// }
	return (true);
}

// @warning no death check! @audit
static bool	philo_is_dead(t_philo *philo)
{
	bool	dead;

	// dead = false;
	// pthread_mutex_lock(&philo->table->death);
	// sem_wait(philo->table->death);
	dead = philo->table->dead;
	// pthread_mutex_unlock(&philo->table->death);
	// sem_post(philo->table->death);
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
			// pthread_mutex_lock(&philo->table->death);
			sem_wait(philo->table->death);
			philo->time_since_meal = timestamp(philo->start_time);
			// pthread_mutex_unlock(&philo->table->death);
			sem_post(philo->table->death);
		}
		// pthread_mutex_lock(&philo->table->death);
		sem_wait(philo->table->death);
		philo->meal_count--;
		// pthread_mutex_unlock(&philo->table->death);
		sem_post(philo->table->death);
		// pthread_mutex_unlock(philo->left);
		p_sleep(philo->table->time_to_eat);
		sem_post(philo->table->forks);
		// pthread_mutex_unlock(&philo->right);
		// sem_post(philo->table->forks);
		print_message(philo, "is eating");
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
