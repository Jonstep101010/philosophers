/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschwabe <jschwabe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 15:53:08 by jschwabe          #+#    #+#             */
/*   Updated: 2023/11/07 09:13:20 by jschwabe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/**
 * @brief wrap malloc call & initialize
 * @param nitems items to allocate
 * @param size sizeof items
 */
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
