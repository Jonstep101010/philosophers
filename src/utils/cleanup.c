/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanup.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschwabe <jschwabe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 07:42:19 by jschwabe          #+#    #+#             */
/*   Updated: 2023/11/14 08:26:25 by jschwabe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TEST
# include "philo.h"
#endif
#ifdef TEST
# include "cleanup.h"
# include <stdio.h>
#endif

/**
 * @brief tell user how to supply correct input
 * @return programs exit code
 */
int		wrong_input()
{
	printf("Some kind of Error message\n");
	return (EXIT_FAILURE);
}

static void	free_philo(t_philo *philo)
{
	pthread_mutex_destroy(&(philo->right));
	pthread_mutex_destroy(&(philo->mutex));
	free(philo);
	philo = NULL;
}

void	deconstruct(t_philo *philo, t_table *rules)
{
	t_philo	*tmp;

	while (rules->num_philos--)
	{
		tmp = philo->next;
		free_philo(philo);
		philo = tmp;
	}
	pthread_mutex_destroy(&rules->death);
	pthread_mutex_destroy(&rules->printing);
	free(rules->philo_list);
	rules->philo_list = NULL;
	free(rules);
	rules = NULL;
}
