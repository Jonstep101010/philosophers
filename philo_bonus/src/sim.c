/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sim.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschwabe <jschwabe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 16:46:29 by jschwabe          #+#    #+#             */
/*   Updated: 2023/11/28 11:31:45 by jschwabe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"
#include <semaphore.h>

void	simulation(t_table *table)
{
	t_philo	*philo;
	t_philo	**list;
	int		i;

	list = table->philo_list;
	philo = list[0];
	i = -1;
	while (++i < table->num_philos)
	{
		table->philo_list[i]->pro_id = fork();
		if (table->philo_list[i]->pro_id == 0)
		{
			forked_philo(table->philo_list[i], table);
		}
	}
	sem_post(table->sync_start);
	sem_post(table->print);

	// need to add checking for meal_count @follow-up
	p_sleep(table->time_to_die);
	sem_wait(table->death);
	i = -1;
	while (++i < table->num_philos)
	{
		sem_post(philo->table->sim_end);
	}
	p_sleep(100);
	i = -1;
	while (++i < table->num_philos)
		waitpid(-1, NULL, 0);
}
