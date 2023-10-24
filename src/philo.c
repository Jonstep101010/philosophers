/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschwabe <jschwabe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 18:24:34 by jschwabe          #+#    #+#             */
/*   Updated: 2023/10/24 18:56:08 by jschwabe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void    should_print_executed(){
    printf("executed philo\n");
}

int main(int ac, char **av)
{
    (void)ac;
    (void)av;
    should_print_executed();
    return (0);
}
