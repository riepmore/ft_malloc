/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmore <pmore@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/07 19:58:00 by pmore             #+#    #+#             */
/*   Updated: 2019/12/17 02:21:54 by pmore            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <sys/mman.h>
#include "ft_malloc.h"
#include "libft/libft.h"

int         main()
{
	void	*ptr0 = 0;
	void	*ptr1 = 0;
	// void	*ptr2 = 0;
	// void	*ptr3 = 0;
	// void	*ptr4 = 0;
	// void	*ptr5 = 0;
	// void	*ptr6 = 0;

	ptr0 = (char*)ft_malloc(10);
	ptr1 = (char*)ft_malloc(20);
	// ptr2 = (char*)ft_malloc(40);
	// ptr3 = (char*)ft_malloc(80);
	// ptr4 = (char*)ft_malloc(160);
	// ptr5 = (char*)ft_malloc(320);
	// ptr6 = (char*)ft_malloc(640);
	ptr0 = ft_strncpy((char*)ptr0, "AAAAAAAAAAAAAAAAAAA\0", 20);
	ptr1 = ft_strncpy((char*)ptr1, "BBBB\0", 5);
	printf("ouf\n");
	printf("RET: %s\n", (char*)ptr0);


	ft_free(ptr0);
	ft_free(ptr1);
	// ft_free(ptr2);
	// ft_free(ptr3);
	// ft_free(ptr4);
	// ft_free(ptr5);
	// ft_free(ptr6);

    return (0);
}
