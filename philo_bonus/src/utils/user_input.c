/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   user_input.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschwabe <jschwabe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 09:59:59 by jschwabe          #+#    #+#             */
/*   Updated: 2023/12/02 18:20:08 by jschwabe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

static bool	isprefix(char c)
{
	if (c == '-' || c == '+')
		return (true);
	return (false);
}

static int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

static long	ft_atol(const char *s)
{
	long	total;
	int		notation;
	int		i;

	total = 0;
	notation = 1;
	i = 0;
	while (s[i] == 32 || (s[i] > 8 && s[i] < 14))
		i++;
	if (isprefix(s[i] && isprefix(s[i + 1])))
		return (LONG_MAX);
	if (isprefix(s[i]))
	{
		if (s[i] == '-')
			notation = -1;
		i++;
	}
	while (ft_isdigit(s[i]))
	{
		total = total * 10 + (s[i] - 48);
		i++;
	}
	return (total * notation);
}

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
