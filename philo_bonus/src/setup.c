/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschwabe <jschwabe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 10:09:22 by jschwabe          #+#    #+#             */
/*   Updated: 2023/11/27 18:13:32 by jschwabe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"
#include <semaphore.h>

// @todo cleanup on failure?
static int	open_semaphores(t_table *table)
{
	sem_unlink("/forks");
	sem_unlink("/death");
	sem_unlink("/print");
	sem_unlink("/sim_end");
	sem_unlink("/sync_start");
	sem_unlink("/time_since_meal");
	table->forks = sem_open("/forks", O_CREAT | O_EXCL, 0666, table->num_philos / 2);
	if (table->forks == SEM_FAILED)
		return (EXIT_FAILURE);
	table->death = sem_open("/death", O_CREAT | O_EXCL, 0666, 0);
	if (table->death == SEM_FAILED)
		return (EXIT_FAILURE);
	table->print = sem_open("/print", O_CREAT | O_EXCL, 0666, 0);
	if (table->print == SEM_FAILED)
		return (EXIT_FAILURE);
	table->sim_end = sem_open("/sim_end", O_CREAT | O_EXCL, 0666, 0);
	if (table->sim_end == SEM_FAILED)
		return (EXIT_FAILURE);
	table->sync_start = sem_open("/sync_start", O_CREAT | O_EXCL, 0644, 0);
	if (table->sync_start == SEM_FAILED)
		return (EXIT_FAILURE);
	table->time_since_meal = sem_open("/time_since_meal", O_CREAT | O_EXCL, 0666, 0);
	if (table->time_since_meal == SEM_FAILED)
		return (EXIT_FAILURE);
	if (table->meals_to_eat > 0)
	{
		sem_unlink("/req_meals");
		table->req_meals = sem_open("/req_meals", O_CREAT | O_EXCL, 0666, table->meals_to_eat);
		if (table->req_meals == SEM_FAILED)
			return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}

static void	assign_philos(t_table *table, t_philo *new)
{
	if (new->id > 1 && new->id < table->num_philos)
	{
		// new->left = &table->philo_list[new->id - 2]->right;
		table->philo_list[new->id - 2]->next = new;
	}
	else if (new->id > 1 && new->id == table->num_philos)
	{
		// table->philo_list[0]->left = &new->right;
		new->next = table->philo_list[0];
		// new->left = &table->philo_list[new->id - 2]->right;
	}
	else if (new->id == 1 && new->id == table->num_philos)
	{
		new->next = new;
		// new->left = &new->right;
	}
	// pthread_mutex_init(&new->right, NULL);
}

char	*get_sem_name(int id)
{
	char	*sem_id;
	char	*sem_name;

	sem_id = ft_itoa(id);
	if (!sem_id)
		return (NULL);
	sem_name = ft_strjoin("/sem_", sem_id);
	if (!sem_name)
	{
		free(sem_id);
		return (NULL);
	}
	free(sem_id);
	sem_unlink(sem_name);
	return (sem_name);
}

t_philo	*create_philo(t_table *table, int id, int meals_to_eat)
{
	t_philo			*new;

	if (!table || id < 1 || id > table->num_philos)
		return (NULL);
	new = (t_philo *) ft_calloc(1, sizeof(t_philo));
	if (!new)
		return (NULL);
	new->id = id;
	new->table = table;
	new->meal_count = meals_to_eat;
	new->next = new;
	new->dead = false;
	// @follow-up need to assign start time at the beginning of the simulation
	assign_philos(table, new);
	new->sem_name = get_sem_name(id);
	new->sim_end = false;
	// char	*deathname = get_sem_name(id);
	// new->death_name = ft_strjoin(deathname, "_death");
	// sem_unlink(new->death_name);
	if (!new->sem_name)
		return (free(new), NULL);
	new->sem = sem_open(new->sem_name, O_CREAT | O_EXCL, 0666, 0);
	// new->death = sem_open(new->death_name, O_CREAT | O_EXCL, 0666, 0);
	if (new->sem == SEM_FAILED)
		return (free(new->sem_name), free(new), NULL);
	return (new);
}

void	*setup(t_table *table)
{
	int	i;

	if (!table || !table->num_philos)
		return (NULL);
	i = -1;
	table->philo_list = ft_calloc(table->num_philos + 1, sizeof(t_philo *));
	if (!table->philo_list)
		return (NULL);
	table->philo_list[table->num_philos] = NULL;
	while (++i < table->num_philos)
	{
		table->philo_list[i] = create_philo(table, i + 1, table->meals_to_eat);
		if (!table->philo_list[i] && i != table->num_philos - 1)
			return (NULL);
		table->philo_list[i]->next = table->philo_list[0];
	}
	if (table->num_philos > 1)
		table->philo_list[0]->next = table->philo_list[1];
	if (table->num_philos > 2)
		table->philo_list[i - 2]->next = table->philo_list[i - 1];
	if (open_semaphores(table) == EXIT_FAILURE)
		return (NULL);
	return ((void *)table);
}
