/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_table.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschwabe <jschwabe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 14:28:52 by jschwabe          #+#    #+#             */
/*   Updated: 2023/11/14 17:42:09 by jschwabe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/**
 * @brief
 * @warning indexing starts at 0, index num_philos points to NULL
 * @param table
 * @param first
 */
void	setup_table(t_table *table, t_philo *cur)
{
	int		i;

	if (!table)
		return ;
	i = -1;
	table->philo_list = ft_calloc(table->num_philos + 1, sizeof(t_philo *));
	table->philo_list[table->num_philos] = NULL;
	while (++i < table->num_philos)
	{
		table->philo_list[i] = cur;
		pthread_create(&cur->thread_id, NULL, philo_routine, cur);
		cur = cur->next;
	}
}
