/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_input.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschwabe <jschwabe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 13:48:42 by jschwabe          #+#    #+#             */
/*   Updated: 2023/11/10 09:10:38 by jschwabe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSE_INPUT_H
# define PARSE_INPUT_H
# include "struct.h"
# include "philo.h"

int		validate_and_init(t_table **input, int ac, char **av);
long	ft_atol(const char *s);
#endif // PARSE_INPUT_H
