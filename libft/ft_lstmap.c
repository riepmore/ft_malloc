/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pierremore <pierremore@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/28 15:41:47 by pierremore        #+#    #+#             */
/*   Updated: 2016/03/09 15:22:59 by pierremore       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*ret;
	t_list	*tmp;
	t_list	*new;

	ret = NULL;
	if (lst != NULL)
	{
		ret = ft_lstnew(lst->content, lst->content_size);
		if (ret == NULL)
			return (NULL);
		ret = f(ret);
		tmp = ret;
		lst = lst->next;
	}
	while (lst != NULL)
	{
		new = ft_lstnew(lst->content, lst->content_size);
		if (new == NULL)
			return (NULL);
		new = f(new);
		tmp->next = new;
		lst = lst->next;
	}
	return (ret);
}
