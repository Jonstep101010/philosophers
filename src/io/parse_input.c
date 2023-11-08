/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschwabe <jschwabe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 14:52:44 by jschwabe          #+#    #+#             */
/*   Updated: 2023/11/07 09:36:04 by jschwabe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse_input.h"
#include <limits.h>

static bool	is_valid_nbr(int ac, char **av)
{
	int	i;
	int	ii;
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

// @warning does not use actual time
// @follow-up rules for death/printing? (mutex?)
static t_input	*init_input_rules(int ac, char **av)
{
	t_input	*s_input;

	s_input = (t_input *) ft_calloc(1, sizeof(t_input));
	s_input->start_time = 0;// (@todo get_time_ms)
	s_input->num_philos = ft_atol(av[1]);
	s_input->time_to_die = ft_atol(av[2]);
	s_input->time_to_eat = ft_atol(av[3]);
	s_input->time_to_sleep = ft_atol(av[4]);
	s_input->meals_to_eat = INT_MIN;
	if (ac == 6 && ft_atol(av[5]) >= 0)
		s_input->meals_to_eat = ft_atol(av[5]);
	return (s_input);
}

int	validate_and_init(t_input **input, int ac, char **av)
{
	if (ac > 6 || ac < 5)
		return (EXIT_FAILURE);
	if (!is_valid_nbr(ac, av))
		return (EXIT_FAILURE);
	*input = init_input_rules(ac, av);
	if (!*input)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
