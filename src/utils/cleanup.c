/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanup.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschwabe <jschwabe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 07:42:19 by jschwabe          #+#    #+#             */
/*   Updated: 2023/11/07 09:37:25 by jschwabe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TEST
# include "philo.h"
#endif
#ifdef TEST
# include "cleanup.h"
# include <stdio.h>
#endif

int		wrong_input()
{
	printf("Some kind of Error message");
	return (EXIT_FAILURE);
}

void	deconstruct(t_philo *s_philo)
{
	t_philo	*tmp;

	tmp = s_philo;
	while (tmp)
	{
		tmp = s_philo->next;
		if (tmp->right)
			pthread_mutex_destroy(tmp->right);
		free(s_philo);
		s_philo = NULL;
		s_philo = tmp;
	}
}
