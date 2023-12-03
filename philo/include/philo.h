/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschwabe <jschwabe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 18:04:05 by jschwabe          #+#    #+#             */
/*   Updated: 2023/12/03 18:25:32 by jschwabe         ###   ########.fr       */
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
# include "utils/user_input.h"
# include "sim/setup.h"
# include "utils/utils.h"
# include "utils/checks.h"
# include "utils/utils_time.h"

# ifndef TEST
// bool	philo_is_dead(t_philo *philo);
void	*philo_routine(void *arg);
void	*setup(t_table *table);
void	simulation(t_table *rules);

// philo actions in routine
bool	eating(t_philo *philo);
void	thinking(t_philo *philo);
void	sleeping(t_philo *philo);

# endif
#endif //PHILO_H (actual philo header that will be used in the project)
