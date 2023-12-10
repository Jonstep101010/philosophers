/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deconstruct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschwabe <jschwabe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 07:42:19 by jschwabe          #+#    #+#             */
/*   Updated: 2023/12/03 18:19:39 by jschwabe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	free_item(void *tofree)
{
	free(tofree);
	tofree = NULL;
}

static void	free_philo(t_philo *philo)
{
	pthread_mutex_destroy(&(philo->right));
	free_item(philo);
}

void	deconstruct(t_table *rules)
{
	int	i;

	i = -1;
	while (++i < rules->num_philos)
		free_philo(rules->philo_list[i]);
	pthread_mutex_destroy(&rules->death);
	pthread_mutex_destroy(&rules->printing);
	free_item(rules->philo_list);
	free_item(rules);
}
