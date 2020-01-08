/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pierremore <pierremore@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/28 15:41:47 by pierremore        #+#    #+#             */
/*   Updated: 2016/01/28 16:47:25 by pierremore       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void		ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list		*temp;
	t_list		*temp2;

	if (alst == NULL || *alst == NULL || del == NULL)
		return ;
	temp = *alst;
	while (temp != NULL)
	{
		temp2 = temp;
		del(temp->content, temp->content_size);
		free(temp);
		temp = temp2->next;
	}
	*alst = NULL;
}
