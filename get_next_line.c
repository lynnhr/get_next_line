/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/08 15:03:16 by lhaydar           #+#    #+#             */
/*   Updated: 2026/01/20 00:52:32 by marvin           ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "get_next_line.h"

char	read_line(int fd, char *reserve)
{
	char	*buffer;
	ssize_t	bytes;
	char	*temp;

	buffer = malloc((SIZE + 1))
}