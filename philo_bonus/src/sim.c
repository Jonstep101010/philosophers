/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sim.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschwabe <jschwabe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 16:46:29 by jschwabe          #+#    #+#             */
/*   Updated: 2023/11/30 17:26:57 by jschwabe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"
#include "struct.h"
#include <pthread.h>
#include <semaphore.h>

#include <limits.h>
static void	*main_monitor(void *arg)
{
	int	meals_eaten;
	t_table	*table;

	table = (t_table *)arg;
	meals_eaten = 0;
	if (table->meals_to_eat == INT_MIN)
		return (NULL);
	sem_wait(table->req_meals);
	while (meals_eaten < table->num_philos - 1)
	{
		sem_wait(table->req_meals);
		if (table->philo_list[0]->dead == true)
			return (NULL);
		meals_eaten++;
	}
	if (meals_eaten == table->num_philos - 1)
	{
		sem_post(table->death);
	sem_wait(table->print);
		printf("\033[1;32m\033[1m%lu\tAll philosophers have eaten %d meals\033[0m\n", timestamp(table->philo_list[0]->start_time), table->meals_to_eat);
	}
	return (NULL);
}

void	simulation(t_table *table)
{
	t_philo	*philo;
	t_philo	**list;
	int		i;
	pthread_t	monitor_meals;

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

	if (pthread_create(&monitor_meals, NULL, main_monitor, table) != 0)
		printf("Error creating main monitor thread\n");
	// need to add checking for meal_count @follow-up
	p_sleep(table->time_to_die);
	sem_wait(table->death);
	sem_post(table->death);
	table->philo_list[0]->dead = true;
	sem_post(table->req_meals);
	i = -1;
	if (pthread_join(monitor_meals, NULL) != 0)
		printf("Error joining main monitor thread\n");
	while (++i < table->num_philos)
	{
		sem_post(philo->table->sim_end);
	}
	p_sleep(100);
	i = -1;
	while (++i < table->num_philos)
		waitpid(-1, NULL, 0);
}
