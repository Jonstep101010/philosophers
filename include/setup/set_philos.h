/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_philos.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschwabe <jschwabe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 15:49:45 by jschwabe          #+#    #+#             */
/*   Updated: 2023/11/15 08:31:00 by jschwabe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SET_PHILOS_H
# define SET_PHILOS_H

# include "philo.h"
# include "struct.h"

t_philo	*set_philos(t_table *table);
t_philo	*create_philo(t_table *table, int id);
#endif // SET_PHILOS_H
