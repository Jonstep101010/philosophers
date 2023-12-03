/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschwabe <jschwabe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 16:57:11 by jschwabe          #+#    #+#             */
/*   Updated: 2023/12/03 16:57:35 by jschwabe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

static	int	get_digits(long n)
{
	int	digits;

	digits = 0;
	if (n <= 0)
		digits++;
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
	if (!s)
		return (0);
	if (nbr < 0)
	{
		s[0] = '-';
		nbr *= -1;
	}
	while (len)
	{
		s[--len] = nbr % 10 + '0';
		nbr /= 10;
	}
	return (s);
}
