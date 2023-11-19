/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_mem.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschwabe <jschwabe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 10:04:12 by jschwabe          #+#    #+#             */
/*   Updated: 2023/11/16 10:07:52 by jschwabe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"
#include <string.h>

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
