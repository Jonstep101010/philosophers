/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschwabe <jschwabe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 16:36:03 by jschwabe          #+#    #+#             */
/*   Updated: 2023/11/15 17:32:50 by jschwabe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

# include <pthread.h>
# include <stdbool.h>

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
	bool				dead;
	pthread_t			thread;
	pthread_mutex_t		death;
	pthread_mutex_t		printing;
	t_philo				**philo_list;
}						t_table;

/*store individual philo*/
struct					s_philo
{
	pthread_t			thread_id;
	int					id;
	t_philo				*next;
	pthread_mutex_t		*left;
	pthread_mutex_t		right;
	pthread_mutex_t		mutex;
	t_table				*table;
	int					meal_count;
	time_t				time_since_meal;
	time_t				start_time;
};

#endif
