/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sim.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschwabe <jschwabe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 16:46:29 by jschwabe          #+#    #+#             */
/*   Updated: 2023/11/14 20:56:55 by jschwabe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static bool	philo_starving(t_philo *philo)
{
	if (philo->meal_count == 0)
		return (false);
	if (timestamp(philo->table) - philo->time_since_meal
		> philo->table->time_to_die)
	{
		print_message(philo, "has died");
		pthread_mutex_lock(&philo->table->death);
		philo->table->dead = true;
		pthread_mutex_unlock(&philo->table->death);
		pthread_mutex_unlock(&philo->mutex);
		return (true);
	}
	return (false);
}

static bool	philos_have_eaten(t_philo *philo, int *tmp_id)
{
	if (philo->meal_count == 0)
	{
		*tmp_id = philo->id;
		philo = philo->next;
		while (philo->id != *tmp_id)
		{
			if (philo->meal_count != 0)
				break;
			philo = philo->next;
		}
		if (philo->id == *tmp_id)
			return (true);
	}
	return (false);
}

void	simulation(t_table *table)
{
	t_philo	*philo;
	t_philo	**list;
	list = table->philo_list;
	philo = list[0];
	int	i;

	i = -1;
	while (++i < table->num_philos)
		pthread_create(&list[i]->thread_id, NULL, philo_routine, list[i]);
	i = 0;
	while (1)
	{
		pthread_mutex_lock(&philo->mutex);
		if (philo_starving(philo) || philos_have_eaten(philo, &i))
			break;
		pthread_mutex_unlock(&philo->mutex);
		philo = philo->next;
	}
	i = -1;
	while (++i < table->num_philos)
		pthread_join(list[i]->thread_id, NULL);
}
