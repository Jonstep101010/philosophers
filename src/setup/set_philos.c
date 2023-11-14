/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_philos.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschwabe <jschwabe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 15:57:39 by jschwabe          #+#    #+#             */
/*   Updated: 2023/11/14 17:07:57 by jschwabe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TEST
# include "philo.h"
#endif
#ifdef TEST
# include "set_philos.h"
#endif

/**
 * @brief Create a the next first object
 * @attention expects everything other than table to be valid
 * @return t_philo* cur->next
 */
t_philo	*create_philo(t_table *table, int id)
{
	t_philo			*new;

	if (!table)
		return (NULL);
	new = (t_philo *) ft_calloc(1, sizeof(t_philo));
	if (!new)
		return (NULL);
	new->id = id;
	new->table = table;
	new->meal_count = table->meals_to_eat;
	new->next = new;
	pthread_mutex_init(&(new->right), NULL);
	pthread_mutex_init(&new->mutex, NULL);
	return (new);
}

t_philo	*set_philos(t_table *table)
{
 	t_philo	*cur;
	t_philo	*first;
	int		id;

	first = create_philo(table, 1);
	if (!first)
		return (NULL);
	cur = first;
	id = 1;
	while (++id <= table->num_philos)
	{
		cur->next = create_philo(table, id);
		cur->next->left = &cur->right;
		if (!cur->next)
			return (NULL);
		if (id == table->num_philos)
			break;
		cur = cur->next;
	}
	first->left = &(cur->next->right); // assign last fork to be left of first
	if (table->num_philos > 1)
		cur->next->next = first; // assign next to last
	return (first);
}
