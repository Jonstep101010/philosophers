/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschwabe <jschwabe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 14:59:02 by jschwabe          #+#    #+#             */
/*   Updated: 2023/11/13 15:42:07 by jschwabe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	take_fork(t_philo *philo)
{
	if (philo)
		print_message(philo, "has taken a fork");
}

static void	select_forks(t_philo *philo)
{
	if (philo->id == philo->table->num_philos)
	{
		pthread_mutex_lock(&philo->right);
		take_fork(philo);
		pthread_mutex_lock(philo->left);
		take_fork(philo);
	}
	else
	{
		pthread_mutex_lock(philo->left);
		take_fork(philo);
		pthread_mutex_lock(&philo->right);
		take_fork(philo);
	}
}

static void	eating(t_philo *philo)
{
	if (philo)
	{
		select_forks(philo);
		philo->time_since_meal = timestamp(philo->table);
		print_message(philo, "is eating");
		p_sleep(philo->table->time_to_eat);
		pthread_mutex_unlock(philo->left);
		pthread_mutex_unlock(&philo->right);
	}
}

static void	thinking(t_philo *philo)
{
	if (philo && !philo_is_dead(philo))
	{
		print_message(philo, "is thinking");
	}
}

static void	sleeping(t_philo *philo)
{
	if (philo && !philo_is_dead(philo))
	{
		print_message(philo, "is sleeping");
		p_sleep(philo->table->time_to_sleep);
	}
}

void	*philo_routine(void *arg)
{
	t_philo	*philo;
	bool	dead;

	philo = (t_philo *)arg;
	if (!philo)
		return (NULL);
	if (philo->id % 2 == 0)
	{
		sleeping(philo);
		p_sleep(philo->table->time_to_sleep);
	}
	while (1)
	{
		pthread_mutex_lock(&philo->table->death);
		dead = philo->table->dead;
		pthread_mutex_unlock(&(philo->table->death));
		if (dead)
			break ;
		// eat
		eating(philo);
		// sleep
		sleeping(philo);
		// think
		thinking(philo);
	}
	return (NULL);
}
