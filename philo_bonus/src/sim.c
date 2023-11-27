/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sim.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschwabe <jschwabe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 16:46:29 by jschwabe          #+#    #+#             */
/*   Updated: 2023/11/27 13:46:01 by jschwabe         ###   ########.fr       */
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
			// printf("child %d, pid:%d\n", i, getpid());
			forked_philo(table->philo_list[i]);
			exit(0);
		}
	}
	i = -1;
	while (++i < table->num_philos)
		sem_post(table->sync_start);
	sem_post(table->print);

	// need to add checking for meal_count @follow-up
	p_sleep(table->time_to_die);
	sem_wait(table->death);
	sem_post(table->death);
	p_sleep(10);
	sem_post(table->print);
	i = -1;
	while (++i < table->num_philos)
		waitpid(-1, NULL, 0);
	// waitpid(-1, NULL, 0);
	while (++i < table->num_philos)
		waitpid(-1, NULL, 0);
		// kill(table->philo_list[i]->pro_id, SIGKILL);

}
