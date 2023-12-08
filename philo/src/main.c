/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschwabe <jschwabe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 07:45:08 by jschwabe          #+#    #+#             */
/*   Updated: 2023/12/08 09:22:28 by jschwabe         ###   ########.fr       */
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
static int	wrong_input(void)
{
	printf("shit input\n");
	return (EXIT_FAILURE);
}

#ifndef TEST

int	main(int ac, char **av)
{
	t_table	*table;

	if (validate_and_init(&table, ac, av) == EXIT_FAILURE || !table)
		return (wrong_input());
	setup(table);
	simulation(table);
	deconstruct(table);
	return (0);
}
#endif // protect against duplicate main for testing
