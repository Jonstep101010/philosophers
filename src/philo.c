/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschwabe <jschwabe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 18:24:34 by jschwabe          #+#    #+#             */
/*   Updated: 2023/10/27 16:01:53 by jschwabe         ###   ########.fr       */
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

char	*should_return_executed_philo(){
	return ("executed philo");
}

#ifndef TEST
int main(int ac, char **av)
{
	t_philo	*s_philo;
	t_input	s_input;

	// memset(&s_philo, 0, sizeof(s_philo));
	// s_philo.input->philo = &s_philo;
	memset(&s_input, 0, sizeof(t_input));
	// (void)ac;
	// (void)av;

	// printf("%s\n", should_return_executed_philo());
	if (parse_input(ac, av, &s_input) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	s_philo = (t_philo *) ft_calloc(1, sizeof(t_philo));
	set_philos(s_philo, &s_input);

	// s_philo->input =
	// printf("%d\n", s_input.num_philos);
	return (0);
}
#endif // protect against duplicate main for testing
