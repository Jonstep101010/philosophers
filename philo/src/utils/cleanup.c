/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanup.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschwabe <jschwabe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 07:42:19 by jschwabe          #+#    #+#             */
/*   Updated: 2023/11/15 18:03:26 by jschwabe         ###   ########.fr       */
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
int	wrong_input(void)
{
	printf("Some kind of Error message\n");
	return (EXIT_FAILURE);
}

void	free_philo(t_philo *philo)
{
	pthread_mutex_destroy(&(philo->right));
	free(philo);
	philo = NULL;
}

void	deconstruct(t_table *rules)
{
	int	i;

	i = -1;
	while (++i < rules->num_philos)
		free_philo(rules->philo_list[i]);
	pthread_mutex_destroy(&rules->death);
	pthread_mutex_destroy(&rules->printing);
	free(rules->philo_list);
	rules->philo_list = NULL;
	free(rules);
	rules = NULL;
}
