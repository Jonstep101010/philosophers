/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_to.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschwabe <jschwabe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 13:38:50 by jschwabe          #+#    #+#             */
/*   Updated: 2023/11/19 17:25:10 by jschwabe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifdef TEST
# include <stdlib.h>
# include <string.h>
void	*ft_calloc(size_t nitems, size_t size)
{
	void	*ptr;

	if (nitems && (nitems * size) / nitems != size)
		return (0);
	ptr = malloc(nitems * size);
	if (!ptr)
		return (0);
	return ((memset(ptr, 0, nitems * size)));
}
#endif
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

static	size_t	ft_strlen(const char *s)
{
	size_t	len;

	len = 0;
	while (*s++)
		len++;
	return (len);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*copy;
	char	*p;

	if (!s1 || !s2)
		return (NULL);
	copy = ft_calloc((ft_strlen(s1) + ft_strlen(s2) + 1), sizeof(char));
	if (!copy)
		return (NULL);
	p = copy;
	while (*s1)
		*p++ = *s1++;
	while (*s2)
		*p++ = *s2++;
	return (*p = '\0', copy);
}
