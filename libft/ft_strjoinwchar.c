/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoinwchar.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pierremore <pierremore@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/09/30 20:48:37 by pierremore        #+#    #+#             */
/*   Updated: 2014/10/08 00:22:08 by pierremore       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char			*ft_strjoinwchar(char *s1, char c, char *s2)
{
	char		*str;

	if (s1 == NULL && s2 == NULL)
		return (ft_strdup(&c));
	else if (s1 == NULL)
		return (ft_strjoin(&c, s2));
	else if (s2 == NULL)
		return (ft_append(s1, c));
	str = ft_append(s1, c);
	return (ft_strjoin(str, s2));
}
