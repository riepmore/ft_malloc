/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pierremore <pierremore@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/22 19:22:47 by pierremore        #+#    #+#             */
/*   Updated: 2016/02/03 15:12:07 by pierremore       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strstr(const char *big, const char *little)
{
	int		i;
	int		j;
	int		temp;

	if (little[0] == '\0')
		return ((char *)big);
	i = -1;
	j = 0;
	while (big[++i])
	{
		if (big[i] == little[j])
		{
			temp = (i - 1);
			while (big[++temp] == little[j] && little[j] && big[temp])
				j++;
			if (little[j] == '\0')
				return ((char *)&big[i]);
			j = 0;
		}
	}
	return (NULL);
}
