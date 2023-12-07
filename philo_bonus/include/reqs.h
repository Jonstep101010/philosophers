/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reqs.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschwabe <jschwabe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 09:10:02 by jschwabe          #+#    #+#             */
/*   Updated: 2023/12/06 09:16:52 by jschwabe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
• All the forks are put in the middle of the table.
• They have no states in memory but the number of
	 available forks is represented by a semaphore.
• Each philosopher should be a process.
	But the main process should not be a philosopher
*/