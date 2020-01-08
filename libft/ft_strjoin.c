/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pierremore <pierremore@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/25 18:01:18 by pierremore        #+#    #+#             */
/*   Updated: 2016/01/25 23:24:33 by pierremore       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char		*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	int		len;
	char	*str;

	if (s1 == NULL && s2 != NULL)
		return (ft_strdup(s2));
	if (s1 != NULL && s2 == NULL)
		return (ft_strdup(s1));
	if (s1 == NULL || s2 == NULL)
		return (NULL);
	len = ft_strlen(s1) + ft_strlen(s2);
	if ((str = malloc((sizeof(char) * len) + 1)) == NULL)
		return (NULL);
	i = -1;
	len = -1;
	while (s1[++i])
		str[i] = s1[i];
	while (s2[++len])
		str[i++] = s2[len];
	str[i] = '\0';
	return (str);
}
