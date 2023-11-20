/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschwabe <jschwabe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 09:11:06 by jschwabe          #+#    #+#             */
/*   Updated: 2023/11/20 14:48:35 by jschwabe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_BONUS_H
# define PHILO_BONUS_H

# include "struct.h"
# include <stddef.h>
# include <stdbool.h>

# include <semaphore.h>
# include <fcntl.h>

/* monitoring philos */
# include <pthread.h>

/* processes */
# include <unistd.h>
# include <sys/types.h>

# include <stdlib.h>
# include <stdio.h>

/*philo actions*/
bool	eating(t_philo *philo);
void	thinking(t_philo *philo);
void	sleeping(t_philo *philo);
void	*philo_routine(void *arg);

/* checks */
bool	philo_starving(t_philo *philo);

/* philo forked process */
void	*forked_philo(void *arg);


void	print_message(t_philo *philo, char *msg);
void	simulation(t_table *table);

void	*setup(t_table *table);

time_t	get_time_ms(void);
void	p_sleep(time_t duration);
time_t	timestamp(time_t start_time);

void	*ft_calloc(size_t nitems, size_t size);
int	validate_and_init(t_table **input, int ac, char **av);

void	deconstruct(t_table *rules);

/*helpers*/
char	*ft_itoa(int n);
char	*ft_strjoin(char const *s1, char const *s2);

#endif
