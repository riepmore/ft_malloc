#ifndef FT_MALLOC_H
# define FT_MALLOC_H

// SIZE fois getpagesize()
# define TINY_SIZE	2
# define SMALL_SIZE	4

// # define NB_CHUNKS	3

#define TRUE		0
#define FALSE		1

# include <sys/mman.h>
# include <unistd.h>

// TO DEL
# include <stdio.h>
# include <string.h>

// Structs
typedef struct	s_chunk
{
	size_t				size;
	short				isfree;
	void 				*addr;
	struct s_chunk 		*next;
}				t_chunk;

typedef struct	s_page
{
	size_t				free_size;
	struct s_chunk		*chunk;
	struct s_page		*next;
}				t_page;

typedef struct 	s_area
{
	size_t			nb_pages_T;
	size_t			nb_pages_S;
	size_t			nb_pages_L;
	struct s_page	*tiny;
	struct s_page	*small;
	struct s_block	*large;
}				t_area;

void			*ft_malloc(size_t size);

#endif
