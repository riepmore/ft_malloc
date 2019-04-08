/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_append.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmore <pmore@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/22 06:08:05 by pmore             #+#    #+#             */
/*   Updated: 2014/01/22 06:08:22 by pmore            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char		*ft_append(char *s, char c)
{
	int		i;
	char	*temp;

	i = 0;
	temp = (char *)malloc(sizeof(char*) * ft_strlen(s) + 1);
	while (*s)
	{
		temp[i] = *(s);
		i++;
		s++;
	}
	temp[i] = c;
	temp[i + 1] = '\0';
	return (temp);
}
