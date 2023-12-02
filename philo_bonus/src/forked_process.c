/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   forked_process.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschwabe <jschwabe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 11:43:09 by jschwabe          #+#    #+#             */
/*   Updated: 2023/12/02 18:22:08 by jschwabe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

static void	*free_fork(t_table *rules)
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
	sem_close(rules->forks);
	sem_close(rules->death);
	sem_close(rules->print);
	sem_close(rules->req_meals);
	sem_close(rules->sim_end);
	sem_close(rules->sync_start);
	free_item(rules->philo_list);
	free_item(rules);
	return (NULL);
}

void	*forked_philo(t_philo *philo, t_table *table)
{
	pthread_t	monitor;
	pthread_t	cleanup;

	if (!philo || !table || !philo->sem || !table->print)
		exit(0);
	if (pthread_create(&monitor, NULL, monitor_philo, philo) != 0)
		return (NULL);
	if (pthread_create(&cleanup, NULL, wait_philo_exit, philo) != 0)
		return (NULL);
	sem_wait(philo->sem);
	sem_post(philo->sem);
	philo_first_action(philo);
	sem_wait(philo->sem);
	philo_routine(philo);
	if (pthread_join(monitor, NULL) != 0)
		printf("Error joining monitor thread\n");
	if (pthread_join(cleanup, NULL) != 0)
		printf("Error detaching cleanup thread\n");
	sem_post(philo->table->print);
	sem_wait(philo->sem);
	free_fork(philo->table);
	exit(0);
}
