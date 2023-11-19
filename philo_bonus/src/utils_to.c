/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_to.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschwabe <jschwabe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 13:38:50 by jschwabe          #+#    #+#             */
/*   Updated: 2023/11/19 13:42:55 by jschwabe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

static	int	get_digits(long n)
{
	int	digits;

	digits = 0;
	while (n)
	{
		n /= 10;
		digits++;
	}
	return (digits);
}

char	*ft_itoa(int n)
{
	char	*s;
	int		len;
	long	nbr;

	nbr = n;
	len = get_digits(nbr);
	s = (char *) ft_calloc(len + 1, sizeof(char));
	while (len)
	{
		s[len--] = (nbr % 10) + '0';
		nbr /= 10;
	}
	return (s);
}

