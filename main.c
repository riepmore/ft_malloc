/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmore <pmore@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/07 19:58:00 by pmore             #+#    #+#             */
/*   Updated: 2019/04/17 13:13:11 by pmore            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <sys/mman.h>
#include "ft_malloc.h"
#include "libft/libft.h"

int         main()
{
	char	*str = 0;

	str = (char*)ft_malloc(10);
	// str = (char*)mmap(0, sizeof(char) + 10, PROT_READ | PROT_WRITE, MAP_ANONYMOUS | MAP_PRIVATE, -1, 0);
	if (str == 0)
		return (-1);
	str = ft_strncpy(str, "123456789\0", 10);
	// printf("%d\n", *str);
	// *str += ft_strlen(str) / 2;
	// printf("%d\n", *str);
	// printf("ret: %s\n", str);
	munmap(str, 10);
    return (0);
}
