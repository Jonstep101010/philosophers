/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_philos.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschwabe <jschwabe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 15:57:39 by jschwabe          #+#    #+#             */
/*   Updated: 2023/11/14 19:38:26 by jschwabe         ###   ########.fr       */
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
	pthread_mutex_init(&(new->right), NULL);
	pthread_mutex_init(&new->mutex, NULL);
	return (new);
}

// t_philo	*set_philos(t_table *table)
// {
//  	t_philo	*cur;
// 	t_philo	*first;
// 	int		id;

// 	id = 0;
// 	while (++id <= table->num_philos)
// 	{
// 		if (id == 1)
// 		{
// 			first = create_philo(table, id);
// 			cur = first;
// 		}
// 		cur->next = create_philo(table, id);
// 		if (!cur || !cur->next)
// 			return (NULL);
// 		cur->next->left = &cur->right;
// 		if (id == table->num_philos)
// 			break;
// 		cur = cur->next;
// 	}
// 	first->left = &(cur->next->right); // assign last fork to be left of first
// 	if (table->num_philos > 1)
// 		cur->next->next = first; // assign next to last
// 	return (first);
// }
