/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_malloc.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmore <pmore@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/11 15:37:04 by pmore             #+#    #+#             */
/*   Updated: 2019/12/16 21:02:17 by pmore            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_MALLOC_H
# define FT_MALLOC_H

// SIZE fois getpagesize()
# define TINY_SIZE		2
# define SMALL_SIZE		4
# define LARGE_SIZE 	0
# define TRUE			0
# define FALSE			1
// for binary

// # define BIN_MAXSIZE	0xFFFFFFFF
// # define BIN_MINSIZE	0x00000000
// # define BIN_USED		0x01
// # define BIN_FREE		0x00

// HEADER EXAMPLE:
// |       1ST CHUNK      ||    2ND CHUNK          ||  ETC
// [AF 14 78 A5 CD D7 E0 00 00 45 95 C4 5F 71 10 FF]

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
	void 				*addr;
	struct s_chunk 		*next;
}				t_chunk;

typedef struct	s_page
{
	size_t				total_size; 	// taille totale (FREE et NON-FREE)
	size_t				left_free; 		// total de memoire libre
	void				*addr;			// l'addresse mémwar
	void				*next_addr;		// ptr vers l'addr mémw dispo
	struct s_chunk		*chunks;
	struct s_page		*next;
	struct s_page		*prev;
}				t_page;

typedef struct	s_lpage 				// PAS ENCORE TOUCHÉ
{
	struct s_lpage		*next;
	struct s_lpage		*prev;
	size_t				size; 			// taille totale
	void				*addr;			// l'addresse mémwar
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
void			ft_free(void *addr);

// DEBUG
void			print_chunks(t_page *page);
void			print_pages(t_page *pages);

// UTILITIES
void		assign_alloc(t_page *new, size_t type);
int			nb_chunks(t_page *page);

#endif
