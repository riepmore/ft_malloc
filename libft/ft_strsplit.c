/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pierremore <pierremore@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/25 18:01:18 by pierremore        #+#    #+#             */
/*   Updated: 2016/02/01 17:19:29 by pierremore       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static int			nb_words(char const *str, char c)
{
	int			i;
	int			len;

	len = 1;
	i = 0;
	if (str[0] == '\0')
		return (0);
	while (str[i] == c)
		i++;
	while (str[i])
	{
		if (str[i] == c)
		{
			len++;
			while (str[i] && str[i] == c)
				i++;
		}
		else
			i++;
	}
	if (str[i - 1] == c)
		len--;
	return (len);
}

static char			*take_word(char const *s, int len, int n, char c)
{
	char	*str;
	int		i;

	if ((str = malloc(sizeof(char) * len)) == NULL)
		return (NULL);
	i = 0;
	while (s[n] && s[n] != c)
	{
		str[i] = s[n];
		i++;
		n++;
	}
	str[i] = '\0';
	return (str);
}

static char			*drop_words(char const *s, int n, char c)
{
	int			i;
	int			len;

	i = 0;
	len = 0;
	while (s[i] == c)
		i++;
	while (len < n)
	{
		while (s[i] && s[i] != c)
			i++;
		while (s[i] && s[i] == c)
			i++;
		len++;
	}
	len = i;
	while (s[len] && s[len] != c)
		len++;
	return (take_word(s, ((len - i) + 1), i, c));
}

char				**ft_strsplit(char const *s, char c)
{
	char		**tab;
	int			words;
	int			i;

	if (s == NULL)
		return (NULL);
	words = nb_words(s, c);
	if ((tab = malloc((sizeof(char *) * words) + 1)) == NULL)
		return (NULL);
	i = -1;
	while (++i < words)
		tab[i] = drop_words(s, i, c);
	tab[i] = NULL;
	return (tab);
}
