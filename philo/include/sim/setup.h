/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_table.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschwabe <jschwabe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 15:49:45 by jschwabe          #+#    #+#             */
/*   Updated: 2023/11/15 08:15:36 by jschwabe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SET_PHILOS_H
# define SET_PHILOS_H

# include "struct.h"

// t_philo	*set_philos(t_table *table);
t_philo	*create_philo(t_table *table, int id);
void	*setup(t_table *table);
#endif // SET_PHILOS_H
