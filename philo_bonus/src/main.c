/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschwabe <jschwabe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 09:10:16 by jschwabe          #+#    #+#             */
/*   Updated: 2023/11/16 10:16:30 by jschwabe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

/*
memset, printf, malloc, free, write, fork, kill,
exit, pthread_create, pthread_detach, pthread_join,
usleep, gettimeofday, waitpid, sem_open, sem_close,
sem_post, sem_wait, sem_unlink
*/
/*
use named semaphores:
-
*/

static int	wrong_input(void)
{
	printf("Some kind of error message");
	return (EXIT_FAILURE);
}

int	main(int ac, char **av)
{
	t_table	*table;

	if (validate_and_init(&table, ac, av) == EXIT_FAILURE || !table)
		return (wrong_input());
	setup(table);
	// simulation(table);
	// deconstruct(table);
	return (0);

}
