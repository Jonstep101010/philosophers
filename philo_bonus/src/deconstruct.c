/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deconstruct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschwabe <jschwabe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 12:44:03 by jschwabe          #+#    #+#             */
/*   Updated: 2023/11/18 16:43:42 by jschwabe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

static void	free_item(void *tofree)
{
	free(tofree);
	tofree = NULL;
}

void	deconstruct(t_table *rules)
{
	int	i;

	i = -1;
	while (++i < rules->num_philos)
		free_item(rules->philo_list[i]);
	sem_unlink("/forks");
	sem_unlink("/death");
	sem_unlink("/print");
	free_item(rules->philo_list);
	free_item(rules);
}
