/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printing.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschwabe <jschwabe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 07:12:35 by jschwabe          #+#    #+#             */
/*   Updated: 2023/11/28 10:52:29 by jschwabe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"
#include <semaphore.h>
#include <unistd.h>

bool	print_message(t_philo *philo, char *msg)
{
	sem_wait(philo->sem);
	if (philo->dead)
	{
		sem_post(philo->sem);
		return (false);
	}
	sem_wait(philo->table->print);
	if (!philo->dead)
		printf("%lu\t%d %s\n", timestamp(philo->start_time), philo->id, msg);
	else
		return (false);
	sem_post(philo->sem);
	sem_post(philo->table->print);
	return (true);
}
