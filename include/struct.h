/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschwabe <jschwabe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 16:36:03 by jschwabe          #+#    #+#             */
/*   Updated: 2023/11/07 09:09:57 by jschwabe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

# include <pthread.h>
# include <stdbool.h>

typedef struct s_philo t_philo;
typedef struct s_input
{
	time_t	start_time;
	int num_philos;
	int time_to_die;
	int time_to_eat;
	int time_to_sleep;
	int	meals_to_eat;
}	t_input;


// typedef pthread_mutex_t ptm_t;
/*store individual philo*/
struct s_philo
{
	int				id;
	t_philo			*next;
	t_input			*input;
	// ptm_t			*mutex;
	pthread_mutex_t	*left;
	pthread_mutex_t	*right;
	int				time_since_meal;
};

#endif
