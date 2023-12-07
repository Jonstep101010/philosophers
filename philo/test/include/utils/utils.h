/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschwabe <jschwabe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 15:54:43 by jschwabe          #+#    #+#             */
/*   Updated: 2023/12/03 18:26:11 by jschwabe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include "philo.h"

void	*ft_calloc(size_t nitems, size_t size);
void	deconstruct(t_table *rules);
void	print_message(t_philo *philo, char *msg);

#endif // UTILS_H
