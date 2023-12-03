/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanup.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschwabe <jschwabe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 07:42:19 by jschwabe          #+#    #+#             */
/*   Updated: 2023/12/03 17:58:12 by jschwabe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TEST
# include "philo.h"
#endif
#ifdef TEST
# include "cleanup.h"
# include <stdio.h>
#endif

void	free_item(void *tofree)
{
	free(tofree);
	tofree = NULL;
}

void	free_philo(t_philo *philo)
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
