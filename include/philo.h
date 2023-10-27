/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschwabe <jschwabe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 18:25:39 by jschwabe          #+#    #+#             */
/*   Updated: 2023/10/27 15:59:29 by jschwabe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H
# include <stddef.h>
# include <stdbool.h>
# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include <pthread.h>
# include "io/parse_input.h"
# include "setup/set_philos.h"
# include "utils/utils.h"
# include "struct.h"

/**
 * @brief make sure testing framework is working
 */
char	*should_return_executed_philo();
#endif
