/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printing.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschwabe <jschwabe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 07:12:35 by jschwabe          #+#    #+#             */
/*   Updated: 2023/11/13 11:05:36 by jschwabe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TEST
# include "philo.h"
#endif
#ifdef TEST
# include "struct.h"
# include <sys/time.h>
# include <stddef.h>
time_t	mock_get_time_ms(void)
{
	struct timeval tv;

	gettimeofday(&tv, NULL);

	return ((tv.tv_sec * 1000) + (tv.tv_usec / 1000));
}

unsigned long	mock_timestamp(t_table *table)
{
	return ((mock_get_time_ms() - table->start_time));
}
void	mock_print_message(t_philo *philo, char *msg)
{
	pthread_mutex_lock(&philo->table->printing);
	printf("%lu %d %s", 1400, philo->id, msg);
	pthread_mutex_unlock(&philo->table->printing);
}
#endif

// use timestamp, philo id, msg, color?
// @follow-up need to implement color
#ifndef TEST
void	print_message(t_philo *philo, char *msg)
{
	pthread_mutex_lock(&philo->table->printing);
	printf("%lu %d %s\n", timestamp(philo->table), philo->id, msg);
	pthread_mutex_unlock(&philo->table->printing);
}
#endif


