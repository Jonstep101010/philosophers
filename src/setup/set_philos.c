/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_philos.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschwabe <jschwabe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 15:57:39 by jschwabe          #+#    #+#             */
/*   Updated: 2023/11/14 20:47:12 by jschwabe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TEST
# include "philo.h"
#endif
#ifdef TEST
# include "set_philos.h"
#endif

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
	if (id == table->num_philos)
	{
		table->philo_list[0]->left = &new->right;
		new->next = table->philo_list[0];
		new->left = &table->philo_list[id - 2]->right;
	}
	if (id > 1 && id < table->num_philos)
	{
		new->left = &table->philo_list[id - 2]->right;
		table->philo_list[id - 2]->next = new;
	}
	pthread_mutex_init(&new->right, NULL);
	pthread_mutex_init(&new->mutex, NULL);
	return (new);
}
