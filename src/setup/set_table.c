/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_table.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschwabe <jschwabe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 14:28:52 by jschwabe          #+#    #+#             */
/*   Updated: 2023/11/14 18:59:12 by jschwabe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/**
 * @brief
 * @warning indexing starts at 0, index num_philos points to NULL
 * @param table
 * @param first
 */
void	setup_table(t_table *table)
{
	int		i;

	if (!table)
		return ;
	i = -1;
	table->philo_list = ft_calloc(table->num_philos + 1, sizeof(t_philo *));
	table->philo_list[table->num_philos] = NULL;
	while (++i < table->num_philos)
	{
		table->philo_list[i] = create_philo(table, i + 1);
		if (!table->philo_list[i])
			return;
		// pthread_create(&table->philo_list[i]->thread_id, NULL, philo_routine, table->philo_list[i]);
		// cur = cur->next;
	}
	table->philo_list[table->num_philos - 1]->next = table->philo_list[0];
}
