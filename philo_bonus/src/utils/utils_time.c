/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_time.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschwabe <jschwabe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 10:04:53 by jschwabe          #+#    #+#             */
/*   Updated: 2023/12/02 18:19:30 by jschwabe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

time_t	get_time_ms(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return ((tv.tv_sec * 1000) + (tv.tv_usec / 1000));
}

void	p_sleep(time_t duration)
{
	time_t	i;

	i = get_time_ms();
	while (get_time_ms() - i < duration)
		usleep(50);
}

time_t	timestamp(time_t start_time)
{
	return ((get_time_ms() - start_time));
}
