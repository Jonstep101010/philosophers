/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_philos.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschwabe <jschwabe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 15:57:39 by jschwabe          #+#    #+#             */
/*   Updated: 2023/11/08 18:08:30 by jschwabe         ###   ########.fr       */
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
 *
 * @return t_philo* cur->next
 */
static	t_philo	*create_philo(t_input *s_input, int id)
{
	t_philo			*new;

	if (id > s_input->num_philos)
		return (NULL);
	new = (t_philo *) ft_calloc(1, sizeof(t_philo));
	if (!new)
		return (NULL);
	new->id = id;
	new->input = s_input;
	pthread_mutex_init(&(new->right), NULL);
	return (new);
}

/**
 * @brief Set the firsts object
 *
 * @param s_input
 */
t_philo	*set_philos(t_input *s_input)
{
 	t_philo	*cur;
	t_philo	*first;
	int		id;

	first = create_philo(s_input, 1);
	if (!first)
		return (NULL);
	id = 1;
	cur = first;
	while (++id <= s_input->num_philos)
	{
		cur->next = create_philo(s_input, id);
		if (id == s_input->num_philos)
			break;
		cur->next->left = &(cur->right);
		cur = cur->next;
	}
	first->left = &(cur->next->right); // assign last fork to be left of first
	cur->next->next = first; // assign next to last
	return (first);
}

