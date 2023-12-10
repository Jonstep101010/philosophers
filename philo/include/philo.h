/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschwabe <jschwabe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 18:04:05 by jschwabe          #+#    #+#             */
/*   Updated: 2023/12/07 09:04:20 by jschwabe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H
# include "struct.h"
# include <stddef.h>
# include <stdbool.h>
# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include <pthread.h>

# ifndef TEST

int		validate_and_init(t_table **input, int ac, char **av);

t_philo	*create_philo(t_table *table, int id);
void	*setup(t_table *table);
void	*philosopher(void *arg);
void	*setup(t_table *table);
void	simulation(t_table *rules);
bool	philo_is_dead(t_philo *philo);

// philo actions in routine
bool	eating(t_philo *philo);
void	thinking(t_philo *philo);
void	sleeping(t_philo *philo);
void	print_message(t_philo *philo, char *msg);

time_t	get_time_ms(void);
void	p_sleep(time_t duration);
time_t	timestamp(time_t start_time);

void	deconstruct(t_table *table);

int		ft_isdigit(int c);
long	ft_atol(const char *str);
void	*ft_calloc(size_t nitems, size_t size);
# endif
#endif //PHILO_H (actual philo header that will be used in the project)
