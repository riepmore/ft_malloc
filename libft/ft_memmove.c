/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pierremore <pierremore@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/22 19:22:47 by pierremore        #+#    #+#             */
/*   Updated: 2016/01/22 23:14:16 by pierremore       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		*ft_memmove(void *dst, const void *src, size_t len)
{
	char		*dsttemp;
	char		*srctemp;

	dsttemp = (char *)dst;
	srctemp = (char *)src;
	while (len--)
	{
		if (src > dst)
			*dsttemp++ = *srctemp++;
		else
			*(dsttemp + len) = *(srctemp + len);
	}
	return (dst);
}
