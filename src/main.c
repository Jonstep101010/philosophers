/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschwabe <jschwabe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 07:45:08 by jschwabe          #+#    #+#             */
/*   Updated: 2023/11/09 16:31:27 by jschwabe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/*
functions:
memset, printf, malloc, free, write,
usleep, gettimeofday, pthread_create,
pthread_detach, pthread_join, pthread_mutex_init,
pthread_mutex_destroy, pthread_mutex_lock,
pthread_mutex_unlock
*/
// void	leaks_check()
// {
// 	system("leaks philo");
// }
	// atexit(leaks_check);

#ifndef TEST
int main(int ac, char **av)
{
	t_philo	*s_philo;
	t_input	*rules;

	if (validate_and_init(&rules, ac, av) == EXIT_FAILURE)
		return (wrong_input());
	s_philo = set_philos(rules);
	simulation(s_philo, rules);
	deconstruct(s_philo, rules);
	// printf("%d\n", s_philo->next->next->id);
	return (0);
}
#endif // protect against duplicate main for testing
