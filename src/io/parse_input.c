/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschwabe <jschwabe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 14:52:44 by jschwabe          #+#    #+#             */
/*   Updated: 2023/10/28 15:13:41 by jschwabe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse_input.h"

int	check_value(t_input *s_input)
{
	// handle req_meals < 0?
	if (s_input->req_meals_status && s_input->req_meals < 1)
		return (1);
	if (s_input->num_philos < 1)
		return (1);
	if (s_input->time_to_die < 10)
		return (1);
	if (s_input->time_to_eat < 10)
		return (1);
	if (s_input->time_to_sleep < 10)
		return (1);
	return (0);
}

/**
 * @brief parser with rudimentary checks
 * @return exit status
 */
int	parse_input(int ac, char **av, t_input *s_input)
{
	if (ac > 6 || ac < 5)
		return (1);
	s_input->num_philos = atol(av[1]);
	s_input->time_to_die = atol(av[2]);
	s_input->time_to_eat = atol(av[3]);
	s_input->time_to_sleep = atol(av[4]);
	s_input->req_meals_status = false;
	if (ac == 6)
	{
		s_input->req_meals_status = true;
		s_input->req_meals = atol(av[5]);
	}
	return (check_value(s_input));
}
