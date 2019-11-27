/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_malloc.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmore <pmore@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/11 15:37:04 by pmore             #+#    #+#             */
/*   Updated: 2019/11/27 11:37:12 by pmore            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_MALLOC_H
# define FT_MALLOC_H

// SIZE fois getpagesize()
# define TINY_SIZE	2
# define SMALL_SIZE	4
# define LARGE_SIZE 0
# define NB_CHUNKS	5
# define TRUE		0
# define FALSE		1
// for binary
# BIN_MAXSIZE		0xFFFF
# BIN_MINSIZE		0x0000
# BIN_USED			0x01
# BIN_FREE			0x00

# include <sys/mman.h>
# include <sys/resource.h>
# include <unistd.h>
# include "libft/libft.h"

// TO DEL
# include <stdio.h>
# include <string.h>

// Structs
typedef struct	s_chunk
{
	size_t				size;
	short				isfree;
	void 				*addr;
	// struct s_chunk 		*next; // ca sert a R
}				t_chunk;

typedef struct	s_page
{
	size_t				total_free; // total de memoire libre
	struct s_chunk		chunks[NB_CHUNKS];
	struct s_page		*next;
	struct s_page		*prev;
	size_t				total_size; // taille totale (FREE et NON-FREE)
	void				*addr;		// l'addresse mémwar
}				t_page;

typedef struct	s_lpage
{
	struct s_lpage		*next;
	struct s_lpage		*prev;
	size_t				size; 		// taille totale
	void				*addr;		// l'addresse mémwar
}				t_lpage;

typedef struct 	s_area
{
	rlim_t			rlim;
	rlim_t			cur_alloc;
	size_t			nb_pages_T;
	size_t			nb_pages_S;
	size_t			nb_pages_L;
	struct s_page	*tiny;
	struct s_page	*small;
	struct s_lpage	*large;
}				t_area;

struct s_area 	 area; // zeroed ?

// MAIN FUNCTIONS
void			*ft_malloc(size_t size);
void			*assign_alloc(t_page *page, size_t size, size_t type);
void			ft_free(void *addr);

// DEBUG
void			print_chunks(t_page *page);
void			print_pages(t_page *pages);

// UTILITIES
void		increment_page_number(size_t type);
int			is_last_chunk(t_page *page);

#endif
