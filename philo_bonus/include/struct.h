/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschwabe <jschwabe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 09:12:27 by jschwabe          #+#    #+#             */
/*   Updated: 2023/11/19 13:29:16 by jschwabe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

# include <stdbool.h>
# include <semaphore.h>

# include <sys/time.h>
# include <time.h>

typedef struct s_philo	t_philo;
typedef struct s_table
{
	time_t				start_time;
	sem_t				*forks;
	sem_t				*death;
	sem_t				*print;
	bool				dead;
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
	time_t				start_time;
	time_t				time_since_meal;
	int					meal_count;
	t_table				*table;
	pid_t				pro_id;
	sem_t				*sem;
	// @follow-up semaphore for each philo using id strjoined
	// @follow-up optional for philo has eaten?
	// sem_t				*meal_count;
};

#endif
