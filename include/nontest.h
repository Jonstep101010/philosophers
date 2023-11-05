/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nontest.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschwabe <jschwabe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 18:04:05 by jschwabe          #+#    #+#             */
/*   Updated: 2023/11/04 18:07:04 by jschwabe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef NONTEST_H
# define NONTEST_H
# include "struct.h"
# include <stddef.h>
# include <stdbool.h>
# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include <pthread.h>

// files that represent mock headers for the source files to test
# include "io/parse_input.h"
# include "setup/set_philos.h"
# include "utils/utils.h"

#endif //NONTEST_H (actual philo header that will be used in the project)