/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_time.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschwabe <jschwabe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 14:19:15 by jschwabe          #+#    #+#             */
/*   Updated: 2023/11/14 16:39:03 by jschwabe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifdef TEST
#include "utils_time.h"
#include "struct.h"
#else
#include "philo.h"
#endif

#include <sys/time.h>
time_t	get_time_ms(void)
{
	struct timeval tv;

	gettimeofday(&tv, NULL);

	return ((tv.tv_sec * 1000) + (tv.tv_usec / 1000));
}

#include <unistd.h>
void	p_sleep(time_t duration)
{
	time_t	i;

	i = get_time_ms();
	while (get_time_ms() - i < duration)
		usleep(50);
}

time_t	timestamp(t_table *table)
{
	return ((get_time_ms() - table->start_time));
}
