/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pierremore <pierremore@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/25 18:01:18 by pierremore        #+#    #+#             */
/*   Updated: 2016/01/26 15:19:39 by pierremore       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char		*ft_strtrim(char const *s)
{
	char		*str;
	int			deb;
	int			fin;
	int			i;

	if (s == NULL)
		return (NULL);
	fin = ft_strlen(s) - 1;
	deb = 0;
	while (s[deb] && (s[deb] == ' ' || s[deb] == '\n' || s[deb] == '\t'))
		deb++;
	if (s[deb] == '\0')
		return ("\0");
	while (fin > 0 && (s[fin] == ' ' || s[fin] == '\n' || s[fin] == '\t'))
		fin--;
	if ((str = malloc(sizeof(char) * (fin - deb) + 2)) == NULL)
		return (NULL);
	i = -1;
	while (deb < (fin + 2))
	{
		str[++i] = s[deb];
		deb++;
	}
	str[i] = '\0';
	return (str);
}
