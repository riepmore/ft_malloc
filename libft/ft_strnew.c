/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pierremore <pierremore@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/25 18:01:18 by pierremore        #+#    #+#             */
/*   Updated: 2016/02/01 17:25:11 by pierremore       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char		*ft_strnew(size_t size)
{
	char		*str;
	size_t		i;

	i = -1;
	if ((str = malloc((sizeof(char) * size) + 1)) == NULL)
		return (NULL);
	while (++i < (size + 1))
		str[i] = '\0';
	return (str);
}
