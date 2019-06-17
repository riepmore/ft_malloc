/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilities.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmore <pmore@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/12 23:11:01 by pmore             #+#    #+#             */
/*   Updated: 2019/06/16 21:13:02 by pmore            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_malloc.h"

void		increment_page_number(size_t type)
{
	if (type == TINY_SIZE)
		area.nb_pages_T++;
	else if (type == SMALL_SIZE)
		area.nb_pages_S++;
}

int			is_last_chunk(t_page *page)
{
	int		i;
	int		n;

	i = 0;
	n = 0;
	if (page == 0)
		return (FALSE); // Ca devrait pas arriver mais bon
	while (i < NB_CHUNKS)
	{
		if (page->chunks[i].isfree == FALSE)
			n++;
		if (n > 1)
			return (FALSE);
		i++;
	}
	return (TRUE);
}
