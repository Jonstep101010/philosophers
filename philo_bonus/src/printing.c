/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printing.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschwabe <jschwabe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 07:12:35 by jschwabe          #+#    #+#             */
/*   Updated: 2023/11/18 16:14:51 by jschwabe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	print_message(t_philo *philo, char *msg)
{
	// pthread_mutex_lock(&philo->table->printing);
	sem_wait(philo->table->death);
	// pthread_mutex_lock(&philo->table->death);
	sem_wait(philo->table->print);
	if (!philo->table->dead)
		printf("%lu %d %s\n", timestamp(philo->start_time), philo->id, msg);
	// pthread_mutex_unlock(&philo->table->death);
	sem_post(philo->table->death);
	// pthread_mutex_unlock(&philo->table->printing);
	sem_post(philo->table->print);
}
