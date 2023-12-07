/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sim.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschwabe <jschwabe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 16:46:29 by jschwabe          #+#    #+#             */
/*   Updated: 2023/12/07 09:25:27 by jschwabe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
static bool	philo_starving(t_philo *philo)
{
	pthread_mutex_lock(&philo->table->death);
	if (philo->meal_count == 0)
	{
		pthread_mutex_unlock(&philo->table->death);
		return (false);
	}
	if (timestamp(philo->start_time)
		- philo->time_since_meal > philo->table->time_to_die)
	{
		printf("\033[1;31m\033[1m%lu\t%d died\033[0m\n", timestamp(philo->start_time), philo->id);
		philo->table->dead = true;
		pthread_mutex_unlock(&philo->table->death);
		return (true);
	}
	pthread_mutex_unlock(&philo->table->death);
	return (false);
}

static bool	philos_have_eaten(t_philo *philo, int *tmp_id)
{
	pthread_mutex_lock(&philo->table->death);
	if (philo->meal_count == 0)
	{
		*tmp_id = philo->id;
		philo = philo->next;
		while (philo->id != *tmp_id)
		{
			if (philo->meal_count != 0)
				break ;
			philo = philo->next;
		}
		if (philo->id == *tmp_id)
		{
			pthread_mutex_unlock(&philo->table->death);
			return (true);
		}
	}
	pthread_mutex_unlock(&philo->table->death);
	return (false);
}

void	simulation(t_table *table)
{
	t_philo	*philo;
	t_philo	**list;
	int		i;

	list = table->philo_list;
	philo = list[0];
	i = -1;
	pthread_mutex_lock(&table->death);
	while (++i < table->num_philos)
		if (pthread_create(&list[i]->thread_id, 0, philosopher, list[i]) == -1)
			return ;
	table->start_time = get_time_ms();
	pthread_mutex_unlock(&table->death);
	while (1)
	{
		if (philo_starving(philo) || philos_have_eaten(philo, &i))
		{
			break ;
		}
		philo = philo->next;
	}
	i = -1;
	while (++i < table->num_philos)
		pthread_join(list[i]->thread_id, NULL);
}
