#include "ft_malloc.h"
#include <stdlib.h>

struct s_area 	area = {0};

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
	(void)size;
	printf("bon, j'ai creer un truc....\n");
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
