/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschwabe <jschwabe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 13:38:50 by jschwabe          #+#    #+#             */
/*   Updated: 2023/12/07 13:57:57 by jschwabe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

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
