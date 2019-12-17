/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmore <pmore@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/11 15:36:28 by pmore             #+#    #+#             */
/*   Updated: 2019/12/17 02:38:43 by pmore            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_malloc.h"

void		print_chunks(t_page *page)
{
	int		i;
	t_chunk	*tmp;

	i = 0;
	tmp = page->chunks;
	if (page == 0)
	{
		printf("Page doesn't exist\n");
		return ;
	}
	printf("Page free size:%zd\n", page->left_free);
	printf("///// CHUNKS \\\\\\\\\\\n" );
	while (tmp)
	{
		printf("/// CHUNK NUMBER %i \\\\\\\n", i);
		printf("Chunk size: %zd\n", tmp->size);
		printf("Chunk addr: %p\n", tmp->addr);
		tmp = tmp->next;
		i++;
	}
	printf("fini\n\n");
}

void		print_pages(t_page *pages)
{
	t_page		*tmp;
	int			i;

	i = 0;
	tmp = pages;
	if (tmp == 0)
		printf("\nY a pas de pages ici gro\n");
	else if (tmp->prev == 0 && tmp->next == 0)
	{
		printf("\nOn dirait que je suis la seule page\n");
		printf("ici %p %p\n", tmp->prev, tmp->next);
		printf("Page numero %i addr: %p\n", i, tmp->addr);
		printf("Page next_addr: %p\n", tmp->next_addr);
		printf("Page left_free: %zd\n", tmp->left_free);
		printf("Page total_size: %zd\n", tmp->total_size);
	}
	else if (tmp->prev == 0)
	{
		printf("\nJe suis la première page !\n");
		while (tmp)
		{
			if (i > 0)
				printf("---------------\n");
			printf("Page numero %i addr: %p\n", i, tmp->addr);
			printf("Page next_addr: %p\n", tmp->next_addr);
			printf("Page left_free: %zd\n", tmp->left_free);
			printf("Page total_size: %zd\n", tmp->total_size);
			i++;
			tmp = tmp->next;
		}
	}
	else if (tmp->next == 0)
	{
		printf("\nJe suis la dernière page !\n");
		while (tmp)
		{
			if (i < 0)
				printf("---------------\n");
			printf("Page numero %i addr: %p\n", i, tmp->addr);
			printf("Page next_addr: %p\n", tmp->next_addr);
			printf("Page left_free: %zd\n", tmp->left_free);
			printf("Page total_size: %zd\n", tmp->total_size);
			i--;
			tmp = tmp->prev;
		}
	}
	else
	{
		printf("\nBon ben le ptr est au milieu, je reviens en arriere et j'affiche.\n");
		while (tmp->prev)
			tmp = tmp->prev;
		while (tmp)
		{
			if (i > 0)
				printf("---------------\n");
			printf("Page numero %i addr: %p\n", i, tmp->addr);
			printf("Page next_addr: %p\n", tmp->next_addr);
			printf("Page left_free: %zd\n", tmp->left_free);
			printf("Page total_size: %zd\n", tmp->total_size);
			i++;
			tmp = tmp->next;
		}
	}
	printf("Affichage de pages finie !\n\n");
}
