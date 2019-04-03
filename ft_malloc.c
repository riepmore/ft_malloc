#include "ft_malloc.h"
#include <stdlib.h>

void *global_chunks = 0;

int			cut_tinychunk(t_tinychk *chunk)
{
	t_tinychk	*first;
	t_tinychk	*tmp;
	int			i;

	if (chunk == 0)
		return (-1);
	first = chunk;
	i = 0;
	while (i < 4)
	{
		// printf("%p\n", chunk);
		// printf("%p\n", chunk + (chunk->size / 2));
		// exit(1);
		printf("%d\n", chunk + (chunk->size / 2));

		tmp = chunk + (chunk->size / 2);

		chunk->next = chunk + (chunk->size / 2);
		chunk = chunk->next;
		chunk->size = chunk->size / 2;
		exit(1);
		i++;
	}
	printf("bg\n");
	chunk = 0;
	chunk = first;
	return (0);
}

int			cut_smallchunk(t_smallchk *chunk)
{
	t_smallchk	*tmp;
	int			i;

	if (chunk == 0)
		return (-1);
	tmp = chunk;
	i = 0;
	while (i < 4)
	{
		chunk->next = chunk + (chunk->size / 2);
		chunk->size = chunk->size / 2;
		chunk = chunk->next;
		i++;
	}
	chunk = 0;
	chunk = tmp;
	return (0);
}

int			init_malloc()
{
	t_chunks	global;

	global_chunks = &global;
	global.tiny = 0;
	global.tiny = (t_tinychk*)mmap(0, sizeof(t_tinychk) + (getpagesize() * N_SIZE), PROT_READ | PROT_WRITE, MAP_ANONYMOUS | MAP_PRIVATE, -1, 0);
	if (global.tiny == 0)
		return (-1);
	global.tiny->size = getpagesize() * N_SIZE;
	global.tiny->isfree = 1;
	global.tiny->next = 0;
	global.small = (t_smallchk*)mmap(0, sizeof(t_tinychk) + (getpagesize() * M_SIZE), PROT_READ | PROT_WRITE, MAP_ANONYMOUS | MAP_PRIVATE, -1, 0);
	if (global.small == 0)
		return (-1);
	global.small->size = getpagesize() * M_SIZE;
	global.small->isfree = 1;
	global.small->next = 0;
	if (cut_tinychunk(global.tiny) == -1)
		return (-1);
	if (cut_smallchunk(global.small) == -1)
		return (-1);
	return (0);
}

void		*ft_malloc(size_t size)
{
	if (global_chunks == 0) //first call of malloc
	{
		if (init_malloc() == -1) // jcrois que j'initialise
		{
			printf("pas pu initialiser mon malloc mdr\n");
			return (0);
		}
	}
	printf("bon jfais koi avec %zu mtn\n", size);
	return (0);
}
