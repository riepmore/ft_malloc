/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmore <pmore@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/07 19:58:00 by pmore             #+#    #+#             */
/*   Updated: 2019/04/08 14:34:49 by pmore            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "libft/libft.h"
#include <sys/mman.h>

int         main()
{
	char	*str = 0;
	void	*addr = 0;

	printf("addr: %d\n", 1 << 11);
	// addr = addr | 0x42424242;

	// str = (char*)mmap(0, sizeof(char) + 10, PROT_READ | PROT_WRITE, MAP_ANONYMOUS | MAP_PRIVATE, -1, 0);
	// ft_strncpy(str, "123456789\0", 10);
	// addr = &str;
	// printf("str: %s\n", str);
	// printf("addr: %p\n", addr);
	// printf("addr str? : %s\n", (char*)addr);
    return (0);
}
