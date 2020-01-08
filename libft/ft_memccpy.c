/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pierremore <pierremore@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/22 19:22:47 by pierremore        #+#    #+#             */
/*   Updated: 2016/03/02 16:44:16 by pierremore       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	char			*srctemp;
	char			*dsttemp;

	srctemp = (char *)src;
	dsttemp = (char *)dst;
	while (n--)
	{
		*dsttemp++ = *srctemp++;
		if (*(dsttemp - 1) == c)
			return (dsttemp);
	}
	return (NULL);
}
