/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschwabe <jschwabe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 09:10:16 by jschwabe          #+#    #+#             */
/*   Updated: 2023/12/02 18:21:56 by jschwabe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

/*
memset, printf, malloc, free, write, fork, kill,
exit, pthread_create, pthread_detach, pthread_join,
usleep, gettimeofday, waitpid,

sem_open, sem_close, sem_post, sem_wait, sem_unlink
*/

static int	wrong_input(void)
{
	printf("Some kind of error message");
	return (EXIT_FAILURE);
}

static void	main_cleanup(t_table *table)
{
	if (table)
		deconstruct(table);
	sem_unlink("/forks");
	sem_unlink("/death");
	sem_unlink("/print");
	sem_unlink("/sim_end");
	sem_unlink("/sync_start");
	sem_unlink("/req_meals");
}

int	main(int ac, char **av)
{
	t_table	*table;

	main_cleanup(NULL);
	if (validate_and_init(&table, ac, av) == EXIT_FAILURE || !table)
		return (wrong_input());
	setup(table);
	simulation(table);
	main_cleanup(table);
	return (0);
}
