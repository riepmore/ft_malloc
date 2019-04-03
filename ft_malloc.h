#ifndef FT_MALLOC_H
# define FT_MALLOC_H

// Size of "pages" in bytes
// LARGE have no limits !
#define	n_SIZE		500		// max of tiny
#define	N_SIZE		1		// x getpagesize()
#define	m_SIZE		2000	// max of small
#define	M_SIZE		2		// x getpagesize()

#include <sys/mman.h>
#include <unistd.h>

// TO DEL
#include <stdio.h>
#include <string.h>

typedef struct	s_tinychk
{
	int					size;
	short				isfree;
	struct s_tinychk	*next;
}				t_tinychk;

typedef struct	s_smallchk
{
	int					size;
	short				isfree;
	struct s_smallchk	*next;
}				t_smallchk;

typedef struct	s_largechk
{
	int					size;
	short				isfree;
	struct s_largechk	*next;
}				t_largechk;

typedef struct s_chunks
{
	struct s_tinychk	*tiny;
	struct s_smallchk	*small;
	struct s_largechk	*large;
}				t_chunks;

void		*ft_malloc(size_t size);

#endif