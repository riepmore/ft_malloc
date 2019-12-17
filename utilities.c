/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilities.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmore <pmore@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/12 23:11:01 by pmore             #+#    #+#             */
/*   Updated: 2019/12/17 01:47:45 by pmore            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_malloc.h"

void		assign_alloc(t_page *page, size_t type)
{
	if (page == 0)
	{
		printf("Error in assign_alloc(), page = 0\n");
		return ;
	}
	while (page->prev != 0) // rewind
		page = page->prev;
	if (type == TINY_SIZE)
	{
		area.nb_pages_T++;
		area.tiny = page;
	}
	else if (type == SMALL_SIZE)
	{
		area.nb_pages_S++;
		area.small = page;
	}
	else
	{
		printf("Error in assign_alloc(), type of page incorrect.\n");
		return;
	}
}

int			nb_chunks(t_page *page)
{
	int			i;
	t_chunk		*tmp;

	i = 0;
	tmp = page->chunks;
	while (tmp)
	{
		tmp = tmp->next;
		i++;
	}
	return (i);
}
