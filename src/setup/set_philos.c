/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_philos.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschwabe <jschwabe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 15:57:39 by jschwabe          #+#    #+#             */
/*   Updated: 2023/10/27 17:31:58 by jschwabe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "set_philos.h"

//@follow-up see if segfault on first
static	void	set_first_philo(t_philo *s_philo, t_input *s_input)
{
	pthread_mutex_t	first_mutex;

	pthread_mutex_init(&first_mutex, NULL);
	s_philo->id = 1;
	s_philo->input = s_input;
}

/**
 * @brief Create a the next philo object
 *
 * @param cur previous object
 * @return t_philo* cur->next
 */
static	t_philo	*create_philo(t_philo *prev, t_input *s_input, int id)
{
	t_philo	*new_philo;
	pthread_mutex_t	new_mutex;

	if (id > s_input->num_philos)
		return (NULL);
	new_philo = (t_philo *) ft_calloc(1, sizeof(t_philo));
	if (!new_philo)
		return (NULL);
	new_philo->id = id;
	new_philo->input = s_input;
	pthread_mutex_init(&new_mutex, NULL);
	prev->right = &new_mutex;
	new_philo->left = prev->mutex;
	new_philo->mutex = &new_mutex;
	return (new_philo);
}

/**
 * @brief Set the philos object
 *
 * @param s_philo first philo
 * @param s_input
 */
void	set_philos(t_philo *s_philo, t_input *s_input)
{
 	t_philo	*cur;
	t_philo	*prev;
	int		id;

	set_first_philo(s_philo, s_input);
	id = 1;
	prev = NULL;
	cur = s_philo;
	while (id <= s_input->num_philos)
	{
		cur->next = create_philo(cur, s_input, id);
		if (!cur->next)
			break;
		cur->next->left = cur->mutex;
		// prev = cur;
		cur = cur->next;
		// if (prev)
		// 	prev->right = cur->mutex;
		id++;
	}
	cur->next = s_philo;
	s_philo->left = cur->mutex;
	s_philo->right = s_philo->next->mutex;
}

