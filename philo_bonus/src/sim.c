/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sim.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschwabe <jschwabe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 16:46:29 by jschwabe          #+#    #+#             */
/*   Updated: 2023/12/02 18:20:32 by jschwabe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

static void	*main_monitor(void *arg)
{
	int		meals_eaten;
	t_table	*table;

	table = (t_table *)arg;
	if (table->meals_to_eat == INT_MIN)
		return (NULL);
	meals_eaten = 0;
	sem_wait(table->sync_start);
	sem_post(table->sync_start);
	sem_wait(table->req_meals);
	while (meals_eaten < table->num_philos - 1)
	{
		sem_wait(table->req_meals);
		if (table->philo_list[0]->dead == true)
			return (NULL);
		meals_eaten++;
	}
	if (meals_eaten == table->num_philos - 1
		&& table->philo_list[0]->dead == false)
	{
		sem_post(table->death);
		sem_wait(table->print);
	}
	return (NULL);
}

static void	init_death(t_table *table)
{
	int	i;

	sem_post(table->death);
	table->philo_list[0]->dead = true;
	sem_post(table->req_meals);
	i = -1;
	while (++i < table->num_philos)
		sem_post(table->sim_end);
	i = -1;
	while (++i < table->num_philos)
		waitpid(-1, NULL, 0);
	i = -1;
	while (++i < table->num_philos)
		sem_post(table->req_meals);
}

void	simulation(t_table *table)
{
	int			i;
	pthread_t	monitor_meals;

	if (!table)
		return ;
	i = -1;
	while (++i < table->num_philos)
	{
		table->philo_list[i]->pro_id = fork();
		if (table->philo_list[i]->pro_id == 0)
			forked_philo(table->philo_list[i], table);
	}
	if (pthread_create(&monitor_meals, NULL, main_monitor, table) != 0)
		printf("Error creating main monitor thread\n");
	sem_post(table->sync_start);
	sem_post(table->print);
	p_sleep(table->time_to_die);
	sem_wait(table->death);
	init_death(table);
	if (pthread_join(monitor_meals, NULL) != 0)
		printf("Error joining main monitor thread\n");
}
