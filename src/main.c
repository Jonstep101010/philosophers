/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschwabe <jschwabe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 07:45:08 by jschwabe          #+#    #+#             */
/*   Updated: 2023/11/08 17:39:25 by jschwabe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "philo.h"

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

#ifndef TEST
int main(int ac, char **av)
{
	// atexit(leaks_check);
	t_philo	*s_philo;
	t_input	*rules;

	// memset(&rules, 0, sizeof(t_input));
	if (validate_and_init(&rules, ac, av) == EXIT_FAILURE)
		return (wrong_input());
	// printf("%lu\n", sizeof(t_philo *));
	// s_philo = (t_philo **) ft_calloc(1, sizeof(t_philo));
	s_philo = set_philos(rules);
	// printf("%d", s_philo->id);
	// (void)s_philo;
	// free(rules);
	// rules = NULL;
	deconstruct(s_philo, rules);
	// printf("%d\n", s_philo->next->next->id);
	return (0);
}
#endif // protect against duplicate main for testing
