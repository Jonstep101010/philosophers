/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschwabe <jschwabe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 18:04:05 by jschwabe          #+#    #+#             */
/*   Updated: 2023/11/14 12:41:26 by jschwabe         ###   ########.fr       */
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

// files that represent mock headers for the source files to test
# include "io/parse_input.h"
# include "setup/set_philos.h"
# include "utils/utils.h"
# include "utils/cleanup.h"
# include "utils/checks.h"
# include "utils/utils_time.h"
# include "philosim/printing.h"

# ifndef TEST
bool	philo_is_dead(t_philo *philo);
void	*philo_routine(void *arg);
void	setup_table(t_table *table, t_philo *first);
t_err_table	simulation(t_philo *philos, t_table *rules);

// philo actions in routine
void	eating(t_philo *philo);
void	thinking(t_philo *philo);
void	sleeping(t_philo *philo);

# endif
#endif //PHILO_H (actual philo header that will be used in the project)
