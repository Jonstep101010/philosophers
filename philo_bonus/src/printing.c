/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printing.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschwabe <jschwabe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 07:12:35 by jschwabe          #+#    #+#             */
/*   Updated: 2023/11/27 11:14:18 by jschwabe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"
#include <semaphore.h>
#include <unistd.h>

void	print_message(t_philo *philo, char *msg)
{
	sem_wait(philo->sem);
	if (!philo->dead)
	{
		sem_post(philo->sem);
		sem_wait(philo->table->print);
		printf("%lu\t%d %s\n", timestamp(philo->start_time), philo->id, msg);
		sem_post(philo->table->print);
	}
	else
	{
		sem_post(philo->sem);
		return ;
	}
}
