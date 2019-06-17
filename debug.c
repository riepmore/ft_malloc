/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmore <pmore@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/11 15:36:28 by pmore             #+#    #+#             */
/*   Updated: 2019/06/15 14:52:27 by pmore            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_malloc.h"

void		print_chunks(t_page *page)
{
	int		i = 0;

	if (page == 0)
	{
		printf("Page is voideded\n");
		return ;
	}
	printf("Page free size:%zd\n", page->total_free);
	printf("///// CHUNKS \\\\\\\\\\\n" );
	while (i < NB_CHUNKS)
	{
		printf("/// CHUNK NUMBER %i \\\\\\\n", i);
		printf("Chunk size: %zd\n", page->chunks[i].size);
		if (page->chunks[i].isfree == TRUE)
			printf("This chunk is free\n");
		else
			printf("This chunk is NOT free\n");
		printf("Chunk addr: %p\n", page->chunks[i].addr);
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
		printf("Page numero %i addr: %p\n", i, tmp);
		printf("Page total_free: %zd\n", tmp->total_free);
		printf("Page max_free: %zd\n", tmp->max_free);
		printf("Page total_size: %zd\n", tmp->total_size);
	}
	else if (tmp->prev == 0)
	{
		printf("\nJe suis la première page !\n");
		while (tmp)
		{
			if (i > 0)
				printf("---------------\n");
			printf("Page numero %i addr: %p\n", i, tmp);
			printf("Page total_free: %zd\n", tmp->total_free);
			printf("Page max_free: %zd\n", tmp->max_free);
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
			printf("Page numero %i addr: %p\n", i, tmp);
			printf("Page total_free: %zd\n", tmp->total_free);
			printf("Page max_free: %zd\n", tmp->max_free);
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
			printf("Page numero %i addr: %p\n", i, tmp);
			printf("Page total_free: %zd\n", tmp->total_free);
			printf("Page max_free: %zd\n", tmp->max_free);
			printf("Page total_size: %zd\n", tmp->total_size);
			i++;
			tmp = tmp->next;
		}
	}
	printf("Affichage de pages finie !\n\n");
}
