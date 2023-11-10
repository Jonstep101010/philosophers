/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanup.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschwabe <jschwabe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 07:42:19 by jschwabe          #+#    #+#             */
/*   Updated: 2023/11/10 09:28:02 by jschwabe         ###   ########.fr       */
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
	free(rules->philo_list);
	rules->philo_list = NULL;
	free(rules);
	rules = NULL;
}
