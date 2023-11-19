/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_table.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschwabe <jschwabe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 14:28:52 by jschwabe          #+#    #+#             */
/*   Updated: 2023/11/15 18:03:20 by jschwabe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	assign_philos(t_table *table, t_philo *new)
{
	if (new->id > 1 && new->id < table->num_philos)
	{
		new->left = &table->philo_list[new->id - 2]->right;
		table->philo_list[new->id - 2]->next = new;
	}
	else if (new->id > 1 && new->id == table->num_philos)
	{
		table->philo_list[0]->left = &new->right;
		new->next = table->philo_list[0];
		new->left = &table->philo_list[new->id - 2]->right;
	}
	else if (new->id == 1 && new->id == table->num_philos)
	{
		new->next = new;
		new->left = &new->right;
	}
	pthread_mutex_init(&new->right, NULL);
}

t_philo	*create_philo(t_table *table, int id)
{
	t_philo			*new;

	if (!table || id < 1 || id > table->num_philos)
		return (NULL);
	new = (t_philo *) ft_calloc(1, sizeof(t_philo));
	if (!new)
		return (NULL);
	new->id = id;
	new->table = table;
	new->meal_count = table->meals_to_eat;
	new->next = new;
	new->start_time = table->start_time;
	assign_philos(table, new);
	return (new);
}

void	*setup(t_table *table)
{
	int	i;

	if (!table || !table->num_philos)
		return (NULL);
	table->start_time = get_time_ms();
	i = -1;
	table->philo_list = ft_calloc(table->num_philos + 1, sizeof(t_philo *));
	if (!table->philo_list)
		return (NULL);
	table->philo_list[table->num_philos] = NULL;
	while (++i < table->num_philos)
	{
		table->philo_list[i] = create_philo(table, i + 1);
		if (!table->philo_list[i])
			return (NULL);
	}
	table->philo_list[table->num_philos - 1]->next = table->philo_list[0];
	return ((void *)table);
}
