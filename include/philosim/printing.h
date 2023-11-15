/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printing.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschwabe <jschwabe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 08:30:31 by jschwabe          #+#    #+#             */
/*   Updated: 2023/11/15 08:30:50 by jschwabe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTING_H
# define PRINTING_H

# include "struct.h"
# ifndef TEST

void			print_message(t_philo *philo, char *msg);
# else

time_t			mock_get_time_ms(void);
unsigned long	mock_timestamp(t_table *table);
void			mock_print_message(t_philo *philo, char *msg);
# endif
#endif // PRINTING_H
