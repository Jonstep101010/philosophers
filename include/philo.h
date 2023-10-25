/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschwabe <jschwabe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 18:25:39 by jschwabe          #+#    #+#             */
/*   Updated: 2023/10/25 17:50:00 by jschwabe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H
# include <stddef.h>
# include <stdbool.h>
# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include "io/parse_input.h"
# include "struct.h"

/**
 * @brief make sure testing framework is working
 */
char	*should_return_executed_philo();

/*av: $(NAME) num_philos time_to_die time_to_eat time_to_sleep [req_meals]*/
/*
(time in ms)
num_philos = num_forks
time_to_die -> eat before it runs out (start of last meal/simulation)
time_to_eat -> time a philosopher needs two forks
time_to_sleep -> time a philo sleeps
req_meals -> simulation stops if all philos have eaten this many times
/ otherwise simulation stops if a philo dies
*/

/*
timestamps:
* philo_id has taken a fork
* philo_id is eating
* philo_id is sleeping
* philo_id is thinking
* philo_id died (max 10ms after death)
*/

/*
functions:
memset, printf, malloc, free, write,
usleep, gettimeofday, pthread_create,
pthread_detach, pthread_join, pthread_mutex_init,
pthread_mutex_destroy, pthread_mutex_lock,
pthread_mutex_unlock
*/

/*
reqs:
- each philo should be a thread
- one fork between each pair of philos -> (one philo, one fork)
- each fork state needs a protection using mutex (philos?)

*/
#endif
