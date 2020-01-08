/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmore <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/04 18:14:48 by pmore             #+#    #+#             */
/*   Updated: 2019/04/04 18:23:38 by pmore            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# define BUFF_SIZE 42

#include <stdlib.h>
#include <unistd.h>
#include "libft.h"

typedef struct 		s_gnl
{
	char		*tmp; 		// dup buffer before being erased
	char		*new_line; 	// will containe the new line
	ssize_t		rd;   		// return of read
	int			gnl_ret; 	// return of the gnl
}					t_gnl;

int		get_next_line(int fd, char **line);

#endif
