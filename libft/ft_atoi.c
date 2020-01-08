/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pierremore <pierremore@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/22 19:22:47 by pierremore        #+#    #+#             */
/*   Updated: 2016/01/25 12:32:12 by pierremore       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			ft_atoi(const char *str)
{
	int		i;
	int		n;
	int		ret;

	i = 0;
	n = 0;
	ret = -1;
	while (str[i] == ' ' || str[i] == '\n' || str[i] == '\r' || str[i] == '\v'
				|| str[i] == '\f' || str[i] == '\t')
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			ret = -ret;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
		n = n * 10 - (str[i++] - '0');
	return (n * ret);
}
