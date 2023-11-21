/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschwabe <jschwabe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 14:59:02 by jschwabe          #+#    #+#             */
/*   Updated: 2023/11/21 15:40:38 by jschwabe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	*philo_routine(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	if (!philo)
		return (NULL);
	if (philo->id % 2 == 0)
		sleeping(philo);
	while (1)
	{
		if (!eating(philo))
			break ;
		sleeping(philo);
		thinking(philo);
	}
	return (NULL);
}
