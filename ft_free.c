/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmore <pmore@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/12 23:08:57 by pmore             #+#    #+#             */
/*   Updated: 2019/12/16 20:44:53 by pmore            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_malloc.h"

// int			free_large(void *addr)
// {
// 	t_lpage		*ptr;
// 	t_lpage		*tmp;
//
// 	tmp = 0;
// 	ptr = area.large;
// 	if (ptr == 0)
// 		return (0);
// 	while (ptr->prev)
// 		ptr = ptr->prev;
// 	while (ptr->next)
// 	{
// 		if (ptr->addr == addr)
// 		{
// 			if (ptr->prev)
// 			{
// 				tmp = ptr->prev;
// 				tmp->next = ptr->next;
// 			}
// 			if (ptr->next)
// 			{
// 				tmp = ptr->next;
// 				tmp->prev = ptr->prev;
// 			}
// 			while (tmp && tmp->prev)
// 				tmp = tmp->prev;
// 			area.large = tmp;
// 			area.nb_pages_L--;
// 			munmap(ptr, sizeof(t_lpage*) + ptr->size);
// 			return (1);
// 		}
// 		ptr = ptr->next;
// 	}
// 	return (0);
// }


void		free_page(t_page *page, size_t type)
{
	t_page		*tmp;

	tmp = 0;
	// Supprime la page de la chaine
	if (page->prev)
	{
		tmp = page->prev;
		tmp->next = page->next;
	}
	if (page->next)
	{
		tmp = page->next;
		tmp->prev = page->prev;
	}
	// reviens au debut d la chaine pour l'assigner a la variable globale ? a test
	while (tmp && tmp->prev)
		tmp = tmp->prev;
	if (type == TINY_SIZE)
	{
		area.tiny = tmp;
		area.nb_pages_T--;
	}
	else if (type == SMALL_SIZE)
	{
		area.small = tmp;
		area.nb_pages_S--;
	}
	munmap(page->addr, page->total_size);
	area.cur_alloc -= page->total_size;
}

int			free_loop(t_page *page, void *addr, size_t type)
{
	t_chunk		*tmp;
	t_chunk		*prev;

	prev = 0;
	printf("wat\n");
	while (page)
	{
		printf("wat2\n");
		tmp = page->chunks;
		while (tmp)
		{
			printf("DEBUG: %p %p\n", tmp->addr, addr);
			if (tmp->addr == addr)
			{
				printf("I found the things to free\n");
				printf("Before:\n");
				print_pages(page);
				if (nb_chunks(page) == 1) // a test
				{
					printf("Dernier chunk donc je supprime la page, ballec\n");
					free_page(page, type);
				}
				else
				{
					printf("Pas le dernier chunk donc je clear ce chunk\n");
					ft_bzero(tmp->addr, tmp->size);
					page->left_free += tmp->size;
					if (prev)
						prev->next = tmp->next;
				}
				printf("\n\nAfter:\n");
				print_pages(page);
				return (1);
			}
			prev = tmp;
			tmp = tmp->next;
		}
		page = page->next;
	}
	return (0);
}

void		ft_free(void *addr)
{
	t_page		*page;

	if (addr == 0)
	{
		printf("On dirait que cette page n'existe plus\n");
		return ;
	}
	if (area.nb_pages_T > 0)
	{
		page = area.tiny;
		if (free_loop(page, addr, TINY_SIZE) == 1)
		{
			area.nb_pages_T--;
			return ;
		}
	}
	if (area.nb_pages_S > 0)
	{
		page = area.small;
		if (free_loop(page, addr, SMALL_SIZE) == 1)
		{
			area.nb_pages_S--;
			return ;
		}
	}
	if (area.nb_pages_L > 0)
	{
		printf("TODO / Free large\n");
		// if ((free_large(addr)) == 1)
		// {
		// 	area.nb_pages_L--;
		// 	return ;
		// }
	}
	printf("J'ai rien trouvé a free\n");
}
