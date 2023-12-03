/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   user_input.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschwabe <jschwabe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 09:59:59 by jschwabe          #+#    #+#             */
/*   Updated: 2023/12/03 16:53:54 by jschwabe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

static bool	is_valid_nbr(int ac, char **av)
{
	int		i;
	int		ii;
	long	nbr;

	i = 0;
	nbr = 0;
	while (i < ac && av[++i])
	{
		if (!av[i] || !av[i][0])
			return (false);
		nbr = ft_atol(av[i]);
		if (nbr > INT_MAX || nbr < 1)
			return (false);
		ii = 0;
		while (av[i][ii])
		{
			if (!(ft_isdigit(av[i][ii])))
				return (false);
			ii++;
		}
	}
	return (true);
}

static t_table	*init_ruletable(int ac, char **av)
{
	t_table	*table;

	table = (t_table *)ft_calloc(1, sizeof(t_table));
	if (!table)
		return (NULL);
	table->num_philos = ft_atol(av[1]);
	table->time_to_die = ft_atol(av[2]);
	table->time_to_eat = ft_atol(av[3]);
	table->time_to_sleep = ft_atol(av[4]);
	if (ac == 6 && ft_atol(av[5]) >= 0 && table->num_philos > 1)
		table->meals_to_eat = ft_atol(av[5]);
	else
		table->meals_to_eat = INT_MIN;
	return (table);
}

int	validate_and_init(t_table **input, int ac, char **av)
{
	if (ac > 6 || ac < 5)
		return (EXIT_FAILURE);
	if (!is_valid_nbr(ac, av))
		return (EXIT_FAILURE);
	*input = init_ruletable(ac, av);
	if (!*input)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
