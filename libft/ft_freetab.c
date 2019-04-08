/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_freetab.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pierremore <pierremore@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/10 17:55:00 by pierremore        #+#    #+#             */
/*   Updated: 2016/03/10 17:57:35 by pierremore       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void		ft_freetab(char **tab)
{
	int		i;

	i = -1;
	while (tab[++i] != NULL)
		free(tab[i]);
	free(tab);
}
