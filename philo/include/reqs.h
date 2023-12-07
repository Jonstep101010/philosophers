/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reqs.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschwabe <jschwabe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 15:40:23 by jschwabe          #+#    #+#             */
/*   Updated: 2023/12/06 09:09:57 by jschwabe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

/* reqs:
- each philo should be a thread
- one fork between each pair of philos -> (one philo, one fork)
- each fork state needs a protection using mutex (philos?)

num_philos:
even: time_to_die = time_to_eat + time_to_sleep + 10

odd:  time_to_die = time_to_eat * 2 + time_to_sleep + 10

1) odd sleep at beginning for (time_to_eat / 2)
2) odd start taking from right fork, even from left
3) all philos take from right fork, except for last one (takes from left)

philos next to each other cannot ever eat at the same time

if time to die is less than sum of time_to_eat + time_to_sleep
before philosopher sleeps, update last meal time

- philos cannot check themselves for death 
(thread busy with action and cannot check death time)
	-> one thread checks time - last_eat_time == time_to_die
	 - once req_meals have been reached, stop
- some philos eat at same time (4 or more)

- single philo will always die (cannot eat without 2 forks)

Things to consider:
- printf interference
- own usleep (for precision)
- avoid infinite loops

- use setters and getters for mutex states

- use valgrind --tool=helgrind -> check
- use fsanitize=thread

*/
