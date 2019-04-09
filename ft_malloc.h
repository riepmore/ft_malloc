#ifndef FT_MALLOC_H
# define FT_MALLOC_H

// SIZE fois getpagesize()
# define TINY_SIZE	4
# define SMALL_SIZE	8
# define NB_BLOCK	8

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
	struct s_chunk 		*next;
}				t_chunk;

typedef struct	s_page
{
	size_t				free_size;
	struct s_chunk		chunk;
	struct s_page		*next;
}				t_page;

typedef struct 	s_area
{
	struct s_page	*small;
	struct s_page	*tiny;
	struct s_block	*large;
}				t_area;

void			*ft_malloc(size_t size);

#endif
