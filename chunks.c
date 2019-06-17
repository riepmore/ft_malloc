/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmore <pmore@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/11 15:36:38 by pmore             #+#    #+#             */
/*   Updated: 2019/06/16 20:55:16 by pmore            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_malloc.h"

size_t		chk_max_free(t_page *page)
{
	int		i;

	i = 0;
	while (i < NB_CHUNKS)
	{
		if (page->chunks[i].isfree == TRUE)
			return (page->chunks[i].size);
		i++;
	}
	return (0);
}

void		assign_page(t_page *page, size_t type)
{
	page->max_free = chk_max_free(page);
	if (type == TINY_SIZE && area.tiny == 0)
		area.tiny = page;
	else if (type == SMALL_SIZE && area.small == 0)
		area.small = page;
}

void		*assign_alloc(t_page *page, size_t size, size_t type)
{
	size_t		i;

	i = NB_CHUNKS;
	while (i >= 0)
	{
		if (page->chunks[i].isfree == TRUE && page->chunks[i].size >= size)
		{
			page->chunks[i].isfree = FALSE;
			page->total_free -= page->chunks[i].size;
			// Split memory here
			assign_page(page, type);
			return (page->chunks[i].addr);
		}
		i--;
	}
	return (0);
}
