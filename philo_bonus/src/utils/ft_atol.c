/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschwabe <jschwabe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 16:54:03 by jschwabe          #+#    #+#             */
/*   Updated: 2023/12/03 16:54:18 by jschwabe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

static bool	isprefix(char c)
{
	if (c == '-' || c == '+')
		return (true);
	return (false);
}

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

long	ft_atol(const char *s)
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
