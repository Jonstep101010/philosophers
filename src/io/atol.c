/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atol.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschwabe <jschwabe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 17:22:00 by jschwabe          #+#    #+#             */
/*   Updated: 2023/10/25 17:26:21 by jschwabe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse_input.h"
#include <limits.h>

static bool	isdigit(char c)
{
	if (c >= '0' && c <= '9')
		return (true);
	return (false);
}

static bool	isprefix(char c)
{
	if (c == '-' || c == '+')
		return (true);
	return (false);
}

long	atol(const char *s)
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
	while (isdigit(s[i]))
	{
		total = total * 10 + (s[i] - 48);
		i++;
	}
	return (total * notation);
}
