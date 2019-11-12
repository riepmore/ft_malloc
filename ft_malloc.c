/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_malloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmore <pmore@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/11 15:36:31 by pmore             #+#    #+#             */
/*   Updated: 2019/11/12 20:33:40 by pmore            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_malloc.h"
#include <stdlib.h>

void		*create_new_chunk(t_page *page, size_t size)
{
	int			i;
	size_t		addr_move;

	addr_move = 0;
	i = 0;
	while (i < (NB_CHUNKS - 1))
	{
		size /= 2;
		page->chunks[i].size = size;
		page->chunks[i].isfree = TRUE;
		page->chunks[i].addr = ((void*)page + sizeof(t_chunk)) + addr_move;
		addr_move += size;
		i++;
	}
	// On repete le boucle car le dernier chunk doit avoir les mêmes caracteristiques que l'avant dernier.
	page->chunks[i].size = size;
	page->chunks[i].isfree = TRUE;
	page->chunks[i].addr = ((void*)page + sizeof(t_chunk)) + addr_move;
	return (page);
}

void		*create_new_page(t_page *page, size_t size, size_t type)
{
	t_page		*new;
	size_t		page_size;
	struct rlimit rlp;

	getrlimit(RLIMIT_AS, &rlp);
	printf("RLIMIT_CUR: %li | RLIMIT_MAX: %li\n", (long)rlp.rlim_cur, (long)rlp.rlim_max);
	if ((long)area.cur_alloc + size >= (long)rlp.rlim_cur)
	{
		printf("ya pu de place rlimit truc\n");
		return (0);
	}
	area.cur_alloc += size;
	new = 0;
	page_size = type * getpagesize();
	new = (t_page*)mmap(0, sizeof(t_page*) + page_size, PROT_READ | PROT_WRITE, MAP_ANONYMOUS | MAP_PRIVATE, -1, 0);
	if (new == MAP_FAILED)
		return (0);
	new->total_free = page_size;
	new->total_size = page_size;
	new->max_free = page_size / 2;
	new->prev = page;
	if (page != 0)
		page->next = new;
	else
		page = new;
	new->next = 0;
	increment_page_number(type);
	create_new_chunk(new, page_size);
	return (assign_alloc(new, size, type));
}

void		*create_large_page(size_t size)
{
	t_lpage		*new;
	t_lpage		*tmp;

	new = 0;
	tmp = area.large;
	new = (t_lpage*)mmap(0, sizeof(t_lpage*) + size, PROT_READ | PROT_WRITE, MAP_ANONYMOUS | MAP_PRIVATE, -1, 0);
	if (new == MAP_FAILED)
		return (0);
	new->size = size;
	new->addr = ((void*)new + sizeof(t_lpage));
	if (tmp)
	{
		while (tmp->next)
			tmp = tmp->next;
		new->prev = tmp;
		new->next = 0;
		tmp->next = new;
	}
	else
		tmp = new;
	area.nb_pages_L++;
	return (new->addr);
}

void		*ft_malloc(size_t size)
{
	t_page		*page;
	t_page		*prev;
	size_t		type;

	type = 0;
	page = 0;
	prev = 0;
	if (size < 1)
		return (0);
	size = (size + (8 - 1)) & -8; // align size to 8
	// Voir si la taille == (TINY_SIZE * getpagesize()) / 2
	if (size < (size_t)(TINY_SIZE * getpagesize()))
	{
		printf("Tiny malloc detected\n");
		page = area.tiny;
		type = TINY_SIZE;

	}
	else if (size < (size_t)(SMALL_SIZE * getpagesize()))
	{
		printf("Small malloc detected\n");
		page = area.small;
		type = TINY_SIZE;
	}
	else
	{
		printf("Large malloc detected\n");
		return (create_large_page(size));
	}
	if (page == 0)
		return (create_new_page(page, size, type)); // Pas encore de page
	while (page)
	{
		if (page->max_free >= size)
			return (assign_alloc(page, size, type)); // Trouvé de la place dans un chunk
		prev = page;
		page = page->next;
	}
	return (create_new_page(prev, size, type)); // Pas de place dans les chunks -> creation d'une nouvelle page.
}
