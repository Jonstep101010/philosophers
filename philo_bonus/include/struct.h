/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschwabe <jschwabe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 09:12:27 by jschwabe          #+#    #+#             */
/*   Updated: 2023/11/16 10:12:09 by jschwabe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

# include "philo_bonus.h"

# include <sys/time.h>
# include <time.h>

typedef struct s_philo	t_philo;
typedef struct s_table
{
	time_t				start_time;
	int					num_philos;
	int					time_to_die;
	int					time_to_think;
	int					time_to_eat;
	int					time_to_sleep;
	int					meals_to_eat;
	t_philo				**philo_list;
}						t_table;

struct s_philo
{
	int					id;
	t_philo				*next;
	int					meal_count;
	time_t				start_time;

};

#endif
