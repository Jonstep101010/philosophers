/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschwabe <jschwabe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 09:11:06 by jschwabe          #+#    #+#             */
/*   Updated: 2023/12/02 18:14:17 by jschwabe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_BONUS_H
# define PHILO_BONUS_H

# include "external.h"
# include "struct.h"

/* philo actions */
void	eating(t_philo *philo);
void	philo_first_action(t_philo *philo);
void	*philo_routine(t_philo *philo);

/* philo threads (monitoring) */
void	*monitor_philo(void *arg);
void	*wait_philo_exit(void *arg);

/* philo forked process */
void	*forked_philo(t_philo *philo, t_table *table);
void	print_message(t_philo *philo, char *msg);
void	simulation(t_table *table);

/* utils time */
time_t	get_time_ms(void);
void	p_sleep(time_t duration);
time_t	timestamp(time_t start_time);

/* utils data */
int		validate_and_init(t_table **input, int ac, char **av);
void	*setup(t_table *table);
void	free_item(void *tofree);
void	deconstruct(t_table *rules);

/*helpers*/
void	*ft_calloc(size_t nitems, size_t size);
char	*ft_itoa(int n);
char	*ft_strjoin(char const *s1, char const *s2);

#endif
