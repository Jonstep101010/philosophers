/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanup.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschwabe <jschwabe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 08:32:18 by jschwabe          #+#    #+#             */
/*   Updated: 2023/11/15 08:32:27 by jschwabe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLEANUP_H
# define CLEANUP_H
# include "struct.h"
# include <stdlib.h>

void	deconstruct(t_table *rules);
int		wrong_input(void);
#endif // CLEANUP_H
