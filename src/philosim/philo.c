/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschwabe <jschwabe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 16:46:29 by jschwabe          #+#    #+#             */
/*   Updated: 2023/11/10 09:28:57 by jschwabe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	philo_routine(void *arg)
{
	(void)arg;

}

void	*table_routine(void *arg)
{
	t_table	*table;

	table = (t_table *)arg;
	printf("some table data from thread: %d\n", table->num_philos);
	return (NULL);
}

	// pthread_detach??
t_err_table	simulation(t_philo *philos, t_table *table)
{
	if (pthread_create(&(table->thread), NULL, table_routine, table) != 0)
		return (TABLE_CREATE);
	(void)philos;
	if (pthread_join(table->thread, NULL) != 0)
		return (TABLE_JOIN);
	return (TABLE_OK);

	// (void)rules;
	// (void)philos;
	// spawn threads for philos (each with own routine)
	// spawn table for supervision
	// t_sim	*sim;

	// if (rules->num_philos % 2 == 0)
	// 	even_number_philos
	// if (pthread_create(philos->thread_id, , &philo_routine, philos))
}
