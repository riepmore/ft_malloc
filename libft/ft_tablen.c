/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tablen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pierremore <pierremore@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/02 17:09:47 by pierremore        #+#    #+#             */
/*   Updated: 2014/12/02 17:13:46 by pierremore       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			ft_tablen(char **tab)
{
	int			i;

	if (tab == NULL)
		return (-1);
	i = 0;
	while (tab[i])
		i++;
	return (i);
}
