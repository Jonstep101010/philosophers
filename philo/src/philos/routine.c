/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschwabe <jschwabe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 14:59:02 by jschwabe          #+#    #+#             */
/*   Updated: 2023/12/03 17:54:33 by jschwabe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static bool	philo_is_dead(t_philo *philo)
{
	bool	dead;

	dead = false;
	pthread_mutex_lock(&philo->table->death);
	dead = philo->table->dead;
	pthread_mutex_unlock(&philo->table->death);
	return (dead);
}

void	philo_first_action(t_philo *philo)
{
	if (philo->id % 2 == 0)
	{
		sleeping(philo);
		if (philo_is_dead(philo))
			return ;
	}
	else
	{
		eating(philo);
		if (philo_is_dead(philo))
			return ;
		sleeping(philo);
	}
	return ;
}

void	*philo_routine(t_philo *philo)
{
	while (1)
	{
		if (philo_is_dead(philo) || !eating(philo))
			break ;
		if (!philo_is_dead(philo))
			sleeping(philo);
		if (!philo_is_dead(philo))
			thinking(philo);
	}
	return (NULL);
}

void	*philosopher(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	if (!philo)
		return (NULL);
	pthread_mutex_lock(&philo->table->death);
	philo->time_since_meal = timestamp(philo->start_time);
	philo->start_time = get_time_ms();
	pthread_mutex_unlock(&philo->table->death);
	philo_first_action(philo);
	if (philo_is_dead(philo))
		return (NULL);
	philo_routine(philo);
	return (NULL);
}
