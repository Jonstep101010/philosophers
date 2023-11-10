/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_philos.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschwabe <jschwabe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 15:57:39 by jschwabe          #+#    #+#             */
/*   Updated: 2023/11/10 09:10:38 by jschwabe         ###   ########.fr       */
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
	new->input = table;
	pthread_mutex_init(&(new->right), NULL);
	return (new);
}

/**
 * @brief
 * @warning indexing starts at 0, index num_philos points to NULL
 * @param table
 * @param first
 */
void	setup_table(t_table *table, t_philo *cur)
{
	int		i;

	if (!table)
		return ;
	i = -1;
	table->philo_list = ft_calloc(table->num_philos + 1, sizeof(t_philo *));
	while (++i < table->num_philos)
	{
		table->philo_list[i] = cur;
		cur = cur->next;
	}
	table->philo_list[i] = NULL;
}

/**
 * @brief Set the firsts object
 *
 * @param table
 */
t_philo	*set_philos(t_table *table)
{
 	t_philo	*cur;
	t_philo	*first;
	int		id;

	first = create_philo(table, 1);
	if (!first)
		return (NULL);
	id = 1;
	cur = first;
	while (++id <= table->num_philos)
	{
		cur->next = create_philo(table, id);
		if (!cur->next)
			return (NULL);
		if (id == table->num_philos)
			break;
		cur->next->left = &(cur->right);
		cur = cur->next;
	}
	first->left = &(cur->next->right); // assign last fork to be left of first
	cur->next->next = first; // assign next to last
	setup_table(table, first);
	return (first);
}
