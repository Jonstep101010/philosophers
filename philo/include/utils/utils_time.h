/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_time.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschwabe <jschwabe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 08:32:37 by jschwabe          #+#    #+#             */
/*   Updated: 2023/11/15 17:30:33 by jschwabe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_TIME_H
# define UTILS_TIME_H

# include "struct.h"
# include <stddef.h>
# include <sys/time.h>
# include <time.h>

time_t					get_time_ms(void);
void					p_sleep(time_t duration);
typedef struct s_table	t_table;
time_t					timestamp(time_t start_time);
#endif // TIME_H
