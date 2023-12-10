/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deconstruct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschwabe <jschwabe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 12:44:03 by jschwabe          #+#    #+#             */
/*   Updated: 2023/12/03 16:42:02 by jschwabe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	free_item(void *tofree)
{
	free(tofree);
	tofree = NULL;
}

void	*deconstruct(t_table *rules)
{
	int	i;

	if (!rules || !rules->philo_list)
		return (NULL);
	i = -1;
	while (++i < rules->num_philos)
	{
		sem_close(rules->philo_list[i]->sem);
		sem_unlink(rules->philo_list[i]->sem_name);
		free_item(rules->philo_list[i]->sem_name);
		free_item(rules->philo_list[i]);
	}
	sem_close(rules->sync_start);
	sem_close(rules->print);
	sem_close(rules->forks);
	sem_close(rules->req_meals);
	sem_close(rules->death);
	sem_close(rules->sim_end);
	free_item(rules->philo_list);
	free_item(rules);
	return (NULL);
}
