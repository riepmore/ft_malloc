#include "ft_malloc.h"
#include <stdlib.h>

struct s_area 	 area; // zeroed ?

t_chunk		*create_new_chunk(size_t type)
{
	t_chunk		*new;
	t_chunk		*tmp;
	int			size;
	int			i;

	i = 0;
	size = type * getpagesize();
	new = (t_chunk*)mmap(0, sizeof(t_chunk) + size, PROT_READ | PROT_WRITE, MAP_ANONYMOUS | MAP_PRIVATE, -1, 0);
	tmp = new;
	if (new == 0)
		return (0);
	while (i < NB_CHUNKS)
	{
		size /= 2;
		new->size = size;
		new->addr = (size_t)(&new) + sizeof(t_chunk);
		new->isfree = TRUE;
		// new->next = *new + size; // aïe
		new = new->next;
		i++;
		printf("%d tour de boucle\n", i);
		printf("addr: %zu\n", new->addr);
		printf("new      : %zd\nnew->next: %zd\n", &new, &new->next);
		munmap(tmp, size);
		exit(1);
	}
	printf("fiou\n");
	return (tmp);
}

int			create_new_page(t_page *page, size_t size, size_t type)
{
	t_page		new;

	printf("Créeons une page...\n");
	if (page != 0)
	{
		printf("Je vais chercher ma derniere page car je ne suis pas vide.\n");
		while (page->next != 0)
			page = page->next;
		page->next = &new;
	}
	new.free_size = (size_t)(getpagesize() * type) / 2;
	new.next = 0;
	printf("bon, j'ai creer un truc....\n");
	if ((new.chunk = create_new_chunk(TINY_SIZE)) == 0)
		return (-1);
	(void)size;
	return (0);
}

void		*ft_malloc(size_t size)
{
	t_page		*page;

	page = 0;
	if (size < 1)
		return (0);
	// Voir si la taille == (TINY_SIZE * getpagesize()) / 2
	if (size < (size_t)((TINY_SIZE * getpagesize()) / 2))
	{
		printf("Tiny malloc detected\n");
		page = area.tiny;
		while (page)
		{
			page = page->next;
			if (page->free_size >= size)
			{
				printf("J'ai trouvé un emplacement mémwar !\n");
				exit(1);
			}
		}
		// page = last_page(area.tiny);
		if (create_new_page(page, size, TINY_SIZE) == -1)
			return (0);
	}
	else if (size < (size_t)((SMALL_SIZE * getpagesize()) / 2))
	{
		printf("Small malloc detected\n");
	}
	else
	{
		printf("Large malloc detected\n");
	}
	return (0);
}
