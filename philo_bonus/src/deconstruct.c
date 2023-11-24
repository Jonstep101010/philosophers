/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deconstruct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschwabe <jschwabe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 12:44:03 by jschwabe          #+#    #+#             */
/*   Updated: 2023/11/22 14:44:35 by jschwabe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"
#include <semaphore.h>
#include <stdlib.h>

void	free_item(void *tofree)
{
	free(tofree);
	tofree = NULL;
}

void	deconstruct(t_table *rules)
{
	int	i;

	i = -1;
	while (++i < rules->num_philos)
	{
		sem_close(rules->philo_list[i]->sem);
		sem_unlink(rules->philo_list[i]->sem_name);
		free_item(rules->philo_list[i]->sem_name);
		free_item(rules->philo_list[i]);
	}
	free_item(rules->philo_list);
	sem_close(rules->forks);
	sem_close(rules->death);
	sem_close(rules->print);
	sem_close(rules->sim_end);
	sem_close(rules->sync_start);
	if (rules->meals_to_eat >= 0)
		sem_close(rules->req_meals);
	free_item(rules);
}
