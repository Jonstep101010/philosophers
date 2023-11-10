/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschwabe <jschwabe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 16:36:03 by jschwabe          #+#    #+#             */
/*   Updated: 2023/11/10 09:25:17 by jschwabe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

# include <pthread.h>
# include <stdbool.h>

typedef enum	e_err_table
{
	TABLE_CREATE,
	TABLE_JOIN,
	TABLE_OK
}	t_err_table;

typedef struct s_philo t_philo;
typedef struct s_table
{
	time_t	start_time;
	int				num_philos;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				meals_to_eat;
	bool			dead;
	pthread_t		thread;
	pthread_mutex_t	death;
	t_philo			**philo_list;
}	t_table;


// typedef pthread_mutex_t ptm_t;
/*store individual philo*/
struct s_philo
{
	pthread_t		thread_id;
	int				id;
	t_philo			*next;
	t_table			*input;
	pthread_mutex_t	*left;
	pthread_mutex_t	right;
	t_table			*table;
	int				meal_count;
	int				time_since_meal;
};

#endif
