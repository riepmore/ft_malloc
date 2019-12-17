/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_malloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmore <pmore@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/11 15:36:31 by pmore             #+#    #+#             */
/*   Updated: 2019/12/17 02:29:40 by pmore            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_malloc.h"
#include <stdlib.h>

void		*create_new_chunk(t_page *page, size_t size)
{
	t_chunk		new;
	t_chunk		*tmp;
	int			i;

	if (page->left_free < size) // should not happen, maybe to del
	{
		printf("Chunk creation error: not enough space in the page\n");
		return (0);
	}
	i = 0;
	new.size = size;
	new.addr = page->next_addr;
	page->left_free -= size;
	printf("next_addr: %p\n", (void*)page->next_addr);
	page->next_addr += size;
	printf("next_addr: %p\n", (void*)page->next_addr);
	if (page->chunks == 0)
		page->chunks = &new;
	else
	{
		tmp = page->chunks;
		while (tmp->next != 0)
			tmp = tmp->next;
		tmp->next = &new;
	}
	return (new.addr);
}

void		*create_new_page(t_page *page, size_t size, size_t type)
{
	t_page			new;
	size_t			page_size;
	struct rlimit 	rlp;

	getrlimit(RLIMIT_AS, &rlp);
	printf("RLIMIT_CUR: %li | RLIMIT_MAX: %li\n", (long)rlp.rlim_cur, (long)rlp.rlim_max);
	if ((long)(area.cur_alloc + size) >= (long)rlp.rlim_cur)
	{
		printf("ya pu de place rlimit truc\n");
		return (0);
	}
	page_size = type * getpagesize();
	new.addr = (void*)mmap(0, page_size, PROT_READ | PROT_WRITE, MAP_ANONYMOUS | MAP_PRIVATE, -1, 0);
	if (new.addr == MAP_FAILED)
	{
		printf("MMAP FAILED\n");
		return (0);
	}
	area.cur_alloc += size;
	new.total_size = page_size;
	new.left_free = page_size;
	new.next_addr = new.addr;
	new.prev = page;
	new.next = 0;
	if (page != 0)
		page->next = &new;
	else
		page = &new;
	assign_alloc(page, type);
	return (create_new_chunk(&new, size));
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
		type = SMALL_SIZE;
	}
	else
	{
		printf("Large malloc detected\n");
		printf("Will wait for this one, i skip.\n");
		return (0); // to del evidemment
		// return (create_large_page(size));
	}
	if (page == 0)
		return (create_new_page(0, size, type)); // Pas encore de page
	while (page)
	{
		if (page->left_free >= size)
		{
			print_pages(page);
			printf("@@@@@@@@@@@@\n");
			print_pages(page);
			printf("g trouve de la place dans une page\n");
			return (create_new_chunk(page, size)); // Trouvé de la place dans une page
		}
		prev = page;
		page = page->next;
	}
	return (create_new_page(prev, size, type)); // Pas de place dans les pages -> creation d'une nouvelle page.
}
