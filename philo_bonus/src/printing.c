/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printing.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschwabe <jschwabe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 07:12:35 by jschwabe          #+#    #+#             */
/*   Updated: 2023/11/25 16:09:57 by jschwabe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"
#include <semaphore.h>
#include <unistd.h>

void	print_message(t_philo *philo, char *msg)
{
	sem_wait(philo->table->print);
	sem_wait(philo->sem);
	if (!philo->dead)
		printf("%lu %d %s (pid:%d)\n", timestamp(philo->start_time), philo->id, msg, getpid());
	sem_post(philo->sem);
	sem_post(philo->table->print);
}
