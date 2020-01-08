/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pierremore <pierremore@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/22 19:22:47 by pierremore        #+#    #+#             */
/*   Updated: 2016/03/09 15:17:41 by pierremore       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	litlen;
	int		ret;

	if (little[0] == '\0')
		return ((char*)big);
	litlen = ft_strlen(little);
	ret = 1;
	while (litlen <= len && *big != '\0'
		&& (ret = ft_strncmp(big, little, litlen)))
	{
		len--;
		big++;
	}
	if (ret != 0)
		return (NULL);
	else
		return ((char *)big);
}
