/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pierremore <pierremore@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/28 15:41:47 by pierremore        #+#    #+#             */
/*   Updated: 2016/01/28 16:36:47 by pierremore       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void		ft_lstdelone(t_list **alst, void (*del)(void *, size_t))
{
	t_list		*temp;

	if (alst == NULL || *alst == NULL || del == NULL)
		return ;
	temp = *alst;
	del(temp->content, temp->content_size);
	free(temp);
	*alst = NULL;
}
