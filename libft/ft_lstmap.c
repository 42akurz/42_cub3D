/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fharing <fharing@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/22 14:36:58 by fharing           #+#    #+#             */
/*   Updated: 2021/06/22 17:13:43 by fharing          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new;
	t_list	*element;

	new = 0;
	while (lst != NULL)
	{
		element = ft_lstnew(f(lst));
		if (element == 0)
			del(element);
		else
			ft_lstadd_back(&new, element);
		lst = lst->next;
	}
	return (new);
}
